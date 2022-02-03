#include "Thread_Pool.h"
#include <functional>
#include <future>
#include "Thread_Safe_Queue.h"
#include <vector>
#include <type_traits>
#include <numeric>
#include <cassert>

template<class Iterator, class T>
struct accumulate_block{
  void operator()(Iterator first, Iterator last, std::promise<T>& result){
    result.set_value(std::accumulate(first, last, 0));
  }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {

  unsigned long const length = std::distance(first, last);

  if (!length)
    return init;

  unsigned long const block_size = 25;
  unsigned long const num_blocks = (length + block_size-1)/block_size;
  std::vector<std::future<T>> futures(num_blocks-1);
  
  thread_pool pool;
  Iterator block_start = first;
  
  for (unsigned long i = 0; i < (num_blocks-1); i++) {
    Iterator block_end = block_start;
    
    std::advance(block_end, block_size);

    std::promise<T> pr;
    futures[i] = pr.get_future();
    pool.submit([&] {
		  accumulate_block<Iterator,T>()(block_start, block_end, pr);
		});
    block_start = block_end;
  }
  std::promise<T> pr;
  
  accumulate_block<Iterator,T>() (block_start,last, pr);
  
  T last_result = pr.get_future().get();
  T result = init;
  for (unsigned long i = 0; i < (num_blocks-1); ++i) {
    result += futures[i].get();
  }
  result += last_result;
  return result;
}

int main(){
  std::vector<int> vec;
  for(int i = 0; i < 3; i++)
    vec.push_back(i);
  int val = parallel_accumulate<std::vector<int>::iterator, int>(vec.begin(), vec.end(), 0);
  
  assert(3 == val);
  return 0;
}
