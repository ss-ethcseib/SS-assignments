#pragma once

#include <iostream>
#include <string>
//#include <curses.h>
#include <cctype>
#include <unordered_map>
//#include <vector>
#include <deque>
#include "Account.h"


namespace BankParts{
  class BankLogic{
  private:
    //Allows for quick account number lookups and
    //For the deletion of an arbitrary account.
    static std::unordered_map<int, Account*> customers;
    //Wanted to try and keep this class from being instantiated
    //because it's a purely static class.
    BankLogic(){};
    ~BankLogic(){};
    
  public:
    static bool UserAuthorization(std::string, std::string);
    static bool DisplayAccounts();
    static bool DisplayAccount(Account*);
    static bool DisplayAccount(std::string);
    static bool SearchName(std::string, std::string);
    static bool CreateNewAccount(std::string, std::string);
    static bool CloseAccount(std::string);
    static bool CloseAccounts();
    //Checks to see if the string is made up of just
    //letters and spaces i.e no special characters and
    //numbers
    static bool isalphabet(std::string);
    //Checks to see if the string is made up of just
    //digits. No letters or special characters.
    static bool isdigits(std::string);
    static std::string StringToLower(std::string);
  };
}
