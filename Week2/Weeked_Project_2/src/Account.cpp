#include "Account.h"

namespace BankParts{

  Account* Account::CreateAccount(const std::string* customerName, const std::string* SSN, const int accNum){
    
    if(*customerName == "" || *SSN == "" || accNum < 0)
      return nullptr;
    
    bool nameCheck = true;
    Account* acc = nullptr;
    
    if(customerName->find(" ") != std::string::npos){
      
      if(customerName->find(" ") == customerName->length() - 1){
	
        nameCheck = false;	
      }
    }
    else
      nameCheck = false;

    if(SSN->length() == 9 && isdigits(SSN) &&
       isalphabet(customerName) && nameCheck)
      	
      acc = new Account(customerName, SSN, accNum);
    else
      return nullptr;
    return acc; 
  }
  
  const float Account::getBalance(){
    return m_balance;
  }
  
  const bool Account::UpdateBalance(const float* ammount){
    
    if(m_balance + *ammount < 0.0f){
      std::cout << "Err: Insufficient balance.";
      return true;
    }
    m_balance += *ammount;
    return true;
  }
  
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
}
