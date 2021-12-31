#include "gtest/gtest.h"
#include "Calendar.h"

void DeleteCalendar(int** calendar){
  if(calendar == nullptr)
    return;
  
  int i = 0;
  while(calendar[i] != nullptr){
    delete[] calendar[i];
    i++;
  }
  delete calendar;
}

bool CompareCalendars(int** calendar1, int** calendar2){

  int index = 0;
  int* it1 = nullptr;
  int* it2 = nullptr;
  
  while(it1 != nullptr && it2 != nullptr){
    
    it1 = calendar1[index];
    it2 = calendar2[index];
    
    for(int i = 0; i < 7; i++){
      
      if(*it1 != *it2){
	
        return false;	
      } 
    }
  }

  return true;
}

int** CreateDecemberCalendar(){
  int** calendar = new int*[6];
  
  for(int i = 0; i < 5; i++){
    
    calendar[i] = new int[7]; 
  }
  calendar[5] = nullptr;
  
  int index = 0;
  int dayCount = 31;
  int day = 3;
  
  if(day != 0){
    
    for(int x = 0; x < day; x++){
      
      calendar[0][x] = -1; 
    }  
  }
  
  for(int i = 0; i < dayCount; i++){
    
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
  return calendar;
}


TEST(Constructor_Test, Proper_Month_Year_Given){
  
  Calendar cal(11, 2021);
  int** calendar1 = cal.get();
  int** calendar2 = CreateDecemberCalendar();
  
  bool check = CompareCalendars(calendar1, calendar2);
  
  DeleteCalendar(calendar2);
  
  ASSERT_EQ(true, check);
}

TEST(Constructor_Test, Bad_Month_Given){
  Calendar cal(90, 2021);
  if(cal.get() == nullptr)
    SUCCEED();
  else
    FAIL();
}

TEST(Constructor_Test, Bad_Year_Given){
  Calendar cal(11, -2021);
  
  if(cal.get() == nullptr)
    SUCCEED();
  else
    FAIL();
}

TEST(Set_Tests, Expected_Parameters_Given){
  Calendar cal(10, 2021);
  cal.set(11, 2021);
  int** calendar1 = cal.get();
  int** calendar2 = CreateDecemberCalendar();
  
  bool check = CompareCalendars(calendar1, calendar2);

  DeleteCalendar(calendar2);
  
  ASSERT_EQ(true, check);
}

TEST(Set_Tests, Bad_Month_Given){
  Calendar cal(11, 2021);
  cal.set(-1, 2021);

  int** calendar1 = cal.get();
  int** calendar2 = CreateDecemberCalendar();

  bool check = CompareCalendars(calendar1, calendar2);

  DeleteCalendar(calendar2);

  ASSERT_EQ(true, check);
}

TEST(Set_Tests, Bad_Year_Given){
  Calendar cal(11, 2021);
  cal.set(11, -2021);

  int** calendar1 = cal.get();
  int** calendar2 = CreateDecemberCalendar();

  bool check = CompareCalendars(calendar1, calendar2);

  DeleteCalendar(calendar2);

  ASSERT_EQ(true, check);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
