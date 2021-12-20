#include <iostream>
#include <string>
#include "BankLogic.h"
#include "Utilities.h"
#include <unordered_map>

using namespace BankParts;

std::string getPassword(char);

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

    if(BankLogic::UserAuthorization(&username, &password)){
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

  BankLogic::ReadCustomersData();
  
  errCount = 0;
  cont = true;
  std::cin.ignore(1, '\n');

  while(cont){
    std::string command = "";
    std::cout << "\n\nCommand list:\n" 
"\t1. Show accounts\n" 
"\t2. Display account\n"
"\t3. Search name\n" 
"\t4. New account\n" 
"\t5. Close account\n" 
"\t6. Quit\n"  
"What is your command?\n";

    
    std::getline(std::cin, command);
    
    command = TrimWhiteSpace(&command);
    
    if(command == "1" || BankParts::StringToLower(&command) == "show accounts"){
      if(!BankLogic::DisplayAccounts())
	std::cout << "\nSorry, it would appear there are currently no accounts in use.\n";
    }
    else if(command == "2" || BankParts::StringToLower(&command) == "display account"){
      
      std::string accNumStr = "";
      
      std::cout << "Give me the account number\naccount > ";
      std::cin >> accNumStr;
      std::cin.ignore(1, '\n');

      accNumStr = TrimWhiteSpace(&accNumStr);

      if(accNumStr != "" && isdigits(&accNumStr)){
	
	int accNum = std::stoi(accNumStr);
      
	if(!BankLogic::DisplayAccount(accNum)){
	  std::cout << "\nSorry, this seems to be an invalid account number.\n";
	}
	else{
	  
	  std::string ans = "";
	  std::cout << "Do you want to update account balance? (y/n)\n";
	  std::cin >> ans;
	  std::cin.ignore(1, '\n');
        
	if(std::tolower(ans[0]) == 'y'){
	  
	  std::cout << "Enter transaction ammount:\n";
	  std::string transAmmountStr = "";
	  std::cin >> transAmmountStr;
	  std::cin.ignore(1, '\n');
	  std::cout << "Enter transaction type: (Credit/Debit)\n";
	  std::string transType = "";
	  std::cin >> transType;
	  std::cin.ignore(1, '\n');

	  transAmmountStr = TrimWhiteSpace(&transAmmountStr);
	  transType = TrimWhiteSpace(&transType);


	  if(transAmmountStr[0] == '+' || transAmmountStr[0] == '-'){
	    	    
	    std::string* split1 = new std::string(transAmmountStr.substr(1));
	    
	    if(split1->find(".") != std::string::npos){
	      
	      std::string* split2 = new std::string(split1->substr(split1->find(".") + 1));                                                         
	      
	      *split1 = split1->substr(0, split1->find("."));
	      
	      if(!isdigits(split1) || !isdigits(split2)){
		delete split1;
		delete split2;
		std::cout << "\nTransaction ammount was not a recognizable number.\n";
		continue;
	      }
	      delete split2;
	      delete split1;
	    }
	  } 
	  else if(transAmmountStr.find(".") != std::string::npos){
	    
	    std::string* split1 = new std::string(transAmmountStr.substr(0, transAmmountStr.find(".")));
	    
	    std::string* split2 = new std::string(transAmmountStr.substr(transAmmountStr.find(".") + 1));
	    
	    if(!isdigits(split1) || !isdigits(split2)){
	      delete split1;
	      delete split2;
	      
	      std::cout << "\nTransaction ammount was not a recognizable string.\n";
	      continue;
	    }
	    delete split1;
	    delete split2;
	  } 
	  else if(!isdigits(&transAmmountStr)){
	    std::cout << "\nThe transaction ammount was not a recognizable number\n.";
	    continue;
	  }
	  
	  float transAmmount = std::stof(transAmmountStr);
	  
	  if(!BankLogic::AddTransaction(accNum, &transAmmount, &transType))
	    std::cout << "\nFailed to add transaction\n";
	  
	  //while ((getchar()) != '\n');
	}
	else if(std::tolower(ans[0]) != 'n')
	  std::cout << "\nSorry, that was not an answer. Returning home\n";
	}
	
      }
      else
	std::cout << "\nThe account number was not recognizable.\n";
    }
    
    else if(command == "3" || BankParts::StringToLower(&command) == "search name"){
      
	std::string firstName = "";
	std::string lastName = "";
        
	std::cout << "Please provide a first name followed by a last name.\n";
	std::cin >> firstName; std::cin >> lastName;
	std::cin.ignore(1, '\n');

	firstName = TrimWhiteSpace(&firstName);
	lastName = TrimWhiteSpace(&lastName);
	
	if(!BankLogic::SearchName(&firstName, &lastName)){
	  std::cout << "\nSorry, there was a problem with the name submitted.\n";
	}
	//while ((getchar()) != '\n');
    }
    else if(command == "4" || BankParts::StringToLower(&command) == "new account"){
      std::string customerName = "";
      std::string SSN = "";
      
      std::cout << "Give the customer's name please.\n";
      std::getline(std::cin, customerName);

      std::cout << "Now provide their SSN (Social Security number). This number should be 9 digits.\n";
      std::getline(std::cin, SSN);

      customerName = TrimWhiteSpace(&customerName);
      SSN = TrimWhiteSpace(&SSN);

      if(SSN.length() != 9 || !isdigits(&SSN)){
	std::cout << "\nThe entered SSN did not meet the requirements needed.\n";
	continue;
      }
      if(customerName.find(" ") == std::string::npos){
	std::cout << "\nOnly a first name was provided. Please try again.\n";
	continue;
      }
      
      if(!BankLogic::CreateNewAccount(&customerName, &SSN)){
	
	std::cout << "\nSorry, there was a problem with the customer's name or their SSN.\n";
      }
      else
	std::cout << customerName << " was added to the system." << std::endl;
      //while ((getchar()) != '\n');
    }
    else if(command == "5" || BankParts::StringToLower(&command) == "close account"){

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

	    accNumStr = TrimWhiteSpace(&accNumStr);

	    if(accNumStr == "" && !isdigits(&accNumStr)){
	      std::cout << "\nThe account number entered was not a recognizable number.\n";
	      continue;
	    }

	
	    int accNum = std::stoi(accNumStr);
	    if(!BankLogic::CloseAccount(accNum))
	      std::cout << "\nSorry, the account number entered does not match any accounts.\n"; 
	  }
	  
	  else if(std::tolower(answer[0]) == 'n')
	    loop = false;

	  //while ((getchar()) != '\n');
	}
    }
    
    else if(command == "6" || BankParts::StringToLower(&command) == "quit"){
      cont = false;
    }
    else{
      std::cout << "\nCommand not recognized\n\n";   
    }
  }

  BankLogic::WriteCustomersData();
  BankLogic::CloseAccounts();
  
  return 0;
}
