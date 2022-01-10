/*Developed by: Ethan Seiber*/

#pragma once

class MyString{
 private:
  char* c_str;
  
  void strcpy(const char&);
  void strcpy(const char*);
  
 public:
  ~MyString(){

    if(c_str != nullptr){
      delete[] c_str;
    }
  }
  
  MyString(){
    c_str = nullptr;
  }

  MyString(char* str){

    if(str != nullptr){
      int i = 0;
      for(; str[i] != '\0'; i++);
      
      c_str = new char[i];
      
      for(int x = 0; x < i + 1; x++)
	c_str[x] = str[x];
    }
    else
      c_str = nullptr;
  }

  MyString(MyString& str){
    c_str = nullptr;
    strcpy(str.c_str);
  }
  
  MyString(MyString* str){
    
    c_str = nullptr;

    if(str != nullptr)
      strcpy(str->c_str);
  }
  
  MyString(MyString&& str) noexcept{
    
    c_str = str.c_str;
    str.c_str = nullptr;
  }

  MyString& operator+(MyString&);
  //MyString& operator+(MyString*);

  MyString& operator*(int);

  char operator[](int);

  void operator=(const char&);
  //void operator=(const char*);
  void operator=(MyString&&);

  bool operator==(MyString&);
  //bool operator==(MyString*);
  bool operator==(char*);  

  const char* getString();
};
