#include "MyString.h"

void MyString::strcpy(char*& dest, const char& src){
  strcpy(dest, &src);
}

void MyString::strcpy(char*& dest, const char* src){

  if(src == nullptr)
    return;
  
  int i = 0;
  for(; src[i] != '\0'; i++);

  if(dest != nullptr)
    delete[] dest;

  dest = new char[i];

  for(i = 0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }
  dest[i] = src[i];
}

char* MyString::operator+(MyString& str){
  return this->operator+(&str);
}

char* MyString::operator+(MyString* str){

  if(str == nullptr)
    return nullptr;

  int size1 = 0;
  for(; this->c_str[size1] != '\0'; size1++);

  int size2 = 0;
  for(; str->c_str[size2] != '\0'; size2++);

  char* newC_str = new char[size1 + size2 - 1];
  
  for(int i = 0; i < size1; i++){
    newC_str[i] = this->c_str[i];
  }

  int x = size1;
  for(int i = 0; i < size2 + 1; i++){
    newC_str[x] = str->c_str[i];
    x++;
  }
  return newC_str;
}

char* MyString::operator*(int amt){

  int size = 0;
  for(; this->c_str[size] != '\0'; size++);

  char* newC_str = new char[size * (amt + 1)];

  int i = 0;
  for(; i < size * (amt + 1); i++){
    
      newC_str[i] = this->c_str[i % size];
  }
  newC_str[i] = '\0';
  return newC_str;
}

char MyString::operator[](int index){
  return this->c_str[index];
}

void MyString::operator=(const char& str){
  
  this->operator=(&str);
}

void MyString::operator=(const char* str){

  if(this->c_str == str)
    return;
  
  if(str == nullptr){
    
    if(this->c_str != nullptr){
      delete[] this->c_str;
    }
    this->c_str = nullptr;
    
    return;
  }
  
  int size = 0;
  for(; str[size] != '\0'; size++);

  if(this->c_str != nullptr)
    delete[] this->c_str;

  this->c_str = new char[size];

  int i = 0;
  for(; i < size + 1; i++){
    this->c_str[i] = str[i];
  }
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
  return this->operator==(&str);  
}

bool MyString::operator==(MyString* str){

  if(this == str)
    return true;
  
  if(this->c_str == nullptr && str->c_str == nullptr)
    return true;
  else if(this->c_str == nullptr && str->c_str != nullptr)
    return false;
  else if(this->c_str != nullptr && str->c_str == nullptr)
    return false;
  
  int size1 = 0;
  for(; this->c_str[size1] != '\0'; size1++);

  int size2 = 0;
  for(; str->c_str[size2] != '\0'; size2++);

  if(size1 != size2)
    return false;
  
  int i = 0;
  for(; this->c_str[i] == str->c_str[i]; i++);
  std::cout << "\n\n check\n " << i << " " << size1 << " " << str->c_str;
  if(i - 1 == size1){
    return true;std::cout << "\n\npass\n";
  }
  else
    return false;
  
  return true;
}

const char* MyString::getString(){
  return c_str;
}
