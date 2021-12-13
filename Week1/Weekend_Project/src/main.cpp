#include <iostream>
#include <string>
//#include <curses.h>
#include <cctype>
#include "bankcli.h"
#include <unordered_map>
#include <vector>

std::string getPassword(char);
std::string StringToLower(std::string);

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

    if(BankLogic::UserAuthorization(username, password)){
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
  errCount = 0;
  cont = true;
  std::cin.ignore(1, '\n');

  while(cont){

    std::cout << "\n\nCommand list:\n1. Show accounts\n2. Display account\n3. Search name\n4. New account\n5. Close account\n6. Quit\nWhat is your command?\n";

    std::getline(std::cin, command);
    
    if(command == "1" || StringToLower(command) == "show accounts"){
      if(!BankLogic::DisplayAccounts())
	std::cout << "Cannot complete the command. There are no accounts currently.\n"; 
    }
    
    else if(command == "2" || StringToLower(command) == "display account"){
      
      std::string accNumStr = "";
      
      std::cout << "Give me the account number\naccount > ";
      std::cin >> accNumStr;
      std::cin.ignore(1, '\n');
      
      if(!BankLogic::DisplayAccount(accNumStr)){
	std::cout << "ERR: Invalid account";
      }
    }
    else if(command == "3" || StringToLower(command) == "search name"){
      
	std::string firstName = "";
	std::string lastName = "";
        
	std::cout << "Please provide a first name followed by a last name.\n";
	std::cin >> firstName; std::cin >> lastName;
	std::cin.ignore(1, '\n');

	if(!BankLogic::SearchName(firstName, lastName)){
	  std::cout << "ERR: There was a problem with the name submitted.";
	}
    }
    else if(command == "4" || StringToLower(command) == "new account"){
      std::string customerName = "";
      std::string SSN = "";
      
      std::cout << "Give the customer's name please.\n";
      std::getline(std::cin, customerName);

      std::cout << "Now provide their SSN (Social Security number). This number should be 9 digits.\n";
      std::getline(std::cin, SSN);

      if(!BankLogic::CreateNewAccount(customerName, SSN)){
	std::cout << "Sorry, there was a problem with the customer's name or their SSN";
      }
      else
	std::cout << customerName << " was added to the system." << std::endl;
    }
    else if(command == "5" || StringToLower(command) == "close account"){

	std::string accNumStr = "";
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
	    if(!BankLogic::CloseAccount(accNumStr))
	      std::cout << "\nSorry, the account number entered does not match any accounts.\n"; 
	  }
	  
	  else if(std::tolower(answer[0]) == 'n')
	    loop = false;
	}
    }
    
    else if(command == "6" || StringToLower(command) == "quit"){
      cont = false;
    }
    else{
      std::cout << "\nCommand not recognized\n\n";   
    }
  }
  
  BankLogic::CloseAccounts();
  return 0;
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
