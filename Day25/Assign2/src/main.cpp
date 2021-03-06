#include <iostream>
#include <vector>
#include <future>
#include <numeric>
#include <cassert>

template<class T>
void accumulate(std::vector<T>& vec, std::promise<T>& pr){
  
  pr.set_value(std::accumulate(vec.begin(), vec.end(), 0));
}

int main(){
  std::promise<int> pr;
  std::future<int> fut = pr.get_future();

  std::vector<int> vec = {0, 1, 2, 3, 4, 5};
  
  std::future<void> discard = std::async(accumulate<int>, std::ref(vec), std::ref(pr));

  assert(std::accumulate(vec.begin(), vec.end(), 0) == fut.get());

  discard.get();
  return 0;
}
