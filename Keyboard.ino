int cxpos = 6; //coordonees du curseur
int cypos = 6;
bool color = 0;

const char touches[5][10] = {
  {'1','2','3','4','5','6','7','8','9','0'},
  {'q','w','e','r','t','y','u','i','o','p'},
  {'a','s','d','f','g','h','j','k','l',';'},
  {'z','x','c','v','b','n',218,216,217,215},
  {193,193,131,131,' ',' ',178,178,176,176}
};

void keyboardsetup(){
  arduboy.print("\n InvertDisplay : ");
  arduboy.print(color);
  arduboy.print("/1");
  arduboy.print("\n \n //use arrows \n //to interract");

  if((arduboy.pressed(UP_BUTTON))||(arduboy.pressed(LEFT_BUTTON))||(arduboy.pressed(DOWN_BUTTON))||(arduboy.pressed(RIGHT_BUTTON))){
    if(color==1){
      color=0;
    }
    else{
      color=1;
    }
    delay(175);
  }

  if(arduboy.pressed(B_BUTTON)){
    mode=1;
    delay(250);
  }

  if(arduboy.pressed(A_BUTTON)){
    arduboy.clear();
    state = 0;
    delay(200);
  }
  
  arduboy.setCursor(14,50);
  arduboy.print("<<< A       B >>>"); 
}

void keyboard()
{
  if(color==1){
    arduboy.invert(1);
  }
  
  if((arduboy.pressed(LEFT_BUTTON))&&(stopper==0)){
    cxpos = cxpos - 12;
    stopper=1;
  }
  
  if((arduboy.pressed(RIGHT_BUTTON))&&(stopper==0)){
    cxpos = cxpos + 12;
    stopper=1;
  }

  if((arduboy.pressed(UP_BUTTON))&&(stopper==0)){
    cypos = cypos - 12;
    stopper=1;
  }
  
  if((arduboy.pressed(DOWN_BUTTON))&&(stopper==0)){
    cypos = cypos + 12;
    stopper=1;
  }

  if((arduboy.notPressed(LEFT_BUTTON))&&(arduboy.notPressed(RIGHT_BUTTON))&&(arduboy.notPressed(UP_BUTTON))&&(arduboy.notPressed(DOWN_BUTTON))){
    stopper=0;
  }
  
  if((arduboy.pressed(A_BUTTON))||(arduboy.pressed(B_BUTTON))){
    Keyboard.press(touches[(cypos-6)/12][(cxpos-6)/12]);
  }
  else{
    Keyboard.releaseAll();
  }

  if(cxpos>120){
    cxpos=cxpos-12;
  }

  if(cypos>60){
    cypos=cypos-12;
  }

  if(cxpos<0){
    cxpos=cxpos+12;
  }

  if(cypos<0){
    cypos=cypos+12;
  }
  
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

void keyboardloop(){
  switch (mode) {
    case 0:
      keyboardsetup();
      break;

    case 1:
      keyboard();
      break;
  }
}
