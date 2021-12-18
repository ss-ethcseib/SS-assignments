#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include "Utilities.h"
//#include <curses.h>
#include <cctype>
#include <unordered_map>
#include <deque>
#include "Account.h"
#include "Accounts.pb.h"
#include <fstream>

//Encryption libraries
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>
#include <cryptopp/modes.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

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
    static const bool UserAuthorization(std::string, std::string);
    static const bool DisplayAccounts();
    static const bool DisplayAccount(Account*);
    static const bool DisplayAccount(std::string);
    static const bool AddTransaction(Account*, std::string*, std::string*);
    static const bool SearchName(std::string, std::string);
    static const bool CreateNewAccount(std::string, std::string);
    static const bool CloseAccount(std::string);
    static const bool CloseAccounts();
    static const bool WriteCustomersData();
    static const bool ReadCustomersData();
  };
}
