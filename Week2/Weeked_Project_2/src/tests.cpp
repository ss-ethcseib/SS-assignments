#define TrueFalse(x) ((x) == (false) ? ("failed") : ("passed")) 
#include <iostream>
#include <string>
#include "BankLogic.h"
using namespace BankParts;

int main(){

  std::string* username = new std::string;
  std::string* password = new std::string;
  *username = "";
  *password = "";
  std::cout << "\tBankLogic class tests\nUser Authorization tests\n\tblank input test: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "900";
  *password = "233";
  std::cout << "\tNumber inputs: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "hello";
  *password = "world";
  std::cout << "\tIvalid string: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "";
  *password = "password";
  std::cout << "\tEmpty input for username: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "root";
  *password = "";
  std::cout << "\tEmpty input for password: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "  ";
  *password = "password";
  std::cout << "\tSpaces entered for username: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "root";
  *password = "   ";
  std::cout << "\tSpaces entered for password: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  *username = "root";
  *password = "password";
  std::cout << "\tCorrect username and password entered: " << TrueFalse(BankLogic::UserAuthorization(username, password)) << std::endl;
  delete username;
  delete password;

  std::cout << "\n\nDisplay Accounts tests\n\tNo accounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccounts()) << std::endl;
  std::string* name = new std::string("John Doe");
  int SSN = 111222333;
  BankLogic::CreateNewAccount(name, SSN);
  std:: cout << "\tAccounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccounts()) << std::endl;

  BankLogic::CloseAccounts();

  std::cout << "\n\nDisplay Account tests\n\tNo accounts in use: \n\t" << TrueFalse(BankLogic::DisplayAccount(0)) << std::endl;
  *name = "John Boom";
  BankLogic::CreateNewAccount(name, 112334556);
  *name = "Johnson Boomhaur";
  BankLogic::CreateNewAccount(name, 222333444);
  *name = "Jane Doe";
  BankLogic::CreateNewAccount(name, 999888777);
  std::cout << "\tNull value given: \n\t" << TrueFalse(BankLogic::DisplayAccount(nullptr)) << std::endl;
  *name = "john smith";
  std::string* ssn = new std::string("996778447");
  Account* acc2 = Account::CreateAccount(name, ssn, 15);
  
  std::cout << "\tGood input given. Account object provided:\n\t" << TrueFalse(BankLogic::DisplayAccount(acc2))<< std::endl;
  std::cout << "\tGood input given. Account number 2 selected \n\t" << TrueFalse(BankLogic::DisplayAccount(1)) << std::endl;
  std::cout << "\tNegative account number given: " << TrueFalse(BankLogic::DisplayAccount(-1)) << std::endl;
  std::cout << "\tNon-existant account number given: " << TrueFalse(BankLogic::DisplayAccount(50)) << std::endl;

  int accNum = 0;
  float* amt = new float(100.5f);
  std::string* type = new std::string("debit");

  std::cout << "\n\nAddTransaction tests\n\tAccount number does not match an account: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  std::cout << "\tAccount number is negative: " << TrueFalse(BankLogic::AddTransaction(-1, amt, type)) << std::endl;
  *amt = -555555;
  std::cout << "\tAmmount entered is negative and more than the balance: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  BankLogic::AddTransaction(accNum, amt, type);
  *amt = -100;
  std::cout << "\tAmmount entered is negative but less than account balance: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *amt = 100;
  std::cout << "\tAmmount entered is positive: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  std::cout << "\tTransaction type is lowercase debit: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *type = "credit";
  std::cout << "\tTransaction type is lowercase credit: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *type = "DEBIT";
  std::cout << "\tTransactin type is Uppercase DEBIT: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *type = "CREDIT";
  std::cout << "\tTransaction type is Uppercase CREDIT: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *type = "adf";
  std::cout << "\tTransaction type is neither credit nor debit: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl; 
  *type = "   ";
  std::cout << "\tTransaction type is spaces: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  *type = "123";
  std::cout << "\tTransaction type is numbers: " << TrueFalse(BankLogic::AddTransaction(accNum, amt, type)) << std::endl;
  delete amt;
  delete type;

  std::string* fname = new std::string("John");
  std::string* lname = new std::string("Boom");
  std::cout << "\n\nSearch name tests\n\tSearch for name and select account 1: " << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  *fname = "";
  std::cout << "\tEmpty string entered for first name: " << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  *lname = "";
  *fname = "John";
  std::cout << "\tEmpty string entered for last name: " << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  *lname = "Doe";
  std::cout << "\tNo matches exist: \n" << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  *fname = "Jane";
  std::cout << "\tOnly one person matches: \n" << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  *fname = "John";
  *lname = "Boom";
  std::cout << "\tMultiple people mathch: \n" << TrueFalse(BankLogic::SearchName(fname, lname)) << std::endl;
  delete fname;
  delete lname;

  name = new std::string("John");
  std::cout << "\n\nCreate new account tests\n\tOnly a first or last name entered: " << TrueFalse(BankLogic::CreateNewAccount(name, 888666777)) << std::endl;
  *name = "";
  std::cout << "\tNo name entered: " << TrueFalse(BankLogic::CreateNewAccount(name, 999111222)) << std::endl;
  *name = "J@ne doe";
  std::cout << "\tSpecial Characters entered for name: " << TrueFalse(BankLogic::CreateNewAccount(name, 888222999)) << std::endl;
  *name = "   ";
  std::cout << "\tSpaces entered for name: " << TrueFalse(BankLogic::CreateNewAccount(name, 222111455)) << std::endl;
  *name = "Paul Walker";
  std::cout << "\tSSN too short: " << TrueFalse(BankLogic::CreateNewAccount(name, 777)) << std::endl;
  //std::cout << "\tSSN too long: " << TrueFalse(BankLogic::CreateNewAccount(name, 7778886666)) << std::endl;
  std::cout << "\tSSN not unique: " << TrueFalse(BankLogic::CreateNewAccount(name, 555555555)) << std::endl;
  std::cout << "\tExpected name and SSN entered: " << TrueFalse(BankLogic::CreateNewAccount(name, 555555555)) << std::endl;
  delete name;
  
  std::cout << "\tAccount number too large: " << TrueFalse(BankLogic::CloseAccount(50)) << std::endl;
  std::cout << "\tAccount number negative: " << TrueFalse(BankLogic::CloseAccount(-2)) << std::endl;
  BankLogic::CloseAccount(0);
  std::cout << "\tAccount already closed or does not exist: " << TrueFalse(BankLogic::CloseAccount(0)) << std::endl;
  std::cout << "\tClose an account: " << TrueFalse(BankLogic::CloseAccount(1)) << std::endl;

  std::cout << "\n\nWrite to bin file using protobuf tests:\n\t" << TrueFalse(BankLogic::WriteCustomersData()) << std::endl;

  std::cout << "\n\nRead from bin file customer data tests:\n\t" << TrueFalse(BankLogic::ReadCustomersData()) << std::endl;

  BankLogic::CloseAccounts();
  std::cout << "\n\nWrite to bin file customers data when no accounts exist tests:\n\t" << TrueFalse(BankLogic::WriteCustomersData()) << std::endl;
  std::cout << "\n\nRead customer data from bin file when bin file does not exist\n\t" << TrueFalse(BankLogic::ReadCustomersData()) << std::endl;

  std::string nam = "James smith";
  BankLogic::CreateNewAccount(&nam, 222333444);
  std::cout << "\n\nClose all accounts test:\n\tWhen accounts exist: " << TrueFalse(BankLogic::CloseAccounts()) << std::endl;
  std::cout << "\tWhen accounts do not exist: " << TrueFalse(BankLogic::CloseAccounts()) << std::endl;						   



  std::string* val = new std::string("as");
  std::cout << "\n\n\nUtilities functions tests:\n\t";
  std::cout << "\n\nisdigits tests:\n\tString of characters submitted: " << TrueFalse(isdigits(val)) << std::endl;
  *val = "#$@";
  std::cout << "\tString of special characters: " << TrueFalse(isdigits(val)) << std::endl;
  *val = "";
  std::cout << "\tEmpty string: " << TrueFalse(isdigits(val)) << std::endl;
  *val = "   ";
  std::cout << "\tSpaces submitted: " << TrueFalse(isdigits(val)) << std::endl;
  *val = "234";
  std::cout << "\tString of digits: " << TrueFalse(isdigits(val)) << std::endl;

  *val = "$#!";
  std::cout << "\n\nisalphabet tests:\n\tString of special characters: " << TrueFalse(isalphabet(val)) << std::endl;
  *val = "123";
  std::cout << "\tString of numbers: " << TrueFalse(isalphabet(val)) << std::endl;
  *val = "";
  std::cout << "\tEmpty String: " << TrueFalse(isalphabet(val)) << std::endl;
  *val = "   ";
  std::cout << "\tSpaces submitted: " << TrueFalse(isalphabet(val)) << std::endl;
  *val = "abc";
  std::cout << "\tString of charactes: " << TrueFalse(isalphabet(val)) << std::endl;

  *val = "HELLO";
  std::cout << "\n\nStringToLower tests: \n\tDoes a string containing uppercase letters become lowercase: " << (StringToLower(val) == "hello" ? "passed" : "failed" ) << std::endl;
  *val = "   ";
  std::cout << "\tShould return when just spaces are submitted: " << (StringToLower(val) == "   " ? "passed" : "failed") << std::endl;

  delete val;



  name = new std::string("Peter Parker");
  ssn = new std::string("555222111");
  std::cout << "\n\n\n\nAccount Class tests\n\n";
  Account* acc = Account::CreateAccount(name, ssn, 90);
  std::cout << "getDateOpened Tests: \n\tIs Date a nullptr: " << (acc->getDateOpened() == nullptr ? "passed" : "failed") << std::endl;
  delete ssn;
  delete name;
  std::cout << "getAccountNumber tests: \n\tSee if account number is greater than -1: " << (-1 < acc->getAccountNumber() ? "passed" : "failed") << std::endl;

  //std::cout << "getSSN tests:\n\tIs SSN 9 digits long: " << (acc->getSSN().length() == 9 ? "passed" : "failed") << std::endl;

  std::cout << "getCustomerName tests:\n\tTest if name is an empty string: " << (acc->getCustomerName() != "" ? "passed" : "failed") << std::endl;

  std::cout << "getBalance tests:\n\tReturn val should be >= 0: " << (acc->getBalance()) << std::endl;

  amt = new float(-400);
  std::cout << "updateBalance tests:\n\tValue entered is negative and greater than the balance: " << TrueFalse(acc->UpdateBalance(amt)) << std::endl;
  *amt = 400;
  std::cout << "\tValue entered is positive: " << TrueFalse(acc->UpdateBalance(amt)) << std::endl;

  delete amt;
  delete name;
  return 0;
}
