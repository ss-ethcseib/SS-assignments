#include "BankLogic.h"

namespace BankParts{
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
    std::cout << "account > Customer name: " << it->second->getCustomerName() << std::endl;
    std::cout << "        > Account number: " << it->second->getAccountNumber() << std::endl;
    std::cout << "        > Date opened: " << it->second->getDateOpened() << std::endl << std::endl;
  }
  return true;
  
  }
  
  bool BankLogic::DisplayAccount(Account* acc){
    if(acc == nullptr)
      return false;
    
    if(customers.empty()){
      std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
	return true;
    }
    
    std::cout << "Account info:\nNAME: " << acc->getCustomerName() << std::endl
	      << "SSN: " << acc->getSSN().substr(5) << std::endl
	      << "DATE OPENED: " << acc->getDateOpened()
      	      << "ACCOUNT NUMBER: " << acc->getAccountNumber();
    
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
	std::cout << "Account info:\nNAME: " << customers[accNum]->getCustomerName() << std::endl
		  << "SSN: " << customers[accNum]->getSSN().substr(5) << std::endl
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
    
    firstName = StringToLower(firstName);
    lastName = StringToLower(lastName);
    //Checking to see if the string is only characters and spaces
    if(isalphabet(firstName + lastName)){
      
      std::string mapFName = "";
      std::string mapLName = "";
      std::string nameMatch = "";
      std::deque<Account*> names = std::deque<Account*>();
      
      for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	  it != customers.end(); it++){
	//Get the names of the customers stored in the map
	mapFName = StringToLower(it->second->getCustomerName().substr(0, it->second->getCustomerName().find(" ")));
	
	mapLName = StringToLower(it->second->getCustomerName().substr(it->second->getCustomerName().find(" ") + 1));
	
	//Determining if the firstName and lastName are substrings of the map names
	if(mapFName.find(firstName) != std::string::npos &&
	   mapLName.find(lastName) != std::string::npos){
	  
	  //Checking to see if the names are exact mathces
	  if(firstName == mapFName && lastName == mapLName){
	    
	    names.push_front(it->second);
	  }
	  else{
	    
	    names.push_back(it->second);
	  }
	}
      }
      
      if(!names.empty()){
	int i = 0;
	for(std::deque<Account*>::iterator it = names.begin();
	    it != names.end(); it++){
	  
	  std::cout << i + 1 << ". " << (*it)->getCustomerName() << std::endl;
	  i++;
	}
	
	std::string ans = "";
	int choice = 0;
	
	std::cout << "Select an account by entering one of the numbers.\n";
	std::cin >> ans;
	std::cin.ignore(1, '\n');
	
	if(!BankLogic::isdigits(ans)){
	  std::cout << "No number entered or number was negative. Lookup failed.";
	  return false;
	}
	
	if(std::stoi(ans) >= i + 1 || std::stoi(ans) <= 0){
	  std::cout<< "Invalid number detected.\n";

	  std::cout << "Please provide a name or type home to leave.\n";
	  std::getline(std::cin, ans);

	  if(StringToLower(ans) == "home")
	    return true;
	  
	  for(std::deque<Account*>::iterator it = names.begin();
	      it < names.end(); it++){
	    if(StringToLower((*it)->getCustomerName()) == StringToLower(ans)){
	      DisplayAccount(*it);
	      return true;
	    }
	  }
	  std::cout << "Sorry, the person entered is not in the list";
	  return true;
	}
	else if((choice = std::stoi(ans)) < i + 1 && std::stoi(ans) > 0){
	  
	  BankLogic::DisplayAccount(names[choice - 1]);
	  return true;
	}
	return true;
      }
      if(names.empty()){
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
  
  std::string BankLogic::StringToLower(std::string str){
    
    for(std::string::iterator it = str.begin(); it != str.end(); it++){
      *it = tolower(*it);
    }
    return str;
    
  }
}
