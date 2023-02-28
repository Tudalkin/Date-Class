#include <iostream>
#include "Date.h"
using namespace std;

//set functions
void Date::setDate(int m, int d, int y){
  month=m;
  day=d;
  year=y;
}
void Date::setMonth(int m){
  month=m;
}
void Date::setDay(int d){
  day=d;
}
void Date::setYear(int y){
  year=y;
}

//get functions
int Date::getMonth()const{
  return month;
}
int Date::getDay()const{
  return day;
}
int Date::getYear()const{
  return year;
}
int Date::getDaysInMonth(){
  int numDays;

  switch(month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      numDays=31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      numDays=30;
      break;
    case 2:
      if (isLeapYear())
        numDays=29;
      else
        numDays=28;
  }
  return numDays;
}

bool Date::isLeapYear(){
  if ((year%4==0)&&(year%100!=0)||(year%400==0))
    return true;
  else
    return false;
}

int Date::numberOfDaysPassed(){
  int sumDays=0;
  for(int i=1; i<month;i++)
    sumDays=sumDays+monthArr[i];
  if(isLeapYear() &&month>2)
    sumDays=sumDays+day+1;
  else
    sumDays=sumDays+day;  
  return sumDays;
}
int Date::numberOfDaysLeft(){
  if(isLeapYear())
    return 366-numberOfDaysPassed();
  else
    return 365-numberOfDaysPassed();
}
void Date::incrementDate(int nDays){
  int daysLeftInMonth;
  daysLeftInMonth = monthArr[month]-day;

  if (daysLeftInMonth>=nDays)
    day=day+nDays;
  else{
    day=1;
    month++;
    nDays =nDays-(daysLeftInMonth+1);
    while(nDays>0)
      if(nDays>=monthArr[month]){
        nDays=nDays-monthArr[month];
        if ((month==2)&&isLeapYear())
          nDays--;
        month++;
        if (month>12){
          month=1;
          year++;
        }
      }
      else{
        day=day+nDays;
        nDays=0;
      }
  }
}
Date::Date(int m,int d,int y){
  month=m;
  day=d;
  year=y;
  switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if(1<=day&&day<=31)
        day=day;
      else
        day=1;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if(1<=day&&day<=30)
        day=day;
      else
        day=1;
      break;
    case 2:
      if (isLeapYear()){
        if(1<=day&&day<=29)
        day=day;
        else
          day=1;
      }
      else{
        if(1<=day&&day<=28)
        day=day;
      else
        day=1;

      }
  }
}
