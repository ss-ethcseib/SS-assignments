#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <stack>

namespace BankParts{
  class Account {
  private:
    std::string m_firstName;
    std::string m_lastName;
    int m_accountNum;
    char* m_dateOpened;
    std::string m_SSN;
    //When an account is deleted there is now an open
    //account/account number to be assigned. That is
    //what this does. Stores the account numbers that
    //closed to be re-assigned to someone else.
    static std::stack<int> freeAccountNumbers;
    static int accountNum;

  public:
    Account(std::string customerName, std::string ssn): m_SSN(ssn) {

      
      if(!freeAccountNumbers.empty()){
	m_accountNum = freeAccountNumbers.top();
	freeAccountNumbers.pop();
      }
      else{
        m_accountNum = accountNum++;
      }
      m_firstName = customerName.substr(0, customerName.find(" "));
      m_lastName = customerName.substr(customerName.find(" ") + 1);
      
      time_t now = time(0);
      m_dateOpened = std::ctime(&now);
    };
    ~Account(){
      freeAccountNumbers.push(this->m_accountNum);
    };
    
    const char* getDateOpened();
    const int getAccountNumber();
    const std::string getSSN();
    const std::string getCustomerName();
    static const int getCurrentAccountNumber();
  };
}
