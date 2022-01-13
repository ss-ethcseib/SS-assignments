#pragma once

#include "Dollar.h"
#include "Euro.h"
#include "Pound.h"
#include "Yen.h"
#include <iostream>
class Conversion{

 public:
  
  Conversion(){}
  //If I comment out my code from here to where it says stop it
  //breaks my program and I can't figure out why. Would like to
  //get rid of these operators because they are a waste of performance.
  Currency& operator()(Euro& dest, Euro& src){
    dest = src;
    std::cout <<"\nEuro\n";
    return dest;
  }

  Currency& operator()(Dollar& dest, Dollar& src){
    dest = src;
    std::cout << "\nDollar\n";
    return dest;
  }

  Currency& operator()(Yen& dest, Yen& src){
    dest = src;
    std::cout << "\nYen\n";
    return dest;
  }

  Currency& operator()(Pound& dest, Pound& src){
    dest = src;
    std::cout << "\nPound\n";
    return dest;
    }

  //STOP HERE


  
  Currency& operator()(Dollar& dest, Euro& src){
    dest.setAmmount(src.getAmmount() * 1.15f);
    return dest;
  }

  Currency& operator()(Dollar& dest, Yen& src){

    dest.setAmmount(src.getAmmount() / 114.14f);
    return dest;
  }

  Currency& operator()(Dollar& dest, Pound& src){
    dest.setAmmount(src.getAmmount() / 0.73f);
    return dest;
  }
  
  Currency& operator()(Euro& dest, Dollar& src){
    dest.setAmmount(src.getAmmount() * 0.869565f);
    return dest;
  }

  Currency& operator()(Euro& dest, Pound& src){
    dest.setAmmount(src.getAmmount() / 0.84f);
    return dest;
  }

  Currency& operator()(Euro& dest, Yen& src){
    dest.setAmmount(src.getAmmount() / 130.80f);
    return dest;
  }

  Currency& operator()(Pound& dest, Dollar& src){
    dest.setAmmount(src.getAmmount() * 0.73f);
    return dest;
  }

  Currency& operator()(Pound& dest, Euro& src){
    dest.setAmmount(src.getAmmount() * 0.84f);
    return dest;
  }

  Currency& operator()(Pound& dest, Yen& src){
    dest.setAmmount(src.getAmmount() / 156.52f);
    return dest;
  }

  Currency& operator()(Yen& dest, Dollar& src){

    dest.setAmmount(src.getAmmount() * 144.14f);
    return dest;
  }

  Currency& operator()(Yen& dest, Euro& src){
    dest.setAmmount(src.getAmmount() * 130.80f);
    return dest;
  }

  Currency& operator()(Yen& dest, Pound& src){
    dest.setAmmount(src.getAmmount() * 156.52f);
    return dest;
  }
};
