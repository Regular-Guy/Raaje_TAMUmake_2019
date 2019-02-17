#include <LiquidCrystal.h>

//initalize the LCD library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//get day time
long long int hour;
long long int minute;
long long int second;
long long int alarmHour;
long long int alarmMinute;
bool alarmOff = false;


void setup() {
  lcd.begin(16, 2);

  
  hour = 0;
  minute = 0;
  second = 0;
  alarm hour = 0;
  alarmMinute = 30;
  bool alarmOff = false;
}

void loop() {
  //get day time
  long long int hour;
  long long int minute;
  long long int second;

  long long int alarmHour;
  long long int alarmSeconds;
  bool alarmOff = false;


  second++

  if(second > 60){
    minute++;
    second = 0;
  }
  if(minute > 60){
    hour++;
    minute = 0;
  }
  if( hour > 24){
    hour = 0;
  }

  if(hour >= alarmHour && minute >= alarmMinute && !alarmOff){
    alert
  }
  seconds++;
}

function
