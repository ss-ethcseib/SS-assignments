#pragma once

#include <vector>
#include <string.h>
#include <iostream>

class Sentence{

 private:
  std::vector<int> offsets;
  char* sentence;

 public:
  
  char* getSentence();
  int num_words() const;
  std::string get_word(int);
  void replace(char*);
  std::vector<int> getOffsets();
  
  ~Sentence(){
    if(sentence != nullptr)
      delete[] sentence;
  }

  Sentence(){
    sentence = nullptr;
  }
  
  Sentence(char* sent){

    if(sent != nullptr){
      bool swap = true;
      for(int i = 0; sent[i] != '\0'; i++){

	if(sent[i] != ' ' && swap){
	  offsets.push_back(i);
	  swap = false;
	}
	else if(sent[i] == ' ' && !swap){
	  swap = true;
	}
      }
      sentence = new char[1];
      strcpy(sentence, sent);
    }
    else
      sentence = nullptr;
  }
  
  Sentence(Sentence* sent){
    if(sent != nullptr){
      this->sentence = new char[1];
      strcpy(this->sentence, sent->sentence);
      this->offsets = sent->offsets;
    }
    else{
      sentence = nullptr;
    }
  }

  Sentence(Sentence&& sent){
    this->sentence = sent.sentence;
    this->offsets = sent.offsets;
    sent.sentence = nullptr;  
  }
  
  void operator= (Sentence& sent)
  {
    if(this->sentence == nullptr)
      this->sentence = new char[1];
    strcpy(this->sentence, sent.sentence);
    this->offsets = sent.offsets;
  }

  void operator= (Sentence&& sent){

    this->sentence = sent.sentence;
    this->offsets = sent.offsets;
    sent.sentence = nullptr;
  }
};
