//Valentin Rossignol (Rossignol.inc "FromageSauvage")
//6 novembre 2021
//Rubber ducky Arduboy

#include <Arduboy2.h>
#include <Mouse.h>
#include <Keyboard.h>
#include "Tinyfont.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

int etatbarre = LOW;
unsigned long previousMillis = 0;
const long interval = 250;  

unsigned char select = 1;
int ypos = 0;
unsigned char loading = 0;
unsigned char state = 0;
unsigned char scriptamount = 8;
bool bootscreen = 0;
String title;
bool mode = 0;
bool stopper = 0;

void selectmenu() {

  if (arduboy.pressed(DOWN_BUTTON)) {
    select = select + 1;
    ypos = ypos - 15;
    delay(200);
  }

  if (arduboy.pressed(UP_BUTTON)) {
    select = select -  1;
    ypos = ypos + 15;
    delay(200);
  }

  if (arduboy.pressed(B_BUTTON)) {
    arduboy.clear();
    state = select;
    delay(200);
  }

  arduboy.setCursor(5, 5);
  arduboy.print(">");

  arduboy.setCursor(105, 5);
  arduboy.print(select);
  arduboy.print("/");
  arduboy.print(scriptamount);
  arduboy.setCursor(15, ypos + 5);
  arduboy.print("Keyboard");
  arduboy.setCursor(15, ypos + 20);
  arduboy.print("Mouse");
  arduboy.setCursor(15, ypos + 35);
  arduboy.print("Run programs");
  arduboy.setCursor(15, ypos + 50);
  arduboy.print("Keystrokes");
  arduboy.setCursor(15, ypos + 65);
  arduboy.print("Set email");
  arduboy.setCursor(15, ypos + 80);
  arduboy.print("Payloads");
  arduboy.setCursor(15, ypos + 95);
  arduboy.print("HID specs");
  arduboy.setCursor(15, ypos + 110);
  arduboy.print("Turn Off");

  if (select < 1) {
    select = select + 1;
  }
  else if (select > scriptamount) {
    select = select - 1;
  }

  if (ypos < -(scriptamount - 1) * 15) {
    ypos = ypos + 15;
  }
  else if (ypos > 0) {
    ypos = ypos - 15;
  }
}

void runloop() {
  switch (state) {
    case 0:
      selectmenu();
      break;

    case 1:
      keyboardloop();
      break;

    case 2:
      mouseloop();
      break;

    case 3:
      programsloop();
      break;

    case 4:
      emailloop();
      break;

    case 5:
      emailloop();
      break;

    case 6:
      emailloop();
      break;

    case 7:
      emailloop();
      break;

    case 8:
      emailloop();
      break;
  }
}

void setup() {
  arduboy.begin();
  arduboy.clear();
  while((arduboy.notPressed(LEFT_BUTTON))&&(arduboy.notPressed(RIGHT_BUTTON))&&(arduboy.notPressed(UP_BUTTON))&&(arduboy.notPressed(DOWN_BUTTON))&&(arduboy.notPressed(A_BUTTON))&&(arduboy.notPressed(B_BUTTON)))
  {
    if(bootscreen == 0){
      arduboy.setCursor(0,5);
      arduboy.print(" From's atmega32u4\n Rubber ducky\n \n FromageSauvage 2021\n \n \n Press any key >>>");
      arduboy.drawRoundRect(0,0,128,64,5,1);
      arduboy.display();
      bootscreen = 1;
    }
  }
  arduboy.clear();
  arduboy.display();
  delay(200);

  while (loading < 100) {
    arduboy.clear();
    arduboy.drawLine(10,10+7,60,10+7,1);
    arduboy.setCursor(10,10);
    arduboy.print("Loading : ");
    arduboy.print(loading);
    arduboy.print("%");
    loading = loading + 1;
    delay(2);
    arduboy.display();
  }

}

void loop() {
  arduboy.clear();
  runloop(); // DONT FORGET TO CHANGE THIS TO RUNLOOP();
  arduboy.display();
}
