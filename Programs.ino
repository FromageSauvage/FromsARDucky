//cmd
//cmd ctrl maj return
//powershell
//powershell ctrl maj return
//explorer
//notepad

int yprogpos = 0;
unsigned char progselect = 1;
unsigned char progamount = 8;
unsigned char prog = 0;
bool windr = 0;

void programsmode(){
  arduboy.print("\n Windows+R : ");
  arduboy.print(windr);
  arduboy.print("/1");
  tinyfont.setCursor(6,24);
  tinyfont.print("Use arrows to interract\nBy the way on some pcs\nwindows+R doesn't work\ncheck it before");

  if((arduboy.pressed(UP_BUTTON))||(arduboy.pressed(LEFT_BUTTON))||(arduboy.pressed(DOWN_BUTTON))||(arduboy.pressed(RIGHT_BUTTON))){
    if(windr==1){
      windr=0;
    }
    else{
      windr=1;
    }
    delay(175);
  }

  if(arduboy.pressed(B_BUTTON)){
    prog = 1;
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

void programsselect(){
  if (arduboy.pressed(DOWN_BUTTON)) {
    progselect = progselect + 1;
    yprogpos = yprogpos - 15;
    delay(200);
  }

  if (arduboy.pressed(UP_BUTTON)) {
    progselect = progselect -  1;
    yprogpos = yprogpos + 15;
    delay(200);
  }

  if (arduboy.pressed(B_BUTTON)) {
    arduboy.clear();
    prog = progselect+1;
    delay(200);
  }

  if(arduboy.pressed(A_BUTTON)){
    state=0;
    delay(250);
  }

  arduboy.setCursor(5, 5);
  arduboy.print(">");

  arduboy.setCursor(105, 5);
  arduboy.print(progselect);
  arduboy.print("/");
  arduboy.print(progamount);
  arduboy.setCursor(15, yprogpos + 5);
  arduboy.print("/cmd");
  arduboy.setCursor(15, yprogpos + 20);
  arduboy.print("/cmd admin");
  arduboy.setCursor(15, yprogpos + 35);
  arduboy.print("/pshell");
  arduboy.setCursor(15, yprogpos + 50);
  arduboy.print("/pshell admin");
  arduboy.setCursor(15, yprogpos + 65);
  arduboy.print("/explorer");
  arduboy.setCursor(15, yprogpos + 80);
  arduboy.print("/notepad");
  arduboy.setCursor(15, yprogpos + 95);
  arduboy.print("/control panel");
  arduboy.setCursor(15, yprogpos + 110);
  arduboy.print("/task manager");

  if (progselect < 1) {
    progselect = progselect + 1;
  }
  else if (progselect > scriptamount) {
    progselect = progselect - 1;
  }

  if (yprogpos < -(progamount - 1) * 15) {
    yprogpos = yprogpos + 15;
  }
  else if (yprogpos > 0) {
    yprogpos = yprogpos - 15;
  }
}

void programsloop(){
  switch (prog) {
    case 0:
      programsmode();
      break;

    case 1:
      programsselect();
      break;

    case 2:
      
      break;

    case 3:
      
      break;

    case 4:
      
      break;

    case 5:
      
      break;

    case 6:
      
      break;

    case 7:
      
      break;

    case 8:
      
      break;
}
}
