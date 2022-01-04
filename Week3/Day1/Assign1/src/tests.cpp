#include <gtest/gtest.h>
#include "Sentence.h"
#include <string>
#include <iostream>

char str[12] = "Hello World";
Sentence sent(str);

TEST(Constructor_Tests, Null_For_Char_Constructor){
  char* sent = nullptr;
  Sentence sentence(sent);
  ASSERT_EQ(nullptr, sentence.getSentence());
}

TEST(Constructor_Tests, Null_For_Sentence_Constructor){
  Sentence* sentence1 = nullptr;
  Sentence sentence2(sentence1);

  ASSERT_EQ(nullptr, sentence2.getSentence());
}

TEST(Constructor_Tests, Move_Constructor_Test){
  Sentence sentence1(str);
  Sentence sentence2(std::move(sentence1));

  if(sentence1.getSentence() == nullptr && strcmp(sentence2.getSentence(), str) == 0)
    SUCCEED();
  else
    FAIL();
}

TEST(Get_Tests, Get_Null_Sentence){
  Sentence sentence;

  ASSERT_EQ(nullptr, sentence.getSentence());
}

TEST(Get_Tests, Get_Filled_Sentence){

  ASSERT_EQ(0, strcmp(str, sent.getSentence()));
}

TEST(Get_Tests, Get_Number_Of_Words){

  ASSERT_EQ(2, sent.num_words());
}

TEST(Get_Tests, Get_Word_Given_Negative){
  ASSERT_EQ("\nErr: index out of range\n", sent.get_word(-1));
}

TEST(Get_Tests, Get_Word_Given_Out_Of_Bounds_Index){
  ASSERT_EQ("\nErr: index out of range\n", sent.get_word(15));
}

TEST(Get_Tests, Get_Word_2){

  if(sent.get_word(1).compare("World") == 0)
    SUCCEED();
  else
    FAIL();
}

TEST(Get_Tests, Replace_With_Nullptr){
  sent.replace(nullptr);
  ASSERT_EQ(nullptr, sent.getSentence());
}

TEST(Get_Tests, Replace_With_New_Sentence){
  sent.replace(str);
  
  ASSERT_EQ(0, strcmp(sent.getSentence(), str));
}

TEST(Get_Tests, Get_Offsets){
  ASSERT_EQ(2, sent.getOffsets().size());
}

TEST(Operator_Overloads, Standard_Assignment_Operator){
  Sentence s1;
  
  s1 = sent;
  if(strcmp(str, s1.getSentence()) == 0)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overloads, Move_Assignment_Operator){
  Sentence s1;
  Sentence s2;

  s2 = sent;
  s1 = std::move(s2);

  if(s2.getSentence() == nullptr && strcmp(str, s1.getSentence()) == 0){
    SUCCEED();
  }
  else
    FAIL();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
