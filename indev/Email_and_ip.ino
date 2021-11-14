int mkcxpos = 6; //coordonees du curseur
int mkcypos = 6;
String email = "";

const char minitouches[4][12] = {
  {'1','2','3','4','5','6','7','8','9','0',"1","1"},
  {'a','z','e','r','t','y','u','i','o','p',2,2},
  {'q','s','d','f','g','h','j','k','l','m',3,3},
  {'w','x','c','v','b','n',' ',' ',' ','@','.','-'}
};

void minikeyboard()
{
  
  unsigned int lastc = email.length();
  
  if((arduboy.pressed(LEFT_BUTTON))&&(stopper==0)){
    mkcxpos = mkcxpos - 10;
    stopper=1;
  }
  
  if((arduboy.pressed(RIGHT_BUTTON))&&(stopper==0)){
    mkcxpos = mkcxpos + 10;
    stopper=1;
  }

  if((arduboy.pressed(UP_BUTTON))&&(stopper==0)){
    mkcypos = mkcypos - 7;
    stopper=1;
  }
  
  if((arduboy.pressed(DOWN_BUTTON))&&(stopper==0)){
    mkcypos = mkcypos + 7;
    stopper=1;
  }

  if((arduboy.notPressed(LEFT_BUTTON))&&(arduboy.notPressed(RIGHT_BUTTON))&&(arduboy.notPressed(UP_BUTTON))&&(arduboy.notPressed(DOWN_BUTTON))){
    stopper=0;
  }
  
  if(arduboy.pressed(A_BUTTON)){
    if(minitouches[(mkcypos-6)/7][(mkcxpos-6)/10]=="1"){
      email.remove(lastc,1);
    }
    else{
    email = email + minitouches[(mkcypos-6)/7][(mkcxpos-6)/10];
    delay(200);
    }
  }

  if(mkcxpos>120){
    mkcxpos=mkcxpos-10;
  }

  if(mkcypos>60){
    mkcypos=mkcypos-12;
  }

  if(mkcxpos<0){
    mkcxpos=mkcxpos+10;
  }

  if(mkcypos<0){
    mkcypos=mkcypos+10;
  }
  
  arduboy.drawRect(0,0,128,64,1);
  tinyfont.setCursor(6,5);
  tinyfont.print("1 2 3 4 5 6 7 8 9 0 <<<");
  tinyfont.setCursor(6,12);
  tinyfont.print("A Z E R T Y U I O P RTN");
  tinyfont.setCursor(6,19); 
  tinyfont.print("Q S D F G H J K L M MAJ");
  tinyfont.setCursor(6,26);
  tinyfont.print("W X C V B N _____ @ . -");
  arduboy.setCursor(50,50);
  arduboy.print((mkcypos-6)/7);
  arduboy.print(" ");
  arduboy.print((mkcxpos-6)/10);
  arduboy.print(" ");
  arduboy.print(minitouches[(mkcypos-6)/7][(mkcxpos-6)/10]);
  tinyfont.setCursor(2,40);
  tinyfont.print(email);
  arduboy.drawLine(mkcxpos,mkcypos+4,mkcxpos+3,mkcypos+4);
}
