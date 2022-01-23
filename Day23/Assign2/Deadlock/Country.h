#pragma once

#include <mutex>

struct Request{
  std::string req, currency;
  float exchangeRate, amt;
};
  
class Country{

private:
  std::mutex m;
  Country* c;
  float dollars;
  float pounds;
  
public:
  Country(): dollars(1000.f), pounds(1000.f){}
  void setCountry(Country* c){
    this->c = c;
  }
  
  void SendRequest(struct Request* req){

    c->ReceivedRequest(req);
  }

  void ReceivedRequest(struct Request* req){

    struct Request reject = {"Reject", "nil", 0.f, 0.f};
    
    if(req->req == "Buy" || req->req == "buy"){
      if(req->currency == "Dollar" || req->currency == "dollar"){

	std::lock_guard<std::mutex> lock1(m);
	std::lock_guard<std::mutex> lock2(c->m);
	if(req->exchangeRate * req->amt < dollars){
	  
	  std::lock_guard<std::mutex> lock3(m);
	  std::lock_guard<std::mutex> lock4(c->m);
	  dollars = dollars - req->exchangeRate * req->amt;
	  
	  struct Request request = {"transfer", req->currency, 0.0f, req->exchangeRate * req->amt};
	  SendRequest(&request);
	}
      }
      else{
	SendRequest(&reject);
      }
    }
    else if(req->req == "Pounds" || req->req == "pounds"){

      std::lock_guard<std::mutex> lock1(m);
      std::lock_guard<std::mutex> lock2(c->m);
      if(req->exchangeRate * req->amt < c->pounds){

	std::lock_guard<std::mutex> lock3(m);
	std::lock_guard<std::mutex> lock4(c->m);
	c->pounds = c->pounds - req->exchangeRate * req->amt;
	
	struct Request request = {"transfer", req->currency, 0.0f, req->exchangeRate * req->amt};
        SendRequest(&request);
      }
      else{
	SendRequest(&reject);
      }
    }
    else if(req->req == "Sell" || req->req == "sell"){
      if(req->currency == "Dollars" || req->currency == "dollars"){

	std::lock_guard<std::mutex> lock1(m);
	std::lock_guard<std::mutex> lock2(m);
	if(dollars > req->exchangeRate * req->amt){

	  std::lock_guard<std::mutex> lock3(m);
	  std::lock_guard<std::mutex> lock4(c->m);
	  dollars -= req->exchangeRate * req->amt;

	  struct Request request = {"transfer", req->currency, 0.f, req->exchangeRate * req->amt};

	  SendRequest(&request);
	}
	else
	  SendRequest(&reject);
      }
      else if(req->currency == "Pounds" || req->currency == "pounds"){

	std::lock_guard<std::mutex> lock1(m);
	std::lock_guard<std::mutex> lock2(c->m);
	if(pounds > req->exchangeRate * req->amt){

	  std::lock_guard<std::mutex> lock3(m);
	  std::lock_guard<std::mutex> lock4(c->m);
	  pounds -= req->exchangeRate * req->amt;
	  struct Request request = {"transfer", req->currency, 0.f, req->exchangeRate * req->amt};
	  SendRequest(&request);
	}
	else
	  SendRequest(&reject);
      }
    }
    else if(req->req == "transfer" || req->req == "Transfer"){
      if(req->currency == "Dollar" || req->currency == "dollar"){

	std::lock_guard<std::mutex> lock1(m);
	std::lock_guard<std::mutex> lock2(c->m);
	if(req->amt > 0.f){
	  std::lock_guard<std::mutex> lock3(m);
	  std::lock_guard<std::mutex> lock4(c->m);
	  dollars += req->amt;
	}
      }
      else if(req->currency == "Pounds" || req->currency == "pounds"){

	std::lock_guard<std::mutex> lock1(m);
	std::lock_guard<std::mutex> lock2(c->m);
	if(req->amt > 0.f){
	  std::lock_guard<std::mutex> lock2(m);
	  std::lock_guard<std::mutex> lock4(c->m);
	  pounds += req->amt;
	}
      }
    }
  }
};
