#include "BankLogic.h"

namespace BankParts{
  std::unordered_map<int, Account*> BankLogic::customers = std::unordered_map<int, Account*>(); 
  std::stack<int> BankLogic::freeAccountNumbers = std::stack<int>();
  int BankLogic::accountNum = 0;

  const bool BankLogic::UserAuthorization(std::string username, std::string password){
    
    if(username == "" || password == "")
      return false;
    std::string strng;
    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::HexEncoder encoder;//(new CryptoPP::FileSink(std::cout));

    byte* key_vals = new byte[CryptoPP::AES::DEFAULT_KEYLENGTH] {24, 56,054,19,36,22,32,19,68,16,16,115,18,159,56,043};
    byte* iv_vals = new byte[CryptoPP::AES::BLOCKSIZE] {241,212,241,61,41,66,100,36,240,244,79,156,97,28,84,235};
    
    //key_vals = {};
    //prng.GenerateBlock(key_vals, CryptoPP::AES::DEFAULT_KEYLENGTH);
    //prng.GenerateBlock(iv_vals, CryptoPP::AES::BLOCKSIZE);

    CryptoPP::SecByteBlock key(reinterpret_cast<const byte*>(key_vals), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::SecByteBlock iv(reinterpret_cast<const byte*>(iv_vals), CryptoPP::AES::BLOCKSIZE);

    std::string cipher;
    try{
      CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption e;
      e.SetKeyWithIV(key, key.size(), iv);
      CryptoPP::StringSource s(password, true,
	    new CryptoPP::StreamTransformationFilter(e,
		       new CryptoPP::StringSink(cipher)));

      encoder.Put((const byte*)&cipher[0], cipher.size());
      encoder.MessageEnd();
      
      encoder.Get((byte*)&cipher[0], cipher.size()); 
    }
    catch(...){

    }

    if(cipher == "FB2FFE082284915C" && username == "root"){
      return true;
    }
    return false;
  }
  
  const bool BankLogic::DisplayAccounts(){
    
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
  
  const bool BankLogic::DisplayAccount(Account* acc){
    if(acc == nullptr)
      return false;
    
    if(customers.empty()){
      std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
	return true;
    }
    
    std::cout << "Account info:\nNAME: " << acc->getCustomerName() << std::endl
	      << "SSN: " << std::to_string(acc->getSSN()).substr(5) << std::endl
	      << "DATE OPENED: " << acc->getDateOpened()
      	      << "ACCOUNT NUMBER: " << acc->getAccountNumber();
    
    return true;    
  }

  const bool BankLogic::DisplayAccount(std::string accNumStr){
    
    if(accNumStr == "")
      return false;
    
    if(customers.empty()){
      std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
      return true;
    }
    
    int accNum = 0;
    
    if(isdigits(accNumStr)){                                                                                          
      accNum = std::stoi(accNumStr);

      if(accNum < accountNum && accNum > -1){
	std::cout << "Account info:\n\tNAME: " << customers[accNum]->getCustomerName() << std::endl
		  << "\tSSN: " << std::to_string(customers[accNum]->getSSN()).substr(5) << std::endl
		  << "\tDATE OPENED: " << customers[accNum]->getDateOpened()
		  << "\tACCOUNT NUMBER: " << customers[accNum]->getAccountNumber() << std::endl;
	return true;
      }
      else
	return false;
    }
    else
      return false;
    
    return false;
  }
  
  const bool BankLogic::AddTransaction(std::string* accNumStr, std::string* ammount, std::string* transType){

    if(StringToLower(transType) != "debit" && StringToLower(transType) != "credit"){
      
      return false;
    }
    
    if(StringToLower(transType) == "credit")
      return true;

    if(!isdigits(*accNumStr))
      return false;
    
    if(!customers[std::stoi(*accNumStr)]->UpdateBalance(ammount)){
      return false;
    }
    return true;
  }
  
  const bool BankLogic::SearchName(std::string firstName, std::string lastName){
    
    if(firstName == "" || lastName == "")
      return false;
    
    if(customers.empty()){
      std::cout << "Sorry, can not complete command. There are currently no accounts in use.\n";
      return true;
    }
    
    firstName = StringToLower(&firstName);
    lastName = StringToLower(&lastName);
    //Checking to see if the string is only characters and spaces
    if(isalphabet(firstName + lastName)){
      
      std::string mapFName = "";
      std::string mapLName = "";
      std::string nameMatch = "";
      std::deque<Account*> names = std::deque<Account*>();
      
      for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	  it != customers.end(); it++){
	//Get the names of the customers stored in the map
	mapFName = it->second->getCustomerName().substr(0, it->second->getCustomerName().find(" "));
	mapFName = StringToLower(&mapFName);

	mapLName = it->second->getCustomerName().substr(it->second->getCustomerName().find(" ") + 1);
	mapLName = StringToLower(&mapLName);
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
	
	if(!isdigits(ans)){
	  std::cout << "No number entered or number was negative. Lookup failed.";
	  return false;
	}
	
	if(std::stoi(ans) >= i + 1 || std::stoi(ans) <= 0){
	  std::cout<< "Invalid number detected.\n";

	  std::cout << "Please provide a name or type home to leave.\n";
	  std::getline(std::cin, ans);

	  if(StringToLower(&ans) == "home")
	    return true;

	  std::string* name = new std::string;
	  
	  for(std::deque<Account*>::iterator it = names.begin();
	      it < names.end(); it++){
	    *name = (*it)->getCustomerName();
	  if(StringToLower(name) == StringToLower(&ans)){
	      DisplayAccount(*it);
	      delete name;
	      return true;
	    }
	  }
	  std::cout << "Sorry, the person entered is not in the list";
	  delete name;
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
  
  const bool BankLogic::CreateNewAccount(std::string customerName, std::string SSN){
    
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
      if(it->second->getSSN() == std::stoi(SSN)){
	ssnExists = true;
      }
    }
    
    if(SSN.length() == 9 && isdigits(SSN) && !ssnExists &&
       isalphabet(customerName) && nameCheck){

      Account* acc = nullptr;

      if(std::stoi(SSN) > 0){
	if(!freeAccountNumbers.empty()){
	  acc = new Account(customerName, std::stoi(SSN), freeAccountNumbers.top());
	  freeAccountNumbers.pop();
	}
	else
	  acc = new Account(customerName, std::stoi(SSN), accountNum++);
	
	customers[acc->getAccountNumber()] = acc;
      }
      else
	return false;
    }
    else
      return false;
    return true;
  }
  
  const bool BankLogic::CloseAccount(std::string accNumStr){
    
    if(accNumStr == "")
      return false;
    
    if(customers.empty()){
      std::cout << "Sorry, command could not be completed because there are currently no accounts in use.\n";
      return true;
    }
    int accNum = 0;
    
    if(isdigits(accNumStr)){
      accNum = std::stoi(accNumStr);
    
    if(accNum < accountNum && accNum > -1){
      
      freeAccountNumbers.push(accNum);
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
  
  
  const bool BankLogic::CloseAccounts(){
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

  const bool BankLogic::WriteCustomersData(){

    if(customers.empty())
      return true;
    
    PBAccounts accs;
    
    for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	it != customers.end(); it++){

      PBAccount* acc = accs.add_accounts();
      acc->set_balance(it->second->GetBalance());
      acc->set_name(it->second->getCustomerName());
      acc->set_accountnum(it->second->getAccountNumber());
      acc->set_dateopened(it->second->getDateOpened());
      acc->set_ssn(it->second->getSSN());
    }

    std::ofstream file = std::ofstream("Customer_data_binary.bin", std::ios_base::out | std::ios_base::binary);

    accs.SerializeToOstream(&file);

    file.close();

    return true;
  }

  const bool BankLogic::ReadCustomersData(){
    
    std::ifstream file = std::ifstream("Customer_data_binary.bin", std::ios::in);

    PBAccounts accs;
    if(!accs.ParseFromIstream(&file)){
      
      file.close();
      return false;
    }
    
    file.close();

    for(int i = 0; i < accs.accounts_size(); i++){
      customers[accs.accounts(i).accountnum()] = new Account(&accs.accounts(i));
      if(accountNum < accs.accounts(i).accountnum()){
	accountNum = accs.accounts(i).accountnum() + 1;
      }
    }

    int* nums = new int[accountNum];
    
    for(int i = 0; i < accs.accounts_size(); i++){
      nums[accs.accounts(i).accountnum()] = 1;
    }

    for(int i = 0; i < accountNum; i++){
      if(nums[i] == 0)
	freeAccountNumbers.push(i);
    }
    
    delete[] nums;
    return true;
  }
}


