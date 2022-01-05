#include <gtest/gtest.h>
#include <string.h>
#include "MyString.h"
#include <iostream>

char c_str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
MyString str(c_str);

char c_str2[6] = {'W', 'o', 'r', 'l', 'd', '\0'};
MyString str2(c_str2);

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

  if(strcmp(c_str, str.getString()) == 0){
    SUCCEED();
  }
  else
    FAIL();
}

TEST(Constructor_Tests, MyString_Object_Submitted_As_Ref){
  MyString sub(str);

  if(strcmp(c_str, sub.getString()) == 0)
    SUCCEED();
  else
    FAIL(); 
}

TEST(Constructor_Tests, MyString_Object_Submitted_As_Pointer){
  MyString sub(&str);

  if(strcmp(c_str, sub.getString()) == 0)
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

  if(s1.getString() == nullptr && strcmp(s2.getString(), c_str) == 0)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Plus_Operator){
  char tmp[13];
  strcat(tmp, c_str);
  strcat(tmp, c_str2);
  
  if(strcmp(str + str2, tmp) == 0){
    SUCCEED();
  }
  else{
    FAIL();
    return;
  }
  
  if(strcmp(str + &str2, tmp) == 0)
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

  if(strcmp(c_str, tmp.getString()) == 0)
    SUCCEED();
  else{
    FAIL();
    return;
  }
  char* tmpstr = new char[2];
  tmpstr[0] = 'c';
  tmp = tmpstr;
  if(strcmp(tmpstr, tmp.getString()) == 0){
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

  if(tmp2.getString() == nullptr && strcmp(tmp.getString(), c_str) == 0)
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
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}   
