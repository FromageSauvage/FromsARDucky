 //routine des combinaisons de frappes

unsigned char combinaison = 0;
unsigned char keybindamount = 13; //IL FAUT PENSER A DEFINIR CETTE VARIABLE EN FONCTION DU NOMBRE DE KEYBINDS
unsigned char keybindselect = 1;
unsigned char keybind = 0;

void keybindsloop()
{
  if (arduboy.pressed(DOWN_BUTTON)) { //Bouton bas
    keybindselect = keybindselect + 1;
    ypos = ypos - 15;
    delay(200);
  }

  if (arduboy.pressed(UP_BUTTON)) { //Bouton haut
    keybindselect = keybindselect -  1;
    ypos = ypos + 15;
    delay(200);
  }

  if (arduboy.pressed(B_BUTTON)) { //Bouton B
    arduboy.clear();
    keybind = keybindselect;
    delay(200);
  }

  if (arduboy.pressed(A_BUTTON)) { //Bouton A
    arduboy.clear();
    select = 1;
    ypos = 0;
    state = 0;
    delay(200);
  }

  //affichage sur l'écran
  
  arduboy.setCursor(5, 5);
  arduboy.print(">");

  arduboy.setCursor(97, 5);
  arduboy.print(keybindselect);
  arduboy.print("/");
  arduboy.print(keybindamount);

  arduboy.setCursor(104, 40);
  arduboy.print("< A");
  arduboy.setCursor(105, 50);
  arduboy.print("B >");

  arduboy.setCursor(15, ypos + 5);
  arduboy.print("ctrl+c");
  arduboy.setCursor(15, ypos + 20);
  arduboy.print("ctrl+v");
  arduboy.setCursor(15, ypos + 35);
  arduboy.print("ctrl+z");
  arduboy.setCursor(15, ypos + 50);
  arduboy.print("ctrl+y");
  arduboy.setCursor(15, ypos + 65);
  arduboy.print("win+m");
  arduboy.setCursor(15, ypos + 80);
  arduboy.print("win+shift+m");
  arduboy.setCursor(15, ypos + 95);
  arduboy.print("ctrl+shift+esc");
  arduboy.setCursor(15, ypos + 110);
  arduboy.print("win+downarrow");
  arduboy.setCursor(15, ypos + 125);
  arduboy.print("alt+f4");
  arduboy.setCursor(15, ypos + 140);
  arduboy.print("ctrl+alt+del");
  arduboy.setCursor(15, ypos + 155);
  arduboy.print("alt+tab");
  arduboy.setCursor(15, ypos + 170);
  arduboy.print("win+l");
  arduboy.setCursor(15, ypos + 185);
  arduboy.print("turn off");

  //limites du menu

  if (keybindselect < 1) {
    keybindselect = keybindselect + 1;
  }
  else if (keybindselect > keybindamount) {
    keybindselect = keybindselect - 1;
  }

  if (ypos < -(keybindamount - 1) * 15) {
    ypos = ypos + 15;
  }
  else if (ypos > 0) {
    ypos = ypos - 15;
  }
}



void keybinds() { //keybinds
  
  switch (keybind) {
    case 0:
      keybindsloop();
      break;

    case 1: //Copier
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 2: //Coller
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 3: //Annuler une action
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('w');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 4: //"Annuler" l'annulation (si je puis dire)
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('y');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 5: //minimiser toutes les fenetres
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(';');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 6: //agrandir toutes les fenetres
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(';');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 7: //ouvrir le gestionnaire de taches
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_ESC);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 8: //Ne plus couvrir l'intégralité de l'écran / Minimiser
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_DOWN_ARROW);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 9: //fermer la fenetre
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 10:  //Ctrl+alt+suppr
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;
      
    case 11:  //Naviguer entre les fenetres
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_TAB);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 12:  //Se déconnecter de la session
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('l');
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;

    case 13:  //éteindre l'ordinateur
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('d');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
      arduboy.clear();
      arduboy.print("command sent");
      delay(100);
      keybind=0;
      break;
      
  }
  
}
