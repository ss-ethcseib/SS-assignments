#include <gtest/gtest.h>
#include <sstream>
#include "utilities.h"

TEST(StringToLower_Tests, string_entered){
  std::string str = "ASF";

  StringToLower(str);

  ASSERT_EQ("asf", str);
}

TEST(is_Hex_Tests, hex_value_entered){

  std::string str = "0xf";
  
  ASSERT_EQ(true, is_Hex(&str));
}

TEST(is_Hex_Tests, non_Hex_value_entered){
  std::string str = "f";

  ASSERT_EQ(false, is_Hex(&str));
}

TEST(is_dec_Tests, decimal_value_entered){

  std::string str = "123";

  ASSERT_EQ(true, is_dec(&str));
}

TEST(is_dec_Tests, non_decimal_value_entered){
  std::string str = "kl";

  ASSERT_EQ(false, is_dec(&str));
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
