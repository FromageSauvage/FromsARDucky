unsigned char cursorspeed = 2;
int potarcursor = 64;
int range = 3;

void mousespeed()
{
  arduboy.setCursor(14,12);
  arduboy.print("Mouse speed : ");
  arduboy.print(((potarcursor-24)/20)+1);
  arduboy.print("/5");
  
  if(((potarcursor-24)/20)+1>5){
    potarcursor=potarcursor-20;
  }
   
  if(((potarcursor-24)/20)+1<1){
    potarcursor=potarcursor+20;
  }
  
  arduboy.drawRect(14,27,100,5,1);
  arduboy.fillRect(potarcursor-1,26,3,7,1);
  arduboy.setCursor(14,50);
  arduboy.print("<<< A       B >>>"); 

  if(arduboy.pressed(LEFT_BUTTON)){
    potarcursor=potarcursor-20;
    cursorspeed=cursorspeed+1;
    delay(175);
  }
  
  if(arduboy.pressed(RIGHT_BUTTON)){
    potarcursor=potarcursor+20;
    cursorspeed=cursorspeed-1;
    delay(250);
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

}
void mouse()
{
  int upState = arduboy.pressed(DOWN_BUTTON);
  int downState = arduboy.pressed(UP_BUTTON);
  int rightState = arduboy.pressed(LEFT_BUTTON);
  int leftState = arduboy.pressed(RIGHT_BUTTON);
  int leftClickState = arduboy.pressed(A_BUTTON);
  int rightClickState = arduboy.pressed(B_BUTTON);

  int  xDistance = (leftState - rightState) * range;
  int  yDistance = (upState - downState) * range;

  if ((xDistance != 0) || (yDistance != 0)) {
    Mouse.move(xDistance, yDistance, 0);
  }

  if (leftClickState == HIGH) {
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  if (rightClickState == HIGH) {
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT);
    }
  }
  else {
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT);
    }
  }

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
  
  delay(cursorspeed*2);
}
void mouseloop()
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
