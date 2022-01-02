//routine du clavier

int cxpos = 6; //coordonees du curseur horizontales
int cypos = 6; //coordonees du curseur verticales
bool color = 0; //couleur de l'affichage, 0=noir 1=blanc
bool stopper = 0; //variable tampon pour les touches de la console afin de recevoir qu'un seul appui

const char touches[5][10] = { //tableau des touches (cherche pas à comprendre c'est un peu "chiadé")
  {'1','2','3','4','5','6','7','8','9','0'},
  {'q','w','e','r','t','y','u','i','o','p'},
  {'a','s','d','f','g','h','j','k','l',';'},
  {'z','x','c','v','b','n',218,216,217,215},
  {193,193,131,131,' ',' ',178,178,176,176}
};



void keyboardsetup(){ //setup clavier

  //inversion de l'affichage (blanc = noir et vice versa)

  //affichage sur l'écran

  arduboy.print("\n InvertDisplay : ");
  arduboy.print(color);
  arduboy.print("/1");
  arduboy.print("\n \n //use arrows \n //to interract");

  if((arduboy.pressed(UP_BUTTON))||(arduboy.pressed(LEFT_BUTTON))||(arduboy.pressed(DOWN_BUTTON))||(arduboy.pressed(RIGHT_BUTTON))){
    if(color==1){
      color=0; //si color est égal à 0 alors on n'inverse pas l'affichage
    }
    else{
      color=1; //si color est égal à 1 alors on inverse l'affichage
    }
    delay(175);
  }

  if(arduboy.pressed(B_BUTTON)){ //confirmation
    mode=1;
    delay(250);
  }

  if(arduboy.pressed(A_BUTTON)){ //retour en arrière
    arduboy.clear();
    select = 1;
    ypos = 0;
    state = 0;
    delay(200);
  }
  
  arduboy.setCursor(14,50);
  arduboy.print("<<< A       B >>>"); 
}



void keyboard() //boucle du clavier
{
  if(color==1){ //inverion de l'affichage en fonction de la variable color
    arduboy.invert(1);
  }
  
  if((arduboy.pressed(LEFT_BUTTON))&&(stopper==0)){ //déplacement sur la matrice
    cxpos = cxpos - 12;
    stopper=1;
  }
  
  if((arduboy.pressed(RIGHT_BUTTON))&&(stopper==0)){ //déplacement sur la matrice
    cxpos = cxpos + 12;
    stopper=1;
  }

  if((arduboy.pressed(UP_BUTTON))&&(stopper==0)){ //déplacement sur la matrice
    cypos = cypos - 12;
    stopper=1;
  }
  
  if((arduboy.pressed(DOWN_BUTTON))&&(stopper==0)){ //déplacement sur la matrice
    cypos = cypos + 12;
    stopper=1;
  }

  if((arduboy.notPressed(LEFT_BUTTON))&&(arduboy.notPressed(RIGHT_BUTTON))&&(arduboy.notPressed(UP_BUTTON))&&(arduboy.notPressed(DOWN_BUTTON))){ //réinitialisation de la variable stopper
    stopper=0;
  }
  
  if((arduboy.pressed(A_BUTTON))||(arduboy.pressed(B_BUTTON))){ //sélection du charactère et simulation de la pression de clavier
    Keyboard.press(touches[(cypos-6)/12][(cxpos-6)/12]);
  }
  else{
    Keyboard.releaseAll(); //relachement des touches du clavier
  }

  if(cxpos>120){ //limites horizontales du curseur sur l'affichage
    cxpos=cxpos-12; 
  }

  if(cypos>60){ //limites verticales du curseur sur l'affichage
    cypos=cypos-12;
  }

  if(cxpos<0){ //limites horizontales du curseur sur l'affichage
    cxpos=cxpos+12;
  }

  if(cypos<0){ //limites verticales du curseur sur l'affichage
    cypos=cypos+12;
  }
  
  //affichage sur l'écran

  arduboy.drawRect(0,0,128,64,1);
  arduboy.setCursor(6,5);
  arduboy.print("1 2 3 4 5 6 7 8 9 0");
  arduboy.setCursor(6,17);
  arduboy.print("a z e r t y u i o p");
  arduboy.setCursor(6,29); 
  arduboy.print("q s d f g h j k l m");
  arduboy.setCursor(6,41);
  arduboy.print("w x c v b n Z Q S D");
  arduboy.setCursor(6,53);
  arduboy.print("maj win --- bks rtn");
  arduboy.drawLine(cxpos,cypos+7,cxpos+5,cypos+7);
}



void keyboardloop(){ //boucle du clavier (avec un switch pour le setup et le clavier en lui même)
  switch (mode) {
    case 0:
      keyboardsetup();
      break;

    case 1:
      keyboard();
      break;
  }
}
