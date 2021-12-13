#include "Account.h"


std::stack<int> Account::freeAccountNumbers = std::stack<int>();
int Account::accountNum = 0;

const std::string Account::getCustomerName(){
  return m_firstName + " " + m_lastName;
}

const char* Account::getDateOpened(){
  return m_dateOpened;
}

const int Account::getAccountNumber(){
  
  return m_accountNum;
}

const std::string Account::getSSN(){
  
  return m_SSN;
}

const int Account::getCurrentAccountNumber(){
  return accountNum;
}

