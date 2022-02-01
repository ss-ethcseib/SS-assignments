#include <thread>
#include <cassert>
#include <atomic>

std::atomic<bool> x, y;
std::atomic<int> z;
struct Data{
  int x;
};
  
auto val = std::memory_order_seq_cst;
auto val2 = std::memory_order_release;
std::atomic<struct Data*> data;
void createData(){
  Data* d = new Data;
  d->x = 2;

  data.store(d, std::memory_order_release);
}

void useData(){
  struct Data* d;
  while(!(d = data.load(std::memory_order_consume)));
  assert(d->x == 2);
  delete d;
}

void write_x(){
  x.store(true, val);
}

void write_y(){
  y.store(true, val);
}

void write_x_then_y(){
  x.store(true, val);
  y.store(true, val2);
}

void read_y_write_z(){
  sleep(1000);
  write_y();
  z.store(-2);
}

void read_x_write_z(){
  write_x();
  z.store(-1);
}

void read_x_then_y(){
  while(!x.load(val));
  if(y.load(val))
    z++;
}

void read_y_then_x(){
  while(!y.load(val));
  if(x.load(val))
    z++;
}

int main(){
  
  for(int ii = 0; ii < 4; ii++){
    if(ii == 1)
      val = std::memory_order_relaxed;
    else if(ii == 2){
      val = std::memory_order_relaxed;
      val2 = std::memory_order_release;
    }
    
    for(int i = 0; i < 100000; i++){
      
      if(ii == 0){
	std::thread t1(write_x), t2(write_y), t3(read_x_then_y), t4(read_y_then_x);
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	
	assert(z.load() == 2);
	z.store(0, val);
      }
      
      else if(ii == 1){
	
	//thread 1 waits one second so thread 2 can write to z. Then z
	//gets overwritten by thread 1 showing a different access order.
	
	std::thread t1(read_y_write_z), t2(read_x_write_z);
	
	t1.join();
	t2.join();
	
	assert(z == -2);
      }
      else if(ii == 2){
	//this shows release acquire synchronization because
	//when the read happens it has to wait on y before x
	//can be read. Since x gets stored in the same thread
	//as y and x happens first when the read of y happens
	//x can also be read and will have the expected outcome.
	std::thread t1(write_x_then_y), t2(read_y_then_x);

	t1.join();
	t2.join();
      }
      else if(ii == 3){
	std::thread t1(createData), t2(useData);

	t1.join();
	t2.join();
      }
    }
  }
  
  
  return 0;
}
