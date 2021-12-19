#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <stack>
#include "Utilities.h"
#include "Accounts.pb.h"
#include <cstring>

namespace BankParts{
  class Account {
  private:
    float m_balance;
    std::string m_firstName;
    std::string m_lastName;
    int m_accountNum;
    char* m_dateOpened;
    int m_SSN;

  public:

    Account(const PBAccount* acc){
      m_balance = acc->balance();
      m_firstName = acc->name().substr(0, acc->name().find(" "));
      m_lastName = acc->name().substr(acc->name().find(" ") + 1);
      m_accountNum = acc->accountnum();
      m_dateOpened = new char[acc->dateopened().length()];
      std::strcpy(m_dateOpened, acc->dateopened().c_str());
      m_SSN = acc->ssn();
    }

    Account(const std::string customerName, const int ssn, const int accNum): m_accountNum(accNum), m_SSN(ssn) {
      
      m_balance = 0.0f;
      m_firstName = customerName.substr(0, customerName.find(" "));
      m_lastName = customerName.substr(customerName.find(" ") + 1);
      
      time_t now = time(0);
      m_dateOpened = std::ctime(&now);
    };
    ~Account(){};

    const char* getDateOpened();
    const int getAccountNumber();
    const int getSSN();
    const std::string getCustomerName();
    const float GetBalance();
    bool UpdateBalance(std::string*);
  };
}
