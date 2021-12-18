#include "Account.h"

namespace BankParts{
  std::stack<int> Account::freeAccountNumbers = std::stack<int>();
  int Account::accountNum = 0;

  const float Account::GetBalance(){
    return m_balance;
  }
  
  bool Account::UpdateBalance(std::string* ammount){
    
    if(ammount[0] == "+" || ammount[0] == "-"){                             
      if(!isdigits((*ammount).substr(1))){                                       
        return false;                                                         
      }                                                                      
    }
    else if(!isdigits(*ammount)){                                           
      
      return false;                                                           
    }
    float amt = std::stof(*ammount);
    
    if(m_balance + amt < 0.0f){
      std::cout << "Err: Insufficient balance.";
      return true;
    }
    m_balance += amt;
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
  
  const int Account::getSSN(){
    
    return m_SSN;
  }
  
  const int Account::getCurrentAccountNumber(){
    return accountNum;
  }
  
}
