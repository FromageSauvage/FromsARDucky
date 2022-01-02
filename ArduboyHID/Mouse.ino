//routine de la souris

unsigned char cursorspeed = 2; //vitesse du curseur
int potarcursor = 64; //position du curseur sur le potentiomètre virtuel dans l'écran de setup
int range = 3; //nombre de pixel que parcourt le curseur à chaque déplacement



void mousespeed() //setup de la souris
{

  //affichage sur l'écran

  arduboy.setCursor(14,12);
  arduboy.print("Mouse speed : ");
  arduboy.print(((potarcursor-24)/20)+1);
  arduboy.print("/5");

  //limites du curseur dans le potentiomètre virtuel
  
  if(((potarcursor-24)/20)+1>5){
    potarcursor=potarcursor-20;
  }
   
  if(((potarcursor-24)/20)+1<1){
    potarcursor=potarcursor+20;
  }
  
  //dessin du potar virtuel et "misc" (etc)

  arduboy.drawRect(14,27,100,5,1);
  arduboy.fillRect(potarcursor-1,26,3,7,1);
  arduboy.setCursor(14,50);
  arduboy.print("<<< A       B >>>"); 


  if(arduboy.pressed(LEFT_BUTTON)){ //déplacement du curseur vers la gauche
    potarcursor=potarcursor-20;
    cursorspeed=cursorspeed+1;
    delay(175);
  }
  
  if(arduboy.pressed(RIGHT_BUTTON)){ //déplacement du curseur vers la droite
    potarcursor=potarcursor+20;
    cursorspeed=cursorspeed-1;
    delay(250);
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

}



void mouse() //boucle de la souris
{

  int upState = arduboy.pressed(DOWN_BUTTON); //assignation des variables d'états de boutons
  int downState = arduboy.pressed(UP_BUTTON); 
  int rightState = arduboy.pressed(LEFT_BUTTON); 
  int leftState = arduboy.pressed(RIGHT_BUTTON); 
  int leftClickState = arduboy.pressed(A_BUTTON); 
  int rightClickState = arduboy.pressed(B_BUTTON); 


  int  xDistance = (leftState - rightState) * range; //définition des variables de distance (distance parcourue par le curseur en fonction de la variable range)
  int  yDistance = (upState - downState) * range;

  if ((xDistance != 0) || (yDistance != 0)) { //si la souris bouge
    Mouse.move(xDistance, yDistance, 0);
  }

  if (leftClickState == HIGH) { //clic gauche
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  else {
    if (Mouse.isPressed(MOUSE_LEFT)) { 
      Mouse.release(MOUSE_LEFT);
    }
  }

  if (rightClickState == HIGH) { //clic droite
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT);
    }
  }
  else {
    if (Mouse.isPressed(MOUSE_RIGHT)) { 
      Mouse.release(MOUSE_RIGHT);
    }
  }

  //affichage sur l'écran

  arduboy.setCursor(5,5); 
  arduboy.print("ardky/Mouse.ino/");
  
  arduboy.drawRoundRect(5,16,31,31,3,1);
  arduboy.setCursor(18,20);
  arduboy.print(downState);
  arduboy.setCursor(9,28);
  arduboy.print(rightState);
  arduboy.setCursor(18,36);
  arduboy.print(upState);
  arduboy.setCursor(27,28);
  arduboy.print(leftState);
  
  arduboy.drawRoundRect(41,16,23,15,3,1);
  arduboy.setCursor(45,20);
  arduboy.print(leftClickState);
  arduboy.setCursor(55,20);
  arduboy.print(rightClickState);
  
  delay(cursorspeed*2); //délai pour limiter la vitesse de la souris
}


void mouseloop() //loop principale de la souris
{
  switch (mode) {
    case 0:
      mousespeed();
      break;

    case 1:
      mouse();
      break;
  }
}
