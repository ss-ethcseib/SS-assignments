#include "MyString.h"

void MyString::strcpy(const char& src){
  strcpy(&src);
}

void MyString::strcpy(const char* src){

  if(src == nullptr)
    return;
  
  int i = 0;
  for(; src[i] != '\0'; i++);

  if(c_str != nullptr)
    delete[] c_str;

  c_str = new char[i];

  for(i = 0; src[i] != '\0'; i++){
    c_str[i] = src[i];
  }
  c_str[i] = src[i];
}

MyString& MyString::operator+(MyString& str){

  int size1 = 0;
  for(; this->c_str[size1] != '\0'; size1++);
  
  int size2 = 0;
  for(; str.c_str[size2] != '\0'; size2++);
  
  char* newC_str = new char[size1 + size2 - 1];
  
  for(int i = 0; i < size1; i++){
    
    newC_str[i] = this->c_str[i];
  }
  
  int x = size1;
  for(int i = 0; i < size2 + 1; i++){
    
    newC_str[x] = str.c_str[i];                                             
    x++;
  }
  
  return *this;
}

MyString& MyString::operator*(int amt){

  int size = 0;
  for(; this->c_str[size] != '\0'; size++);

  char* newC_str = new char[size * (amt + 1)];

  int i = 0;
  for(; i < size * (amt + 1); i++){
    
      newC_str[i] = this->c_str[i % size];
  }
  newC_str[i] = '\0';

  if(this->c_str != nullptr)
    delete[] this->c_str;

  this->c_str = newC_str;

  return *this;
}

char MyString::operator[](int index){
  return this->c_str[index];
}

void MyString::operator=(const char& str){

  strcpy(str);
}

void MyString::operator=(MyString&& str){

  if(this == &str)
    return;
  
  if(this->c_str != nullptr)
    delete[] this->c_str;

  c_str = str.c_str;

  str.c_str = nullptr;
}

bool MyString::operator==(MyString& str){

  if(this == &str)
    return true;
 
  if(this->c_str == nullptr && str.c_str == nullptr)
    return true;
  else if(this->c_str == nullptr && str.c_str != nullptr)
    return false;
  else if(this->c_str != nullptr && str.c_str == nullptr)
    return false;

  int size1 = 0;
  for(; this->c_str[size1] != '\0'; size1++);
  
  int size2 = 0;
  for(; str.c_str[size2] != '\0'; size2++);
  
  if(size1 != size2)
    return false;
  
  int i = 0;
  for(; i < size1 + 1 && this->c_str[i] == str.c_str[i]; i++);
  
  if(i - 1 == size1){
    return true;
  }
  else
    return false;
  return true;
}

bool MyString::operator==(char* c_str){
  
  if(this->c_str == nullptr && c_str == nullptr)
    return true;
  
  else if(this->c_str == nullptr && c_str != nullptr)
    return false;
  
  else if(this->c_str != nullptr && c_str == nullptr)
    return false;
  
  int size1 = 0;
  for(; this->c_str[size1] != '\0'; size1++);
  
  int size2 = 0;
  for(; c_str[size2] != '\0'; size2++);

  if(size1 != size2)
    return false;
    
  int i = 0;
  for(; i < size1 + 1 && this->c_str[i] == c_str[i]; i++);
  
  if(i - 1 == size1){
    return true;                                                             
  }
  
  else
    return false;
  return true; 
}

const char* MyString::getString(){
  return c_str;
}
