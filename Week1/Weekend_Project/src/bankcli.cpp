#include <iostream>
#include <string>
#include <curses.h>
#include <cctype>
#include "Account.h"
#include <unordered_map>
#include <vector>

std::string getPassword(char);
std::string StringToLower(std::string);
bool isdigits(std::string);
bool isalphabet(std::string);

int main(int argc, char** args){

  std::string username = "";
  std::string password = "";
  bool cont = true;
  int errCount = 0;
  
  while(cont){
    std::cout << "Username: ";
    std::cin >> username;
    
    std::cout << "Password: ";
    std::cin >> password;
    //password = getPassword('*');

    if(password == "password" && username == "root"){
      cont = false;
      errCount = 0;
    }
    else
      std::cout << "Wrong username or password.\n";
    
    if(errCount == 2){
      std::cout << "Failed to login: Too many attempts made.\n";
      return -1;
    }
    errCount++;
  }
  std::cout << "Username and password accepted.\n";

  std::string command = "";
  std::unordered_map<int, Account*> customers = std::unordered_map<int, Account*>();
  //std::unordered_map<int, Account*> customers = {
  //		    {accountNum++, new Account("james tome", "111111111")},
  //		    {accountNum++, new Account("tim new", "111111112")},
  //		    {accountNum++, new Account("timothy newhouse", "111111113")}
  //};
  errCount = 0;
  cont = true;
  std::cin.ignore(1, '\n');

  while(cont){

    std::cout << "\n\nCommand list:\n1. Show accounts\n2. Display account\n3. Search name\n4. New account\n5. Close account\n6. Quit\nWhat is your command?\n";

    std::getline(std::cin, command);
    
    if(command == "1" || StringToLower(command) == "show accounts"){
      if(customers.empty()){
	std::cout << "Cannot complete the command. There are no accounts currently.\n";
      }
      else{
	for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	    it != customers.end(); it++){
	  
	  std::cout << "account > " << it->second->getCustomerName() << std::endl;
	  std::cout << "        > " << it->second->getAccountNumber() << std::endl;
	  std::cout << "        > " << it->second->getDateOpened() << std::endl << std::endl;
	}
      }
    }
    
    else if(command == "2" || StringToLower(command) == "display account"){

      if(customers.empty()){
	std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
      }
      else{
	std::string accNumStr = "";
	int accNum = 0;
	
	std::cout << "Give me the account number\naccount > ";
	std::cin >> accNumStr;
	std::cin.ignore(1, '\n');
        
	if(isdigits(accNumStr)){
	  accNum = std::stoi(accNumStr);
	  
	  if(accNum < accountNum && accNum > -1){
	    std::cout << "Account info:\n" << customers[accNum]->getCustomerName()
		      << std::endl << customers[accNum]->getSSN() << std::endl
		      << customers[accNum]->getDateOpened()
		      << customers[accNum]->getAccountNumber();
	  }
	}
	else{
	  std::cout << "ERR: Invalid account\n";
	}
      }
    }
    else if(command == "3" || StringToLower(command) == "search name"){
      
      if(customers.empty()){
	std::cout << "Sorry, can not complete command. There are currently no accounts in use. \n";
      }
      else{
	std::string firstName = "";
	std::string lastName = "";
        
	std::cout << "Please provide a first name followed by a last name.\n";
	std::cin >> firstName; std::cin >> lastName;
	std::cin.ignore(1, '\n');

	if(isalphabet(firstName + lastName)){
	  std::string mapFName = "";
	  std::string mapLName = "";
	  std::string nameMatch = "";
	  int nameMatchCount = 0;
	  std::vector<std::string> names = std::vector<std::string>();

	  for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	      it != customers.end(); it++){

	    mapFName = it->second->getCustomerName().substr(0, it->second->getCustomerName().find(" "));

	    mapLName = it->second->getCustomerName().substr(it->second->getCustomerName().find(" ") + 1);
	    
	    if(mapFName.find(firstName) != std::string::npos &&
	       mapLName.find(lastName) != std::string::npos){
	      
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
	    }
	  }

	  if(names.empty() && nameMatchCount == 0){
	    std::cout << "Sorry, no names were found matching first and last names";
	  }
	}
	else
	  std::cout << "Sorry, there was a problem with the string entered.\n";
      }
    }
    else if(command == "4" || StringToLower(command) == "new account"){
      std::string customerName = "";
      std::string SSN = "";
      bool nameCheck = true;
      bool ssnExists = false;
      
      std::cout << "Give the customer's name please.\n";
      std::getline(std::cin, customerName);

      if(customerName.find(" ") != std::string::npos){

	if(customerName.find(" ") == customerName.length() - 1){
	  nameCheck = false;
	}
      }
      else
	nameCheck = false;
      
      std::cout << "Now provide their SSN (Social Security number). This number should be 9 digits.\n";
      std::getline(std::cin, SSN);

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
	  
	  std::cout << acc->getCustomerName() << " was added to the system with account number " << acc->getAccountNumber() << ".\n";
	}
      }
      else{
	
	std::cout << "Sorry, the customer was not added due to a problem with their name or social security number.\n";
      }
    }
    else if(command == "5" || StringToLower(command) == "close account"){

      if(customers.empty()){
	std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
      }
      else{
	std::string accNumStr = "";
	int accNum = 0;
	std::string answer = "";
	bool loop = true;
	
	std::cout << "Which account do you want to close? (Account Number needed)" << std::endl;
	std::cin >> accNumStr;

	while(loop){
	  std::cout << "Are you sure you want to close the account? (y/n)\n";
	  std::cin >> answer;
	  std::cin.ignore(1, '\n');
	  
	  if(std::tolower(answer[0]) == 'y'){

	    loop = false;
	    
	    if(isdigits(accNumStr)){
	      accNum = std::stoi(accNumStr);
	      
	      if(accNum < accountNum && accNum > -1){
	        
		delete customers[accNum];
		customers.erase(accNum);		       
	      }
	      else
		std::cout << "\n Sorry, the account number entered does not match any accounts.\n";
	    }
	    else
	      std::cout << "\nSorry, the account number entered was of the wrong format.\n";
	  }
	  else if(std::tolower(answer[0]) == 'n')
	    loop = false;
	}
      }
    }
    else if(command == "6" || StringToLower(command) == "quit"){
      cont = false;
    }
    else{
      std::cout << "\nCommand not recognized\n\n";
    }
    
  }

  for(std::unordered_map<int, Account*>::iterator it = customers.begin();
      it != customers.end(); it++){
    delete it->second;
  }
  return 0;
}

bool isalphabet(std::string str){

  for(char c : str){
    if(!std::isalpha(c))
      if(c != ' ')
	return false;
  }
  return true;
}

bool isdigits(std::string str){

  for(char c : str){
    if(!std::isdigit(c)){
      return false;
    }
  }
  return true;
}
std::string StringToLower(std::string str){

  for(std::string::iterator it = str.begin(); it != str.end(); it++){
    *it = tolower(*it);
  }
  return str;
}

std::string getPassword(char sp = '*'){

  /*  std::string passwd = "";
  char input = '';

  while(true){
    input = getch();

    if(input == KEY_ENTER){
      std::cout << std::endl;
      return passwd;
    }
    else if(input == KEY_BACKSPACE && passwd.length() != 0){
      passwd.pop_back();
      std::cout << "\b \b";
      continue;
    }
    else if(input == KEY_BACKSPACE && passwd.length() == 0){
      continue;
    }

    passwd.push_back(input);
    std::cout << sp;
    }*/
  return "";
}
