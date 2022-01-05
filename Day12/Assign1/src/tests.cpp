/*Developed by: Ethan Seiber*/

#include <gtest/gtest.h>
#include "MyString.h"

char c_str[6] = {'H', 'e', 'l', 'l', 'o'};
MyString str(c_str);

char c_str2[6] = {'W', 'o', 'r', 'l', 'd'};
MyString str2(c_str2);

//Used to concatenate c_strings together
char* strcat(char* c_str1, char* c_str2){

  if(c_str1 == nullptr)
    return c_str2;
  else if(c_str2 == nullptr)
    return c_str1;
  else if(c_str1 == nullptr && c_str2 == nullptr)
    return nullptr;
  
  int size1 = 0;
  for(; c_str1[size1] != '\0'; size1++);
  
  int size2 = 0;
  for(; c_str2[size2] != '\0'; size2++);
  
  char* newC_str = new char[size1 + size2 - 1];
  
  for(int i = 0; i < size1; i++){
    
    newC_str[i] = c_str1[i];  
  }
  
  int x = size1;
  for(int i = 0; i < size2 + 1; i++){
    
    newC_str[x] = c_str2[i];
    x++;
  }
  return newC_str;
}

//compares two c_strings for equality
bool strcmp(char* c_str1, char* c_str2){

  if(c_str1 == c_str2)
    return true;
  
  if(c_str1 == nullptr && c_str2 == nullptr)
    return true;
  
  else if(c_str1 == nullptr && c_str2 != nullptr)
    return false;
  
  else if(c_str1 != nullptr && c_str2 == nullptr)
    return false;

  int size1 = 0;
  for(; c_str1[size1] != '\0'; size1++);

  int size2 = 0;
  for(; c_str2[size2] != '\0'; size2++);

if(size1 != size2)                                                          
    return false;
 
  int i = 0;
  for(; i < size1 + 1 && c_str1[i] == c_str2[i]; i++);
  
  if(i - 1 == size1){
    return true;
  }
  else
    return false;
  return true;  
}

TEST(strcat_Tests, nullptr_Tests){

  char* tmp = nullptr;

  if(strcmp(strcat(tmp, c_str), c_str))
    SUCCEED();
  else{
    FAIL();
    return;
  }

  if(strcmp(strcat(c_str, tmp), c_str))
    SUCCEED();
  else{
    FAIL();
    return;
  }

  if(strcmp(strcat(tmp, tmp), tmp))
    SUCCEED();
  else{
    FAIL();
  }
}

TEST(strcat_Tests, Input_Cstrings){
  char tmp [13] = "HelloHello\0";
  if(strcmp(strcat(c_str, c_str), tmp))
    SUCCEED();
  else{
    FAIL();
  }
}

TEST(strcmp_Tests, Input_Nullptr){
  char* tmp = nullptr;

  if(strcmp(tmp, c_str)){
    FAIL();
    return;
  }
  else if(strcmp(c_str, tmp)){
    FAIL();
    return;
  }
  else if(strcmp(c_str, c_str)){
    SUCCEED();
  }
  else{
    FAIL();
    return;
  }
}

TEST(strcmp_Tests, Cstrings_input){
  char tmp[7] = "Hello\0";
  char tmp2[7] = "Hello\0";
  
  if(strcmp(tmp, tmp)){
    SUCCEED();
  }
  else{
    FAIL();
    return;
  }

  if(strcmp(tmp, tmp2))
    SUCCEED();
  else{
    FAIL();
    return;
  }
}

TEST(Constructor_Tests, Nullpointer_For_Cstring){
  char* tmp = nullptr;
  MyString s(tmp);

  ASSERT_EQ(nullptr, s.getString());
}

TEST(Constructor_Tests, Nullpointer_For_MyString_Object){
  MyString* tmp = nullptr;
  MyString tmp2(tmp);

  ASSERT_EQ(nullptr, tmp2.getString());
}

TEST(Constructor_Tests, CString_Submitted_As_Pointer){

  MyString sub(&str);
  if(str == c_str){
    SUCCEED();
  }
  else
    FAIL();
}

TEST(Constructor_Tests, MyString_Object_Submitted_As_Ref){
  MyString sub(str);

  if(sub == c_str)
    SUCCEED();
  else
    FAIL(); 
}

TEST(Constructor_Tests, MyString_Object_Submitted_As_Pointer){
  MyString sub(&str);

  if(sub == c_str)
    SUCCEED();
  else
    FAIL();
}

TEST(Constructor_Tests, MyString_Object_Submitted_As_Nullpointer){
  MyString* tmp = nullptr;
  MyString sub(tmp);

  ASSERT_EQ(nullptr, sub.getString());
}

TEST(Constructor_Tests, Move_Constructor){
  MyString s1(c_str);
  MyString s2(std::move(s1));

  if(s1.getString() == nullptr && s2 == c_str)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Plus_Operator){
  char tmpstr[13];
  strcat(tmpstr, c_str);
  strcat(tmpstr, c_str2);

  if(strcmp(str + str2, tmpstr) == 0){
    SUCCEED();
  }
  else{
    FAIL();
    return;
  }
  
  if(strcmp(str + &str2, tmpstr) == 0)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Multiplication_Operator){

  char tmp [16] = "Hello";
  strcat(tmp, c_str);
  strcat(tmp, c_str);
  
  if(strcmp(str * 2, tmp) == 0)
    SUCCEED();
  else{
    FAIL();
  }
}

TEST(Operator_Overload_Tests, Square_Bracket_Operator){
  ASSERT_EQ(c_str[1], str[1]);
}

TEST(Operator_Overload_Tests, Assignment_Operator){
  MyString tmp;
  
  tmp = c_str;

  if(tmp == c_str)
    SUCCEED();
  else{
    FAIL();
    return;
  }
  char* tmpstr = new char[2];
  tmpstr[0] = 'c';
  tmp = tmpstr;
  if(tmp == tmpstr){
    SUCCEED();
    delete[] tmpstr;
  }
  else{
    delete[] tmpstr;
    FAIL();
    return;
  }
}

TEST(Operator_Overload_Tests, Assignment_Move_Operator){

  MyString tmp;
  MyString tmp2(c_str);
  
  tmp = std::move(tmp2);

  if(tmp2.getString() == nullptr && tmp == c_str)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, EqualTo_Operator){
  MyString tmp(c_str);
  MyString tmp2(c_str2);

  if(str == tmp){
    SUCCEED();
  }
  else{
    FAIL();
    return;
  }
  
  if(str == tmp2){
    FAIL();
    return;
  }

  if(tmp == c_str)
    SUCCEED();
  else{
    FAIL();
    return;
  }

  if(tmp == tmp)
    SUCCEED();
  else
    FAIL();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}   
