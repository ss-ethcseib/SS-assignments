#include <gtest/gtest.h>
#include<sstream>

TEST(Conversion_Tests, Hex_Conversions){
  std::stringstream str;
  str << std::hex << "0xf";

  int val = 0;
  str >> val;
  
  ASSERT_EQ(15, val);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
