#include <cassert>
#include <thread>
#include <future>
#include <vector>
#include <functional>

template<class T, class X>
void none_of(T beg, T end, std::function<bool(X)>& pred,
	    std::promise<X>& result,
	    std::atomic<bool>& done_flag){

  try{
    for(; beg != end && done_flag.load() != false; beg++){
      if(pred(*beg)){
	result.set_value(*beg);
	done_flag.store(false);

	return;
      }
    }
  }
  catch(...){
    try{
      result.set_exception(std::current_exception());
      done_flag.store(true);
    }
    catch(...){

    }
  }
}

int main(){
  std::vector<int> vec;
  std::promise<int> result;
  std::atomic<bool> done_flag = true;

  for(int i = 0; i < 15; i++){
    vec.push_back(15 - i);
  }
  
  std::function<bool(int)> pred =
    [](int val) noexcept(true) -> bool {
      
      return val == 1;
    };

  std::future<void> future1 = std::async(none_of<std::vector<int>::iterator, int>, vec.begin(), vec.begin() + ((vec.end() - vec.begin()) / 2), std::ref(pred), std::ref(result), std::ref(done_flag));

  std::future<void> future2 = std::async(none_of<std::vector<int>::iterator, int>, vec.begin() + (vec.end() - vec.begin()) / 2 + 1, vec.end(), std::ref(pred), std::ref(result), std::ref(done_flag));

  
  assert(result.get_future().get() == 1);
  assert(done_flag.load() == false);
  
  return 0;
}
