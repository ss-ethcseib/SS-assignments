#include "bankcli.h"
  
std::unordered_map<int, Account*> BankLogic::customers = std::unordered_map<int, Account*>(); 

bool BankLogic::UserAuthorization(std::string username, std::string password){

  if(username == "" || password == "")
    return false;
  
  if(password == "password" && username == "root"){
    return true;
  }
  return false;
}

bool BankLogic::DisplayAccounts(){
  
  if(customers.empty()){
    std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
    return true;
  }
  
  for(std::unordered_map<int, Account*>::iterator it = customers.begin();
      it != customers.end(); it++){
    std::cout << "account > " << it->second->getCustomerName() << std::endl;
    std::cout << "        > " << it->second->getAccountNumber() << std::endl;
    std::cout << "        > " << it->second->getDateOpened() << std::endl << std::endl;
  }
  return true;
  
}

bool BankLogic::DisplayAccount(std::string accNumStr){

  if(accNumStr == "")
    return false;

  if(customers.empty()){
    std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
    return true;
  }
  
  int accNum = 0;
  
  if(isdigits(accNumStr)){                                                                                          
    accNum = std::stoi(accNumStr);

    if(accNum < Account::getCurrentAccountNumber() && accNum > -1){
	std::cout << "Account info:\nNAME: " << customers[accNum]->getCustomerName()
		  << "SSN: " << std::endl << customers[accNum]->getSSN() << std::endl
		  << "DATE OPENED: " << customers[accNum]->getDateOpened()
		  << "ACCOUNT NUMBER: " << customers[accNum]->getAccountNumber();
	return true;
    }
    else
      return false;
  }
  else
    return false;
  
  return false;
}

bool BankLogic::SearchName(std::string firstName, std::string lastName){

  if(firstName == "" || lastName == "")
    return false;
  
  if(customers.empty()){
    std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
    return true;
  }

  //Checking to see if the string is only characters and spaces
  if(isalphabet(firstName + lastName)){
    
    std::string mapFName = "";
    std::string mapLName = "";
    std::string nameMatch = "";
    int nameMatchCount = 0;
    std::vector<std::string> names = std::vector<std::string>();
    
    for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	it != customers.end(); it++){
      //Get the names of the customers stored in the map
      mapFName = it->second->getCustomerName().substr(0, it->second->getCustomerName().find(" "));
      mapLName = it->second->getCustomerName().substr(it->second->getCustomerName().find(" ") + 1);

      //Determining if the firstName and lastName are substrings of the map names
      if(mapFName.find(firstName) != std::string::npos &&
	 mapLName.find(lastName) != std::string::npos){

	//Checking to see if the names are exact mathces
	if(firstName == mapFName && lastName == mapLName){
	  
	  nameMatch = firstName + " " + lastName;
	  nameMatchCount++;
	}
	else{
	  names.push_back(mapFName + " " + mapLName);
	}
      }
    }
    int i = 0;
    if(nameMatchCount > 0){
      for(; i < nameMatchCount; i++){
	std::cout << i + 1 << ". " << nameMatch << std::endl;
      }
    }
    
    if(!names.empty()){
      for(std::vector<std::string>::iterator it = names.begin();
	  it != names.end(); it++){
	
	std::cout << i + 1 << ". " << *it << std::endl;
	i++;
      }
      return true;
    }
    if(names.empty() && nameMatchCount == 0){
      std::cout << "Sorry, no names were found matching first and last names";
      return true;
    }
  }
  return true;
}

bool BankLogic::CreateNewAccount(std::string customerName, std::string SSN){

  if(customerName == "" || SSN == "")
    return false;
  
  bool nameCheck = true;
  bool ssnExists = false;
  
    if(customerName.find(" ") != std::string::npos){
      if(customerName.find(" ") == customerName.length() - 1){
	nameCheck = false;
      }
    }
    else
      nameCheck = false;
    
    for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	it != customers.end(); it++){
      if(it->second->getSSN() == SSN){
	ssnExists = true;
      }
    }
    
    if(SSN.length() == 9 && isdigits(SSN) && !ssnExists &&
       isalphabet(customerName) && nameCheck){
      
      if(std::stoi(SSN) > 0){
	Account* acc = new Account(customerName, SSN);
	customers[acc->getAccountNumber()] = acc;
	
	//std::cout << acc->getCustomerName() << " was added to the system with account number " <<
	//acc->getAccountNumber() << ".\n";
      }
      else
	return false;
    }
    else
      return false;
    return true;
}

bool BankLogic::CloseAccount(std::string accNumStr){

  if(accNumStr == "")
    return false;
  
  if(customers.empty()){
    std::cout << "Sorry, command could not be completed because there are currently no accounts in use.\n";
    return true;
  }
  int accNum = 0;
  
  if(isdigits(accNumStr)){
    accNum = std::stoi(accNumStr);
    
    if(accNum < Account::getCurrentAccountNumber() && accNum > -1){
	  
      delete customers[accNum];
      customers.erase(accNum);
    }
    else
      return false;
      }
  else
    return false;
  
  return true;
}


bool BankLogic::CloseAccounts(){
  if(customers.empty()){
    return true;
  }
  
  for(std::unordered_map<int, Account*>::iterator it = customers.begin();
      it != customers.end(); it++){
    delete it->second;
  }
  customers.clear();
  return true;
}

bool BankLogic::isalphabet(std::string str){

  if(str == "")
    return false;
  for(char c : str){
    if(!std::isalpha(c))
      if(c != ' ')   
	return false;
  }
  return true;
}

bool BankLogic::isdigits(std::string str){

  if(str == "")
    return false;
  
  for(char c: str){
    if(!std::isdigit(c)){
      return false;
    }
  }
  return true;
}

