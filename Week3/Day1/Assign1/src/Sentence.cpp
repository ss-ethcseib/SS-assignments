#include "Sentence.h"

char* Sentence::getSentence(){
    return sentence;
}

int Sentence::num_words() const {
  return offsets.size();
}

std::string Sentence::get_word(const int index){

  if(index < 0 || index >= offsets.size())
    return "\nErr: index out of range\n";
  
  std::string str = "";
  for(int i = offsets[index]; sentence[i] != '\0' && sentence[i] != ' '; i++){
    str += sentence[i];
  }
  return str;
}

void Sentence::replace(char* sent){
  if(sent == nullptr){
    sentence = nullptr;
    return;
  }
  
  if(sentence == nullptr)
    sentence = new char[1];
  strcpy(sentence, sent);
}

std::vector<int> Sentence::getOffsets(){
  return offsets;
}
