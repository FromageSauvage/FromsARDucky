//routine des specs

void specsloop()
{
  if(arduboy.pressed(A_BUTTON)){ //retour en arrière
    arduboy.clear();
    select = 1;
    ypos = 0;
    state = 0;
    delay(200);
  }

  arduboy.drawRect(1,-2,126,68,1); //dessiner des lignes verticales à droite et à gauche
  
  //affichage du texte sur l'écran
  
  arduboy.setCursor(6,5);
  arduboy.print("From's HID v");
  arduboy.print(version);
  arduboy.setCursor(6,17);
  arduboy.print("Coded by Valentin");
  arduboy.setCursor(6,25);
  arduboy.print("Special thanks to");
  arduboy.setCursor(6,33);
  arduboy.print("Bapt !");
  arduboy.setCursor(6,45);
  arduboy.print("This program is");
  arduboy.setCursor(6,52);
  arduboy.print("Open Source !");
  
  arduboy.setCursor(105, 50);
  arduboy.print("< A");
}
