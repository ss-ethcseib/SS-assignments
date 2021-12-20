#include "BankLogic.h"

namespace BankParts{
  std::unordered_map<int, Account*> BankLogic::customers = std::unordered_map<int, Account*>(); 
  std::stack<int> BankLogic::freeAccountNumbers = std::stack<int>();
  int BankLogic::accountNum = 0;

  const bool BankLogic::UserAuthorization(const std::string* username, const std::string* password){
    
    if(*username == "" || *password == "")
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
      CryptoPP::StringSource s(*password, true,
	    new CryptoPP::StreamTransformationFilter(e,
		       new CryptoPP::StringSink(cipher)));

      encoder.Put((const byte*)&cipher[0], cipher.size());
      encoder.MessageEnd();
      
      encoder.Get((byte*)&cipher[0], cipher.size()); 
    }
    catch(...){

    }

    if(cipher == "FB2FFE082284915C" && *username == "root"){
      return true;
    }
    return false;
  }
  
  const bool BankLogic::DisplayAccounts(){
    
    if(customers.empty()){
      return false;
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
	return false;
    }

    DisplayAccount(acc->getAccountNumber());

    return true;    
  }

  const bool BankLogic::DisplayAccount(const int accNum){
        
    if(customers.empty()){
      return false;
    }

    std::stack<int> tmp;
    for(int i = 0; i < freeAccountNumbers.size(); i++){
      if(accNum == freeAccountNumbers.top()){
	
        for(int x = 0; x < tmp.size(); x++){
	  freeAccountNumbers.push(tmp.top());
	  tmp.pop();
        }
	
        return false;	
      }
      tmp.push(freeAccountNumbers.top());
      freeAccountNumbers.pop();
    }
    freeAccountNumbers = tmp;  

    if(accNum < accountNum && accNum > -1){
      
      std::cout << "Account info:\n\tNAME: " << customers[accNum]->getCustomerName() << std::endl
		<< "\tBALANCE: " << customers[accNum]->getBalance() << std::endl
		<< "\tSSN: " << customers[accNum]->getSSN().substr(5) << std::endl
		<< "\tDATE OPENED: " << customers[accNum]->getDateOpened()
		<< "\tACCOUNT NUMBER: " << customers[accNum]->getAccountNumber() << std::endl;
      
      return true;
    }
    else{
      return false;
    }
    
    return false;
  }
  
  const bool BankLogic::AddTransaction(const int accNum, const float* ammount, const std::string* transType){
    
    if(customers.empty()){
      return false;
    }
    
    if(StringToLower(transType) != "debit" && StringToLower(transType) != "credit"){
      
      return false;
    }
    
    if(StringToLower(transType) == "credit")
      return true;
    
    if(accNum < 0 || accNum >= accountNum)
      return false;

    std::stack<int> tmp;
    for(int i = 0; i < freeAccountNumbers.size(); i++){

      if(accNum == freeAccountNumbers.top()){
	for(int x = 0; x < tmp.size(); x++){
	  freeAccountNumbers.push(tmp.top());
	  tmp.pop();
	}
	return false;
      }
      tmp.push(freeAccountNumbers.top());
      freeAccountNumbers.pop();
    }
    freeAccountNumbers = tmp;
    
    if(!customers[accNum]->UpdateBalance(ammount)){
      return false;
    }

    return true;
  }
  
  const bool BankLogic::SearchName(const std::string* firstName, const std::string* lastName){
    
    if(*firstName == "" || *lastName == "")
      return false;
    
    if(customers.empty()){
      return false;
    }
    
    std::string fName = StringToLower(firstName);
    std::string lName = StringToLower(lastName);
    std::string fullName = fName + lName;
    //Checking to see if the string is only characters and spaces
    if(isalphabet(&fullName)){
      
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
	if(mapFName.find(fName) != std::string::npos &&
	   mapLName.find(lName) != std::string::npos){
	  
	  //Checking to see if the names are exact mathces
	  if(fName == mapFName && lName == mapLName){
	    
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
	
	ans = TrimWhiteSpace(&ans);

	std::cin.ignore(1, '\n');
	
	if(!isdigits(&ans) || std::stoi(ans) >= i + 1 || std::stoi(ans) <= 0){
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
  
  const bool BankLogic::CreateNewAccount(const std::string* customerName, const std::string* SSN){

    if(customerName == nullptr || SSN == nullptr)
      return false;
    if(*customerName == "" || *SSN == "")
      return false;

    if(SSN->length() != 9 || !isdigits(SSN))
      return false;

    if(customerName->find(" ") == std::string::npos)
      return false;
  
    bool ssnExists = false;
    Account* acc = nullptr;
    
    for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	it != customers.end(); it++){
      if(it->second->getSSN() == *SSN){
	ssnExists = true;
      }
    }
    
    if(!ssnExists){
      if(!freeAccountNumbers.empty()){
	acc = Account::CreateAccount(customerName, SSN, freeAccountNumbers.top());
	freeAccountNumbers.pop();
      }
      else{
        acc = Account::CreateAccount(customerName, SSN, accountNum++);
      }
      if(acc == nullptr)
	return false;
      
      customers[acc->getAccountNumber()] = acc;

      return true;
    }
    else
      return false;
    
  }
  
  const bool BankLogic::CloseAccount(const int accNum){
    
    if(customers.empty()){
      return false;
    }
    
    if(accNum < accountNum && accNum > -1){
      
      freeAccountNumbers.push(accNum);
      delete customers[accNum];
      customers.erase(accNum);
    }
    else
      return false;  
    return false;
  }
  
  
  const bool BankLogic::CloseAccounts(){
    if(customers.empty()){
      return true;
    }
    
    for(std::unordered_map<int, Account*>::iterator it = customers.begin();
	it != customers.end(); it++){
      freeAccountNumbers.push(it->second->getAccountNumber());
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
      acc->set_balance(it->second->getBalance());
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
      if(accountNum <= accs.accounts(i).accountnum()){
	accountNum = accs.accounts(i).accountnum() + 1;
      }
    }

    int* nums = new int[accountNum];
    
    for(int i = 0; i < accs.accounts_size(); i++){
      nums[accs.accounts(i).accountnum()] = 1;
    }

    for(int i = 0; i < accountNum; i++){
      if(nums[i] != 1){
	freeAccountNumbers.push(i);
      }
    }
    
    delete[] nums;
    return true;
  }
}


