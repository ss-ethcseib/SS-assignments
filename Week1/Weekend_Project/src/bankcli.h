#pragma once

#include <iostream>
#include <string>
//#include <curses.h>
#include <cctype>
#include <unordered_map>
#include <vector>
#include "Account.h"


  class BankLogic{
  private:
    static std::unordered_map<int, Account*> customers;
    BankLogic(){};
    ~BankLogic(){};
    
  public:
    static bool UserAuthorization(std::string, std::string);
    static bool DisplayAccounts();
    static bool DisplayAccount(std::string);
    static bool SearchName(std::string, std::string);
    static bool CreateNewAccount(std::string, std::string);
    static bool CloseAccount(std::string);
    static bool CloseAccounts();
    static bool isalphabet(std::string);
    static bool isdigits(std::string);
    static bool CustomersEmpty();
  };

