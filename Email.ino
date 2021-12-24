/*
ALWAYS INDEV 
*/

int mkcxpos = 6; //coordonees du curseur
int mkcypos = 6;
String email = "";
bool capslock = 0;
unsigned char keeblock = 0;

const char minitouches[8][12] = {
  {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' ', ' '},
  {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 2, 2},
  {'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 3, 3},
  {'w', 'x', 'c', 'v', 'b', 'n', ' ', ' ', ' ', '@', '.', '-'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' ', ' '},
  {'A', 'Z', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 2, 2},
  {'Q', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 3, 3},
  {'W', 'X', 'C', 'V', 'B', 'N', ' ', ' ', ' ', '@', '.', '-'}
};

void emailsetup()
{
  arduboy.print("\n Type your email\n adress, then press\n RTN to confirm");

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

void minikeyboard()
{

  unsigned int lastc = email.length() - 1;
  unsigned int barre = email.length()*5;

  if ((arduboy.pressed(LEFT_BUTTON)) && (stopper == 0)) {
    mkcxpos = mkcxpos - 10;
    stopper = 1;
  }

  if ((arduboy.pressed(RIGHT_BUTTON)) && (stopper == 0)) {
    mkcxpos = mkcxpos + 10;
    stopper = 1;
  }

  if ((arduboy.pressed(UP_BUTTON)) && (stopper == 0)) {
    mkcypos = mkcypos - 7;
    stopper = 1;
  }

  if ((arduboy.pressed(DOWN_BUTTON)) && (stopper == 0)) {
    mkcypos = mkcypos + 7;
    stopper = 1;
  }

  if ((arduboy.notPressed(LEFT_BUTTON)) && (arduboy.notPressed(RIGHT_BUTTON)) && (arduboy.notPressed(UP_BUTTON)) && (arduboy.notPressed(DOWN_BUTTON))) {
    stopper = 0;
  }

  if (arduboy.pressed(A_BUTTON)) {
    if ((((mkcypos - 6) / 7 == 0) && ((mkcxpos - 6) / 10 == 10)) || (((mkcypos - 6) / 7 == 0) && ((mkcxpos - 6) / 10 == 11))) {
      email.remove(lastc, 1);
    }
    else if ((((mkcypos - 6) / 7 == 2) && ((mkcxpos - 6) / 10 == 10)) || (((mkcypos - 6) / 7 == 2) && ((mkcxpos - 6) / 10 == 11))) {
      capslock=!capslock;
    }
    else if ((((mkcypos - 6) / 7 == 1) && ((mkcxpos - 6) / 10 == 10)) || (((mkcypos - 6) / 7 == 1) && ((mkcxpos - 6) / 10 == 11))) {
      arduboy.clear();
      state = 0;
      mode = 0;
      delay(200);
    }
    else {
      email = email + minitouches[((mkcypos - 6) / 7)+keeblock][(mkcxpos - 6) / 10];
    }
    delay(200);
  }

  if (mkcxpos > 116) {
    mkcxpos = mkcxpos - 10;
  }

  if (mkcypos > 27) {
    mkcypos = mkcypos - 7;
  }

  if (mkcxpos < 6) {
    mkcxpos = mkcxpos + 10;
  }

  if (mkcypos < 6) {
    mkcypos = mkcypos + 7;
  }

  arduboy.drawRect(0, 0, 128, 64, 1);
  tinyfont.setCursor(6, 5);
  tinyfont.print("Email :");
  tinyfont.setCursor(6, 15);
  tinyfont.print(email);
  tinyfont.setCursor(6, 25);

  keeblock = capslock*4;
  
  tinyfont.print("Caps lock : ");
  tinyfont.print(capslock);
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (etatbarre == LOW) {
      tinyfont.setCursor(5+barre, 15);
      tinyfont.print("|");
      etatbarre = HIGH;
    } else {
      etatbarre = LOW;
    }
  }
  
  tinyfont.setCursor(6, 5+29);
  tinyfont.print("1 2 3 4 5 6 7 8 9 0 <<<");
  tinyfont.setCursor(6, 12+29);
  tinyfont.print("A Z E R T Y U I O P RTN");
  tinyfont.setCursor(6, 19+29);
  tinyfont.print("Q S D F G H J K L M MAJ");
  tinyfont.setCursor(6, 26+29);
  tinyfont.print("W X C V B N _____ @ . -");
  arduboy.drawLine(mkcxpos, mkcypos + 4 + 29, mkcxpos + 3, mkcypos + 4 + 29);
}

void emailloop(){
  switch (mode) {
    case 0:
      emailsetup();
      break;

    case 1:
      minikeyboard();
      break;
  }
}
