#define SIZE 5

#include <gtest/gtest.h>
#include "MyVector.h"

void fillVec(myvector<int>& vec){
  for(int i = 0; i < SIZE; i++){
    vec.push_back(i);
  }
}

TEST(myvector_Function_Tests, Push_Back_Test){
  myvector<int> vec;
  myvector<int> vec1;
  
  for(int i = 0; i < 5; i++){
    vec.push_back(i);
    vec1.push_back(i);
  }

  if(vec == vec1)
    SUCCEED();
  else
    FAIL();
}

TEST(myvector_Function_Tests, Move_Push_back_Test){
  myvector<int> vec;
  
  vec.push_back(1);
  ASSERT_EQ(vec[0], 1);
}

TEST(myvector_Function_Tests, at_Function_Test){
  myvector<int> vec;
  fillVec(vec);
  
  ASSERT_EQ(vec[2], 2);
}

TEST(myvector_Function_Tests, pop_back_Test){
  myvector<int> vec;
  fillVec(vec);

  ASSERT_EQ(vec.size(), SIZE);
}

TEST(myvector_Function_Tests, clear_Test){
  myvector<int> vec;
  fillVec(vec);

  vec.clear();
  ASSERT_EQ(vec.size(), 0);
}

TEST(myvector_Function_Tests, reserve_Test){
  myvector<int> vec;
  fillVec(vec);
  int cap = 32;
  vec.reserve(cap);

  ASSERT_EQ(vec.capacity(), 32);
}

TEST(myvector_Function_Tests, size_Test){
  myvector<int> vec;

  fillVec(vec);

  ASSERT_EQ(vec.size(), SIZE);
}

TEST(myvector_Function_Tests, capacity_Test){
  myvector<int> vec;

  fillVec(vec);

  ASSERT_EQ(vec.capacity(), 16);
}

TEST(myvector_Operator_Tests, Copy_Assignment_Operator){
  myvector<int> vec;
  myvector<int> vec2;

  fillVec(vec2);

  vec = vec2;

  if(vec == vec2)
    SUCCEED();
  else
    FAIL();
}

TEST(myvector_Operator_Overload_Tests, Square_Bracket_Overload_Test){
  myvector<int> vec;

  fillVec(vec);

  ASSERT_EQ(vec[1], 1);
}

TEST(myvector_Operator_Overload_Tests, Equal_To_Operator_Test){
  myvector<int> vec1;
  myvector<int> vec2;
  fillVec(vec1);
  fillVec(vec2);
  
  if(vec1 == vec2)
    SUCCEED();
  else
    FAIL();
}

TEST(myvector_Operator_Overload_Tests, Move_Assignment_Operator_Test){
  myvector<int> vec1;
  fillVec(vec1);
  myvector<int> vec2;

  vec2 = std::move(vec1);

  ASSERT_EQ(vec2[1], 1);
  ASSERT_EQ(vec1.size(), 0);
}

TEST(Iterator_Tests, Loop_Through_myvector_Obj){
  myvector<int> vec;
  fillVec(vec);

  int i = 0;
  for(myvector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    if(*it != vec[i]){
      FAIL();
      return;
    }
    i++;
  }
  SUCCEED();
}

TEST(myvector_Constructor_Tests, Move_Constructor){
  myvector<int> vec;
  fillVec(vec);
  myvector<int> vec2(std::move(vec));

  ASSERT_EQ(vec2[0], 0);
  ASSERT_EQ(vec.size(), 0);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
