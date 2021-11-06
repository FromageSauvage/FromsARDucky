//Valentin Rossignol (Rossignol.inc "FromageSauvage")
//6 novembre 2021
//Rubber ducky Arduboy

#include <Arduboy2.h>
Arduboy2 arduboy;
unsigned char select = 1;
int ypos = 0;
unsigned char loading = 0;
unsigned char state = 0;
unsigned char scriptamount = 6;
String title;


void selectmenu() {

  if(arduboy.pressed(DOWN_BUTTON)){
    select = select + 1;
    ypos = ypos - 15;
    delay(200);
  }

  if(arduboy.pressed(UP_BUTTON)){
    select = select -  1;
    ypos = ypos + 15;
    delay(200);
  }

  arduboy.setCursor(5,5);
  arduboy.print(">");

  arduboy.setCursor(105,5);
  arduboy.print(select);
  arduboy.print("/");
  arduboy.print(scriptamount);
  arduboy.setCursor(15,ypos+5);
  arduboy.print("Keyboard");
  arduboy.setCursor(15,ypos+20);
  arduboy.print("Mouse");
  arduboy.setCursor(15,ypos+35);
  arduboy.print("Run programs");
  arduboy.setCursor(15,ypos+50);
  arduboy.print("Keystrokes");
  arduboy.setCursor(15,ypos+65);
  arduboy.print("Miscellaneous");
  arduboy.setCursor(15,ypos+80);
  arduboy.print("Turn Off");

  if(select<1){
    select = select + 1;
  }
  else if(select>scriptamount){
    select = select - 1;
  }
  
  if(ypos<-(scriptamount-1)*15){
    ypos = ypos + 15;
  }
  else if(ypos>0){
    ypos = ypos - 15;
  }
}

void prelaunch() {
  arduboy.setCursor(10,10);
  arduboy.print("Are you sure to launch");
  
}

void runloop() {
  switch (state){
    case 0:
      selectmenu();
      break;

    case 1:
      prelaunch();
      break;
  }
}

void setup() {
  
  arduboy.begin();
  arduboy.clear();
  arduboy.print(" \n  From's atmega32u4\n  Rubber ducky\n \n  BETA VERSION");
  arduboy.display();
  delay(3000);
  arduboy.clear();
  arduboy.display();
  delay(100);
  
  while(loading < 100){
    arduboy.clear();
    arduboy.print("Loading : ");
    arduboy.print(loading);
    arduboy.print("%");
    loading = loading + 1;
    delay(5);
    arduboy.display();
  }
  
}

void loop() {
  arduboy.clear();
  runloop();
  arduboy.display();
}
