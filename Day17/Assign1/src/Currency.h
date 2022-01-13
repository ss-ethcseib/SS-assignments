#pragma once

class Currency{

protected:
  float amt;
  
public:
  Currency(): amt(0.f){}
  Currency(const float f): amt(f){}
  Currency(const Currency& cur): amt(cur.amt){}
  Currency(Currency&& cur){
    amt = cur.amt;
    cur.amt = 0;
  }

  virtual void operator=(const Currency& cur){
    if(this != &cur)
      this->amt = cur.amt;
  }

  virtual void operator=(Currency&& cur){
    if(this == &cur)
      return;

    this->amt = cur.amt;
    cur.amt = 0;
  }
  
  virtual void setAmmount(float f){
    amt = f;
  }
  
  virtual void updateAmmount(float f){
    amt += f;
  }

  virtual float getAmmount(){
    return amt;
  }
  
  virtual operator float(){
    return amt;
  }
};
