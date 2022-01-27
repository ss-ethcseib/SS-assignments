#include <cassert>
#include <thread>
#include <future>
#include <vector>
#include <functional>

template<class T, class X>
void any_of(T beg, T end, std::function<bool(X)>& pred, std::promise<X>& result,
	    std::atomic<bool>& done_flag){

  try{
    for(; beg != end && done_flag.load() != true; beg++){
      if(pred(*beg)){
	result.set_value(*beg);
	done_flag.store(true);

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
  std::atomic<bool> done_flag = false;

  for(int i = 0; i < 15; i++){
    vec.push_back(i);
  }
  
  std::function<bool(int)> pred =
    [](int val) noexcept(true) -> bool{
      return val < 5;
    };
  
  std::thread t1(any_of<std::vector<int>::iterator, int>, vec.begin(),
		 vec.begin() + ((vec.end() - vec.begin()) / 2), std::ref(pred), std::ref(result), std::ref(done_flag));

  std::thread t2(any_of<std::vector<int>::iterator, int>, vec.begin() + ((vec.end() - vec.begin()) / 2) + 1, vec.end(),
		 std::ref(pred), std::ref(result), std::ref(done_flag));
  
  t1.join();
  t2.join();
  
  assert(done_flag.load() == true);
  assert(result.get_future().get() < 5);
 
  return 0;
}
