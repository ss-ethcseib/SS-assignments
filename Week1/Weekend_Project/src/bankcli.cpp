#include <iostream>
#include <string>
#include <curses.h>

//ideas: Create a map to store usernames as keys and structs with info as values. 
std::string getPassword(char);

int main(int argc, char** args){

  std::string username = "";
  std::string password = "";
  
  std::cout << "Username: ";
  std::cin >> username;

  std::cout << "Password: ";
  std::cin >> password;
  //password = getPassword('*');

  
  return 0;
}

std::string getPassword(char sp = '*'){

  std::string passwd = "";
  char input = '';

  while(true){
    input = getch();

    if(input == KEY_ENTER){
      std::cout << std::endl;
      return passwd;
    }
    else if(input == KEY_BACKSPACE && passwd.length() != 0){
      passwd.pop_back();
      std::cout << "\b \b";
      continue;
    }
    else if(input == KEY_BACKSPACE && passwd.length() == 0){
      continue;
    }

    passwd.push_back(input);
    std::cout << sp;
  }
}
