#pragma once

template<typename T>
class myvector {
private:
  T* mData; // this is the actual data (or array)
  int mSize; // Size is how much data.  Capacity is how much memory.
  int mCapacity; // not always same as mSize, usually much larger than mSize.
  T mUndefined;// Lots of STL functions say that doing something naughty gets "undefined behavior".

public:
  myvector(): mData(new T[16]), mSize(0), mCapacity(16) {}
  myvector(const T* data, const int sz): mData(data), mSize(sz), mCapacity(sz) {} // creates a vector of sz elements

  virtual ~myvector() {

    if(mData != nullptr)
      delete[] mData;
  }
  
  myvector(const myvector<T>& other) {
    mData = new T[other.mSize];
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    mUndefined = other.mUndefined;
    
    for(int i = 0; i < other.mSize; i++)
      mData[i] = other.mData[i];
  }
  
  myvector(myvector<T>&& other) noexcept(false){
    mData = other.mData;
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    mUndefined = other.mUndefined;

    other.mData = nullptr;
    other.mSize = 0;
    other.mCapacity = 0;
  }

  myvector& operator=(myvector<T>& other) {

    this->mSize = other.mSize;
    this->mCapacity = other.mCapacity;
    this->mUndefined = other.mUndefined;

    this->mData = new T[this->mSize];

    for(int i = 0; i < this->mSize; i++)
      this->mData[i] = other.mData[i];
    
    return *this;
  }
  
  bool operator==(const myvector<T>& other) {

    if(this->mSize != other.mSize)
      return false;
    
    for(int i = 0; i < this->mSize; i++){
      if(this->mData[i] != other.mData[i])
	return false;
    }
    
    return true;
  }
  
  T& operator[](int offset) {
    if(offset > -1 && offset < this->mSize)
      return this->mData[offset];
    return mUndefined;
  }
  
  void push_back(const T& t) {

    if(mSize != mCapacity - 1){
      mData[mSize] = t;
      mSize++;
      return;
    }

    mCapacity *= 2;
    T* tmp = new T[mCapacity];

    int i = 0;
    for(; i < mSize; i++){
      tmp[i] = mData[i];
    }

    tmp[i] = t;

    delete[] mData;

    mData = tmp;
    mSize++;
  }
  
  void pop_back() {
    mSize--;//research more
  }
  
  T& at(int offset) {

    if(offset > -1 && offset < mSize)
      return mData[offset];
    return mUndefined;
  }
  
  void clear() {
    delete[] mData;

    mSize = 0;
    mCapacity = 16;
    
    mData = new T[mCapacity];
  }
  
  int size() const {
    
    return mSize;
  }
  
  void reserve(unsigned int tCount) {

    if(tCount > mCapacity){
      T* tmp = new T[tCount];
      
      for(int i = 0; i < mSize; i++){
	tmp[i] = mData[i];
      }
      
      delete[] mData;
      mData = tmp;

      mCapacity = tCount;
    }
  } // use an algorithm to increase capacity as required

  int capacity() const {return mCapacity;}

  // iterator
  struct iterator {

    using iterator_category = std::bidirectional_iterator_tag;
    using different_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    //friend myvector;
    
    pointer it;
    
  public:

    iterator(): it(nullptr) {}
    iterator(pointer myvec): it(myvec) {}

    reference operator++() {
      ++this->it;
      return *this;
    }
    
    iterator operator++(int i){
      iterator tmp = *this;
      this->it++;
      return tmp;
    }
    
    reference operator--() {
      --this->it;
      return *this;
    }
    
    iterator operator--(int i) {
      iterator tmp = *this;
      this->it--;
      return tmp;
    }
    
    bool operator==(const iterator& it){
      return this->it == it.it;
    }
    
    bool operator!=(const iterator& it){
      return this->it != it.it;
    }

    reference operator*(){
      return *(this->it);
    }

    pointer operator->(){
      return this->it;
    }
  };
  
  iterator begin() const {
    return iterator(&mData[0]);
  }
  
  iterator end() const {
    return iterator(&mData[mSize]);
  }
};
