#pragma once

template<typename T>
class myvector {
private:
  T* mData; // this is the actual data (or array)
  int mSize; // Size is how much data.  Capacity is how much memory.
  int mCapacity; // not always same as mSize, usually much larger than mSize.
  T mUndefined;// Lots of STL functions say that doing something naughty gets "undefined behavior".

public:
  myvector() noexcept(true): mData(new T[16]), mSize(0), mCapacity(16) {}
  myvector(const T* data, const int sz) noexcept(true): mData(data), mSize(sz), mCapacity(sz) {} // creates a vector of sz elements

  virtual ~myvector() noexcept(false){

    if(mData != nullptr)
      delete[] mData;
  }
  
  myvector(const myvector<T>& other) noexcept(true){
    mData = new T[other.mSize];
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    mUndefined = other.mUndefined;
    
    for(int i = 0; i < other.mSize; i++)
      mData[i] = other.mData[i];
  }
  
  myvector(myvector<T>&& other) noexcept(true):
    mData(std::exchange<T*>(other.mData, nullptr)),
    mSize(std::exchange(other.mSize, 0)),
    mCapacity(std::exchange(other.mCapacity, 0)),
    mUndefined(other.mUndefined) {}

  myvector& operator=(myvector<T>&& other){

    if(this != &other){
      this->mSize = std::exchange(other.mSize, 0);
      this->mCapacity = std::exchange(other.mCapacity, 0);
      this->mUndefined = other.mUndefined;
      this->mData = std::exchange<T*>(other.mData, nullptr);
    }
    return *this;
  }
  
  myvector& operator=(const myvector<T>& other) noexcept(false){

    if(this != & other){
      this->mSize = other.mSize;
      this->mCapacity = other.mCapacity;
      this->mUndefined = other.mUndefined;
      
      this->mData = new T[this->mSize];
      
      for(int i = 0; i < this->mSize; i++)
	this->mData[i] = other.mData[i];
    }
    return *this;
  }
  
  bool operator==(const myvector<T>& other) noexcept(false){

    if(this->mSize != other.mSize)
      return false;
    
    for(int i = 0; i < this->mSize; i++){
      if(this->mData[i] != other.mData[i])
	return false;
    }
    
    return true;
  }
  
  T& operator[](const unsigned int offset) noexcept(false){
    if(offset < this->mSize)
      return this->mData[offset];
    return mUndefined;
  }

  void push_back(const T& t) noexcept(false){

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

  void push_back(T&& t) noexcept(false) {
    
    if(mSize != mCapacity - 1){
      mData[mSize] = std::move(t);
      mSize++;
      return;
    }

    mCapacity *= 2;
    T* tmp = new T[mCapacity];

    int i = 0;
    for(; i < mSize; i++){
      tmp[i] = std::move(mData[i]);
    }

    tmp[i] = std::move(t);

    delete[] mData;

    mData = tmp;
    mSize++;
  }
  
  void pop_back() noexcept(true){
    mSize--;//research more
  }
  
  T& at(const unsigned int offset) noexcept(false){

    if(offset < mSize)
      return mData[offset];
    return mUndefined;
  }
  
  void clear() noexcept(false){
    delete[] mData;

    mSize = 0;
    mCapacity = 16;
    
    mData = new T[mCapacity];
  }
  
  int size() const noexcept(true){
    
    return mSize;
  }
  
  void reserve(const unsigned int tCount) noexcept(false){

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

  int capacity() const noexcept(true){
    return mCapacity;
  }

  // iterator
  struct iterator {

    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    pointer it;
    
  public:

    iterator() noexcept(true): it(nullptr) {}
    iterator(pointer myvec) noexcept(false): it(myvec) {}

    reference operator++() noexcept(true){
      ++this->it;
      return *this;
    }
    
    iterator operator++(int i) noexcept(true){
      iterator tmp = *this;
      this->it++;
      return tmp;
    }
    
    reference operator--() noexcept(true){
      --this->it;
      return *this;
    }
    
    iterator operator--(int i) noexcept(true){
      iterator tmp = *this;
      this->it--;
      return tmp;
    }
    
    bool operator==(const iterator& it) noexcept(true){
      return this->it == it.it;
    }
    
    bool operator!=(const iterator& it) noexcept(true){
      return this->it != it.it;
    }

    reference operator*() noexcept(true){
      return *(this->it);
    }

    pointer operator->() noexcept(true){
      return this->it;
    }
  };
  
  iterator begin() const noexcept(false){
    return iterator(&mData[0]);
  }
  
  iterator end() const noexcept(false){
    return iterator(&mData[mSize]);
  }
};
