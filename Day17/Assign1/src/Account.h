#pragma once

#include "Conversion.h"
#include <type_traits>
#include "Dollar.h"

template<class T, class C>
class Account{

private:
  T amt;
  C conversion;
  
public:
  Account() = delete;

  Account(T* currency, C* conversion): amt(*currency), conversion(*conversion){}

  template<class J>
  Account(J& acc): amt(acc.amt), conversion(acc.conversion){}

  template<class J>
  Account(J&& acc){
    this->amt = acc.amt;
    this->conversion = acc.conversion;

    acc.amt = 0;
  }
  
  template<class Q>
  T Deposit(Q* dAmt){

    if(!std::is_same<decltype(amt), decltype(*dAmt)>::value){
      if(dAmt->getAmmount() > 0.f){
	T dest;
	
	conversion(dest, *dAmt);
	
	amt.updateAmmount(dest);
	return amt;
      }
      else{
	return this->amt;
      }
    }
    else{
      amt.updateAmmount(*dAmt);
    }
    return this->amt;
  }
  
  template<class Q>
  T Withdraw(Q* wAmt){
    if(!std::is_same<decltype(amt), decltype(*wAmt)>::value){
      if(wAmt->getAmmount() > 0.f){
	T dest;
	
	conversion(dest, *wAmt);
	
	amt.updateAmmount(-1 * dest);
	
	return this->amt;
      }
      else
	return this->amt;
    }
    else
      amt.updateAmmount(-1 * (*wAmt));
    return this->amt;
  }

  template<class R>
  Account<R, C>* Currency(){
    R c;

    conversion(c, amt);
    
    Account<R, C>* acc = new Account<R, C>(&c, &conversion);
    return acc;
  }

  
  Account<T, C>& operator=(Account<T, C>& acc){
    if(this == &acc)
      return *this;

    this->amt = acc.amt;
    this->conversion = acc.conversion;

    return *this;
  }

  Account<T, C>& operator=(Account<T, C>&& acc){

    if(this == &acc)
      return *this;
    
    this->amt = acc.amt;
    this->conversion = acc.conversion;

    acc.amt = 0;

    return *this;
  }

  template<class X>
  bool operator==(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){
      if(this->amt == val)
	return true;
    }
    return false;
  }
  
  template<class X>
  bool operator==(Account<X, C>& acc){
    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      conversion(c, acc.amt);
      
      if(this->amt == c)
	return true;
    }
    else if(this->amt == acc.amt){
      return true;
    }
    return false;  
  }

  template<class X>
  bool operator!=(Account<X, C>& acc){
    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      Conversion(c, acc.amt);
      
      if(c != this->amt)
	return true;
    }
    else if(this->amt != acc.amt){
      return true;
    }
    return false;
  }

  template<class X>
  bool operator<(Account<T, C>& acc){

    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      conversion(c, acc.amt);

      if(this->amt < c)
	return true;
    }
    else if(this->amt < acc.amt)
      return true;
    return false;
  }

  bool operator>(Account<T, C>& acc){
    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      conversion(c, acc.amt);
      
      if(this->amt > c)
	return true;
    }
    else if(this->amt > acc.amt)
      return true;
    return false;
  }

  bool operator<=(Account<T, C>& acc){

    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      conversion(c, acc.amt);
      
      if(this->amt <= c)
	return true;
    }
    else if(this->amt <= acc.amt)
      return true;
    return false;
  }

  bool operator>=(Account<T, C>& acc){

    if(!std::is_same<decltype(*this), decltype(acc)>::value){
      T c;
      conversion(c, acc.amt);
      
      if(this->amt >= c)
	return true;
    }
    else if(this->amt >= acc.amt)
      return true;
    return false;
  }

  template<class X>
  Account<T, C> operator+(const X& val){

    if(!std::is_arithmetic<decltype(val)>::value){
      T c(this->amt);
      c.updateAmmount(val);
      
      Account<T, C> tmp(&c, &this->conversion);

      return tmp;
    }
    return *this;
  }

  template<class X>
  Account<T, C>& operator+=(const X& val){

    if(!std::is_arithmetic<decltype(val)>::value){
      
      this->amt = this->amt + val;
      return *this;
    }
    return *this;
  }

  Account<T, C>& operator++(){
    this->amt = this->amt + 1;
    return *this;
  }

  Account<T, C>& operator++(int val){
    this->amt = this->amt + 1;
    return *this;
  }
  
  template<class X>
  Account<T, C> operator-(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){
      T c(this->amt);
      c.updateAmmount(-1 * val);
      
      Account<T, C> tmp(&c, &this->conversion);

      return tmp;
    }
    return *this;
  }

  template<class X>
  Account<T, C>& operator-=(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){

      this->amt = this->amt - val;
      return *this;
    }
    return *this;
  }

  Account<T, C>& operator--(){
    this->amt = this->amt - 1;
    return *this;
  }

  Account<T, C>& operator--(int val){
    this->amt = this->amt - 1;

    return *this;
  }
  
  template<class X>
  Account<T, C> operator*(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){
      T c(this->amt);
      c.setAmmount(this->amt * val);
      
      Account<T, C> tmp(&c, &this->conversion);

      return tmp;
    }
    return *this;
  }

  template<class X>
  Account<T, C>& operator*=(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){

      this->amt = this->amt * val;
      return *this;
    }
    return *this;
  }

  template<class X>
  Account<T, C> operator/(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){
      T c;
      c.setAmmount(this->amt / val);
      
      Account<T, C> tmp(&c, &this->conversion);

      return tmp;
    }
    return *this;
  }

  template<class X>
  Account<T, C>& operator/=(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){

      this->amt = this->amt / val;
      return *this;
    }
    return *this;
  }

  template<class X>
  Account<T, C> operator%(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){
      T c;
      c.setAmmount(this->amt % val);
      
      Account<T, C> tmp(&c, &this->conversion);

      return tmp;
    }
    return *this;
  }

  template<class X>
  Account<T, C>& operator%=(const X& val){
    if(!std::is_arithmetic<decltype(val)>::value){

      this->amt = this->amt % val;
      return *this;
    }
    return *this;
  }

  template<class X>
  operator X(){
    if(!std::is_same<decltype(this->amt), X>::value){
      X c;
      this->conversion(c, this->amt);
      return c;
    }
    return this->amt;
  }
};
