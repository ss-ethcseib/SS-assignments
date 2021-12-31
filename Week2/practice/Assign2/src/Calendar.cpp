#include "Calendar.h"

int Calendar::days[] = {31, 28, 31, 30,
		  31, 30, 31, 31,
		  30, 31, 30, 31};

int** Calendar::get() const{
  if(calendar == nullptr){
    return nullptr;
  }
  
  return calendar;
}

void Calendar::print() const{

  if(calendar == nullptr)
    return;
  
  int i = 0;
  while(calendar[i] != nullptr){
    for(int x = 0; x < 7; x++){
      std::cout << "Day: " << calendar[i][x] << std::endl;
    }
    i++;
  }
}

void Calendar::set(int month, int year){

  if(month > 11 || month < 0 || year < 0){
    return;
  }
  double yearCheck1 = (double)year/4;
  int yearCheck2 = (int)(year/4);
  int dayCount = days[month];
  
  if(month == 1 && yearCheck1 == yearCheck2)  
    dayCount++;
  
  std::tm tm;                                                               
  tm.tm_year = year - 1900;
  tm.tm_mon = month;
  tm.tm_mday = 1;
  tm.tm_isdst = -1;
  tm.tm_sec = 0;
  tm.tm_min = 0;
  tm.tm_hour = 0;

  
  std::time_t t = std::mktime(&tm);
  std::tm* local = std::localtime(&t);
  int weeksNum = std::ceil((float)(dayCount + local->tm_wday) / 7);

  calendar = new int*[weeksNum + 1];
  calendar[weeksNum] = nullptr;

  for(int i = 0; i < weeksNum; i++){
    calendar[i] = new int[7];   
  }
  
  int index = 0;
  int day = local->tm_wday;

  if(day != 0){
    for(int x = 0; x < day; x++){
      calendar[0][x] = -1;
    }
  }
  
  int i = 0;
  
  for(; i < dayCount; i++){
    calendar[index][day % 7] = i + 1;
    day++;

    if(day != 0 && day % 7 == 0){
      index++;
    }
  }
  
  while(day != 0 && day % 7 != 0){
    
    calendar[index][day % 7] = -1;
    day++;
  }
}
