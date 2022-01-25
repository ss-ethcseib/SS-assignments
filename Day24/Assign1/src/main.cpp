#include <iostream>
#include <thread>
#include "Queue.h"
#include <future>

bool try1(threadsafe_queue<int>& queue, int& val){
  return queue.try_pop(val);
}

std::shared_ptr<int> try2(threadsafe_queue<int>& queue){
  return queue.try_pop();
}

bool ret(){return true;}
int main(){

  int val = -1;
  threadsafe_queue<int> queue;
  std::future<bool> as1;
  std::future<std::shared_ptr<int>> as2;
  
  for(int i = 0; i < 16; i++){
    queue.push(i);
  }

  for(int i = 0; i < 18; i++){
    
    as1 = std::async(try1, std::ref(queue), std::ref(val));
    as2 = std::async(try2, std::ref(queue));

    bool check = as1.get();
    std::shared_ptr<int> ptr = as2.get();
    if(ptr != nullptr && val == *ptr){
      std::cerr << "\nERR: Race Condition\n";
      return -1;
    }

    if(check)
      std::cout << "val 1 should be " << i << "\n\tval: " << val;
    else
      std::cout << "Queue empty";
    
    if(ptr == nullptr)
      std::cout << "\nQueue empty\n";
      else
	std::cout << "\nval 2 should be " << ++i << "\n\tval: " << *ptr << std::endl << std::endl;
  }
  
  return 0;
}
