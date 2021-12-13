#define TrueFalse(x) ((x) == (false) ? ("failed") : ("passed")) 
#include <iostream>
#include <string>
#include "BankLogic.h"
using namespace BankParts;

int main(){

  std::cout << "User Authorization tests\n\tblank input test: " << TrueFalse(BankLogic::UserAuthorization("", "")) << std::endl;
  std::cout << "\tNumber inputs: " << TrueFalse(BankLogic::UserAuthorization("900", "233")) << std::endl;
  std::cout << "\tIvalid string: " << TrueFalse(BankLogic::UserAuthorization("hello", "world")) << std::endl;
  std::cout << "\tEmpty input for username: " << TrueFalse(BankLogic::UserAuthorization("", "password")) << std::endl;
  std::cout << "\tEmpty input for password: " << TrueFalse(BankLogic::UserAuthorization("root", "")) << std::endl;
  
  std::cout << "\n\nDisplay Accounts tests\n\tNo accounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccounts()) << std::endl;
  BankLogic::CreateNewAccount("John Doe", "111222333");
  std:: cout << "\tAccounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccounts()) << std::endl;

  BankLogic::CloseAccounts();
  
  std::cout << "\n\nDisplay Account tests\n\tNo accounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccount("0")) << std::endl;
  BankLogic::CreateNewAccount("John Boom", "111222333");
  BankLogic::CreateNewAccount("Johnson Boomhaur", "222333444");
  BankLogic::CreateNewAccount("Jane Doe", "999888777");
  std::cout << "\tAccount number 2 selected: \n\t" << TrueFalse(BankLogic::DisplayAccount("1")) << std::endl;
  std::cout << "\tNegative account number given: " << TrueFalse(BankLogic::DisplayAccount("-2")) << std::endl;
  std::cout << "\tNon-existant account number given: " << TrueFalse(BankLogic::DisplayAccount("100")) << std::endl;
  std::cout << "\tBad input given (letters): " << TrueFalse(BankLogic::DisplayAccount("hi")) << std::endl;
  std::cout << "\tBad input given (special characters): " << TrueFalse(BankLogic::DisplayAccount("%^$")) << std::endl;
  std::cout << "\tNo input given: " << TrueFalse(BankLogic::DisplayAccount("")) << std::endl;
  
  std::cout << "\n\nSearch name tests\n\tSearch for name: " << TrueFalse(BankLogic::SearchName("John", "Boom")) << std::endl;
  std::cout << "\tEmpty string entered for first name: " << TrueFalse(BankLogic::SearchName("", "Boom")) << std::endl;
  std::cout << "\tEmpty string entered for last name: " << TrueFalse(BankLogic::SearchName("John", "")) << std::endl;
  std::cout << "\tNo matches exist: \n" << TrueFalse(BankLogic::SearchName("John", "Doe")) << std::endl;
  std::cout << "\tOnly one person matches: \n" << TrueFalse(BankLogic::SearchName("Jane",  "Doe")) << std::endl;
  std::cout << "\tMultiple people mathch: \n" << TrueFalse(BankLogic::SearchName("John", "Boom")) << std::endl;
  
  std::cout << "\n\nCreate new account tests\n\tOnly a first or last name entered: " << TrueFalse(BankLogic::CreateNewAccount("John", "888666777")) << std::endl;
  std::cout << "\tNo name entered: " << TrueFalse(BankLogic::CreateNewAccount("", "999111222")) << std::endl;
  std::cout << "\tSpecial Characters entered for name: " << TrueFalse(BankLogic::CreateNewAccount("J@ne doe", "888222999")) << std::endl;
  std::cout << "\tNo SSN entered: " << TrueFalse(BankLogic::CreateNewAccount("Paul Walker", "")) << std::endl;
  std::cout << "\tSSN too short: " << TrueFalse(BankLogic::CreateNewAccount("Johnson Johnson", "777")) << std::endl;
  std::cout << "\tSSN too long: " << TrueFalse(BankLogic::CreateNewAccount("James Turk", "7778886666")) << std::endl;
  std::cout << "\tSSN made of characters: " << TrueFalse(BankLogic::CreateNewAccount("Leonidas Pear", "asdfghjkl")) << std::endl;
  std::cout << "\tSSN made of special characters: " << TrueFalse(BankLogic::CreateNewAccount("Johnny Test", "%%%$$$###")) << std::endl;
  std::cout << "\tSSN not unique: " << TrueFalse(BankLogic::CreateNewAccount("Leonard james", "555555555")) << std::endl;
  std::cout << "\tExpected name and SSN entered: " << TrueFalse(BankLogic::CreateNewAccount("Leonard Nimoy", "555555555")) << std::endl;

  std::cout << "\n\nClose Account tests\n\tCharacters for account number: " << TrueFalse(BankLogic::CloseAccount("Leonard Nimoy")) << std::endl;
  std::cout << "\tSpecial characters for account number: " << TrueFalse(BankLogic::CloseAccount("@#$!")) << std::endl;
  std::cout << "\tEmpty string: " << TrueFalse(BankLogic::CloseAccount("")) << std::endl;
  std::cout << "\tAccount number too large: " << TrueFalse(BankLogic::CloseAccount("50")) << std::endl;
  std::cout << "\tAccount number negative: " << TrueFalse(BankLogic::CloseAccount("-2")) << std::endl;
  BankLogic::CloseAccount("0");
  std::cout << "\tAccount already closed: " << TrueFalse(BankLogic::CloseAccount("0")) << std::endl;
  std::cout << "\tClose an account: " << TrueFalse(BankLogic::CloseAccount("1")) << std::endl;

  std::cout << "\n\nClose all accounts test: " << TrueFalse(BankLogic::CloseAccounts()) << std::endl;

  std::cout << "\n\nisdigits tests:\n\tString of characters submitted: " << TrueFalse(BankLogic::isdigits("asfd")) << std::endl;
  std::cout << "\tString of special characters: " << TrueFalse(BankLogic::isdigits("!@#")) << std::endl;
  std::cout << "\tEmpty string: " << TrueFalse(BankLogic::isdigits("")) << std::endl;
  std::cout << "\tString of digits: " << TrueFalse(BankLogic::isdigits("123")) << std::endl;

  std::cout << "\n\nisalphabet tests:\n\tString of special characters: " << TrueFalse(BankLogic::isalphabet("!@#")) << std::endl;
  std::cout << "\tString of numbers: " << TrueFalse(BankLogic::isalphabet("123")) << std::endl;
  std::cout << "\tEmpty String: " << TrueFalse(BankLogic::isalphabet("")) << std::endl;
  std::cout << "\tString of charactes: " << TrueFalse(BankLogic::isalphabet("abc")) << std::endl;

  std::cout << "\n\nStringToLower tests: \n\tDoes a string containing uppercase letters become lowercase: " << (BankLogic::StringToLower("HELLO") == "hello" ? "passed" : "failed" ) << std::endl;

  std::cout << "\n\n\n\nAccount Class tests\n\n";
  Account acc("Peter Parker", "555222111");
  std::cout << "getDateOpened Tests: \n\tIs Date a nullptr: " << (acc.getDateOpened() == nullptr ? "passed" : "failed") << std::endl;

  std::cout << "getAccountNumber tests: \n\tSee if account number is greater than -1 but less than the current account number: " << (-1 < acc.getAccountNumber() < Account::getCurrentAccountNumber() ? "passed" : "failed") << std::endl;

  std::cout << "getSSN tests:\n\tIs SSN 9 digits long: " << (acc.getSSN().length() == 9 ? "passed" : "failed") << std::endl;

  std::cout << "getCustomerName tests:\n\tTest if name is an empty string: " << (acc.getCustomerName() != "" ? "passed" : "failed") << std::endl;
  
  return 0;
}
