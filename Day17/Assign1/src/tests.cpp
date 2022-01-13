#include <gtest/gtest.h>
#include "includes.h"

Dollar dollar(30.f);
Conversion conversion;
Account<Dollar, Conversion> account(&dollar, &conversion);

TEST(test, test){
  Euro e;

  e = (Euro&)account;
}

TEST(Operator_Overload_Tests, Plus_Operator_Using_Float){

  if(account + 1.f == 31.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Plus_Equal_Operator_Using_Int){
  account += 2;

  if(account == 32.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Incrememt_Operator){
  account++;

  if(account == 33.f)
    SUCCEED();
  else{
    FAIL();
    return;
  }

  ++account;

  if(account == 34.f)
    SUCCEED();
  else
    FAIL();

  account--;
}

TEST(Operator_Overload_Tests, Minus_Operator_Using_Double){

  if(account - 2.0 == 31.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Minus_Equal_Using_Char){
  char c = 5;
  account -= c;
  
  if(account == 28.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Decrement_Operator){

  account--;
  if(account == 27.f)
    SUCCEED();
  else{
    FAIL();
    return;
  }

  --account;
  if(account == 26.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Multiply_Test){
  if(account * 2 == 52.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Operator_Overload_Tests, Operator_Casting){
  Dollar d;
  d = account;

  if(d == 26.f)
    SUCCEED();
  else
    FAIL();
}

TEST(Account_Deposit_Tests, Expected_Data_Submitted){
  Dollar d(15.f);
  Conversion c;
  Account<Dollar, Conversion> acc(&d, &c);

  Euro e(15.f);
  ASSERT_EQ(acc.Deposit<Euro>(&e).getAmmount(), d + e * 1.15f);

  e.setAmmount(-2.f);
  ASSERT_EQ(acc.Deposit<Euro>(&e).getAmmount(), d + 15.f * 1.15f);
}

TEST(Account_Withdrawal_Tests, Expected_Data_Submitted){
  Euro e(12.f);
  Conversion c;
  Dollar d(10.f);
  
  Account<Euro, Conversion> acc(&e, &c);

  ASSERT_EQ(acc.Withdraw<Dollar>(&d).getAmmount(), e - d * 0.869565f);
  
  d.setAmmount(-12.f);
  ASSERT_EQ(acc.Withdraw<Dollar>(&d).getAmmount(), e - 10.f * 0.869565f);
}

TEST(Currency_Function_Test, Dollar_To_Euro){
  Dollar d(14.f);
  Conversion c;
  Account<Dollar, Conversion> acc(&d, &c);

  Account<Euro, Conversion>* accptr = acc.Currency<Euro>();
  Euro e;
  ASSERT_EQ(accptr->Deposit<Euro>(&e).getAmmount(), d * 0.869565f);
}

TEST(Account_Operator_Tests, Copy_Assignment_Operator){
  Dollar d(1.f);
  Conversion c;

  Account<Dollar, Conversion> acc(&d, &c);

  d.setAmmount(14.f);

  Account<Dollar, Conversion> acc2(&d, &c);

  acc = acc2;

  if(acc == acc2)
    SUCCEED();
  else
    FAIL();
}


int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
