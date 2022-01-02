//Valentin Rossignol (Rossignol.inc "FromageSauvage")
//6 novembre 2021
//Human interface device

//English
//NOTES : If the program interfere with your real mouse/keyboard, reset the arduboy or unplug your mouse/keyboard.
//known issue : The mouse.ino program may lag a lot. If it does, just unplug an replug the arduboy or reset it
//btw (only for english users) make sure that you've set your pc for "French" keyboards (azerty) or the program will not work correctly.

//Français
//NOTES : Si le programme interfère avec votre vraie souris/clavier, redémarrez votre console avec le bouton reset ou débranchez la.
//Bug connu : Le programme mouse.ino pourrait beaucoup lagger. Si c'est le cas débranchez puis rebranchez la console ou redémarrez la.

unsigned char version = 1;

#include <Arduboy2.h> //déclaration des librairies
#include <Mouse.h>
#include <Keyboard.h>
#include "Tinyfont.h"

Arduboy2 arduboy; //arduboy
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height()); //Prérequis pour la librairie Tinyfont



unsigned char select = 1; //variables utiles pour "ArduboyHID.ino"
int ypos = 0;
unsigned char loading = 0;
unsigned char state = 0;
unsigned char scriptamount = 4;

bool bootscreen = 0; //variables pour les autres programmes
bool mode = 0;



void selectmenu() { //Menu principal

  //navigation dans le menu principal

  if (arduboy.pressed(DOWN_BUTTON)) { //Bouton bas
    select = select + 1;
    ypos = ypos - 15;
    delay(200);
  }

  if (arduboy.pressed(UP_BUTTON)) { //Bouton haut
    select = select -  1;
    ypos = ypos + 15;
    delay(200);
  }

  if (arduboy.pressed(B_BUTTON)) { //Bouton B
    arduboy.clear();
    state = select;
    ypos = 0;
    delay(200);
  }

  //Affichage sur l'écran

  arduboy.setCursor(5, 5);
  arduboy.print(">");

  arduboy.setCursor(105, 5);
  arduboy.print(select);
  arduboy.print("/");
  arduboy.print(scriptamount);

  arduboy.setCursor(105, 50);
  arduboy.print("B >");

  arduboy.setCursor(15, ypos + 5);
  arduboy.print("Keyboard");
  arduboy.setCursor(15, ypos + 20);
  arduboy.print("Mouse");
  arduboy.setCursor(15, ypos + 35);
  arduboy.print("Keybinds");
  arduboy.setCursor(15, ypos + 50);
  arduboy.print("HID specs");
  
  //Limites du curseur

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



void runloop() { //Boucle principale

  switch (state) {
    case 0:
      selectmenu(); //Menu principal
      break;

    case 1:
      keyboardloop(); //Clavier
      break;

    case 2:
      mouseloop(); //Souris
      break;

    case 3:
      keybinds(); //Combinaisons de touches
      break;

    case 4:
      specsloop(); //specs de la Human intaface device
      break;
  }
}



void setup() { //setup

  arduboy.begin(); //lancement d'arduboy
  arduboy.clear();

  //écran de boot, test des touches
  while((arduboy.notPressed(LEFT_BUTTON))&&(arduboy.notPressed(RIGHT_BUTTON))&&(arduboy.notPressed(UP_BUTTON))&&(arduboy.notPressed(DOWN_BUTTON))&&(arduboy.notPressed(A_BUTTON))&&(arduboy.notPressed(B_BUTTON)))
  {
    if(bootscreen == 0){ //écran de boot
      arduboy.setCursor(0,5);
      arduboy.print(" From's atmega32u4\n HID\n \n FromageSauvage 2021\n \n \n Press any key >>>");
      arduboy.drawRoundRect(0,0,128,64,5,1);
      arduboy.display();
      bootscreen = 1;
    }
  }

  arduboy.clear(); //réinitialisation de l'affichage
  arduboy.display(); //actualisation de l'affichage
  delay(200); //pause

  while (loading < 100) { //écran de chargement (facultatif)
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



void loop() { //loop
  arduboy.clear();
  runloop(); // DONT FORGET TO CHANGE THIS TO RUNLOOP();
  arduboy.display();
}
