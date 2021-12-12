#include <iostream>
#include <typeinfo>

int main(void) {

  void** arr = new void*[2];
  int i = 6;
  float f = 1.4f;
  arr[0] = &i;
  arr[1] = &f;

  std::cout << "In a void pointer array of size 2 I have stored an int and a float. According to the compiler the types of each as they are stored in the array are " << typeid(arr[0]).name() << " and " << typeid(arr[1]).name() << ". This tells us that we cannot automatically cast them back to their previous types, because their types have changed to void* in order to be stored inside the void array. With this said we can still get them back to an int and float if we, the programmer, know which was an int and which was a float. Example being: We know the int was stored before the float so we can cast accordingly to get " << *(int*)arr[0] << " and " << *(float*)arr[1] << std::endl;
  
	return 0;
}
