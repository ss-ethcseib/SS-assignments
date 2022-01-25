#pragma once

#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

template<class T>
class threadsafe_queue {

private:
  std::mutex mut;
  std::queue<T> data_queue;
  std::condition_variable data_cond;

public:

  bool empty(){
    if(data_queue.empty())
      return true;
    return false;
  }
  
  void push(T new_value) {
    std::lock_guard<std::mutex> lk(mut);

    data_queue.push(new_value);
    data_cond.notify_one();
  }
  
  void wait_and_pop(T& value) {
    std::unique_lock<std::mutex> lk(mut);

    data_cond.wait(lk,[this]{return !data_queue.empty();});
    value = data_queue.front();
    data_queue.pop();
  }

  bool try_pop(T& value) {
    std::lock_guard<std::mutex> lk(mut);

    if (data_queue.empty())
      return false;

    value = data_queue.front();
    data_queue.pop();

    return true;
  } 

  std::shared_ptr<T> try_pop() {
    std::lock_guard<std::mutex> lk(mut);

    if (data_queue.empty())
      return std::shared_ptr<T>();

    std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
    data_queue.pop();

    return res;
  }
};
