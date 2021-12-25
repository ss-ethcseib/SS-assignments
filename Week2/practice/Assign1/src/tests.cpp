#include "gtest/gtest.h"
#include "BigNumber.h"
#include <string>
#include <vector>

TEST(Constructor_tests, ExpectedString){
  std::string str = "123";
  BigNumber num(&str);

  ASSERT_EQ("123", num.number());
}

TEST(Constructor_tests, Overflow_Value){
  std::string str = "3000000000";
  BigNumber num1(&str);

  ASSERT_EQ("3000000000", num1.number());
}

TEST(Simulate_Multiply_Tests, PositiveNos){
  BigNumber num1(125), num2(2);
  std::vector<std::vector<unsigned char>> test = {{'1', '2', '5'}, {'2'},
						  {'0'}, {'5', '0'},
						  {'2', '0', '0'},
						  {'2', '5', '0'}};
  std::vector<std::vector<unsigned char>> vec = num1.simulate_multiply(num2);

  ASSERT_EQ(test, vec);
}

TEST(MultiplyTest, PositiveNos){

  long int n1 = 12;
  long int n2 = 12;
  BigNumber num1(n1), num2(n2);

  num1.multiply(num2);
  ASSERT_EQ(n1 * n2, std::stol(num2.number()));
}

TEST(MultiplyTest, OneNegativeNo){
  long int n1 = -12;
  long int n2 = 12;

  BigNumber num1(n1), num2(n2);
  num1.multiply(num2);

  ASSERT_EQ(n1 * n2, std::stol(num2.number()));
}

TEST(MultiplyTest, TwoNegativeNos){

  long int n1 = -12;
  long int n2 = -12;
  
  BigNumber num1(n1), num2(n2);
  
  num1.multiply(num2);
  
  ASSERT_EQ(n1 * n2, std::stol(num2.number()));     
}

TEST(MultiplyTest, Num2_Has_More_Digits_Than_Num1){

  long int n1 = 2;
  long int n2 = 12;
  
  BigNumber num1(n1), num2(n2);
  num1.multiply(num2);
  
  ASSERT_EQ(n1 * n2, std::stol(num2.number()));     
}

TEST(MultiplyTest, multiplication_overflow){
  long int n1 = 4000000000;
  long int n2 = 1;

  BigNumber num1(n1), num2(n2);
  num1.multiply(num2);
  ASSERT_EQ(n1 * n2, std::stoll(num2.number()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
