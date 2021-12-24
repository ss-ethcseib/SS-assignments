#include "gtest/gtest.h"
#include "BigNumber.h"

TEST(MultiplyTest, PositiveNos){

  long int n1 = 12;
  long int n2 = 12;
  BigNumber num1(&n1), num2(&n2);

  num1.multiply(num1, num2);
  ASSERT_EQ(12 * 12, num1.number());
}

TEST(MultiplyTest, OneNegativeNo){
  long int n1 = -12;
  long int n2 = 12;

  BigNumber num1(&n1), num2(&n2);
  num1.multiply(num1, num2);

  ASSERT_EQ(-144, num1.number());
}

TEST(MultiplyTest, TwoNegativeNos){

  long int n1 = -12;
  long int n2 = -12;
  
  BigNumber num1(&n1), num2(&n2);
  
  num1.multiply(num1, num2);
  
  ASSERT_EQ(144, num1.number());     
}

TEST(MultiplyTest, Num2_Has_More_Digits_Than_Num1){

  long int n1 = 1;
  long int n2 = 12;
  
  BigNumber num1(&n1), num2(&n2);
  num1.multiply(num1, num2);
  
  ASSERT_EQ(12, num1.number());     
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
