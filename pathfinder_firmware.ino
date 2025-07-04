int LED1 = D0; //Red
int LED2 = D1; //Yellow
int LED3 = D2; //Green
int LED4 = D3; //Blue

int SW1 = D4; //Red
int SW2 = D5; //Yellow
int SW3 = D6; //Green
int SW4 = D7; //Blue

while ((millis() - startMillis) <= period) {
void startGame(){
  int right = true;
  int count = 0;
  int seq [20];
  int time = 200;
  while(right){
    colour = random(0,4);
    seq[count] = colour;
    for (int i=0;i<count;i++){
      sel = seq[i];
      lightUp(sel);
      delay(time);

    }

  }
}
int pressedButton(){
  if (digitalRead(SW1) == LOW) return 0;
  if (digitalRead(SW2) == LOW) return 1;
  if (digitalRead(SW3) == LOW) return 2;
  if (digitalRead(SW4) == LOW) return 3;
  return -1;
}
void lightUp (pressedButton){
    switch (pressedButton){
    case 0:
      digitalWrite(LED1, HIGH);
      delay(200);
      digitalWrite(LED1, LOW);
    case 1:
      digitalWrite(LED2, HIGH);
      delay(200);
      digitalWrite(LED2, LOW);
    case 2:
      digitalWrite(LED3, HIGh);
      delay(200);
      digitalWrite(LED3, LOW);
    case 3:
      digitalWrite(LED4, HIGH);
      delay(200);
      digitalWrite(LED4, LOW);
  }





}
}
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  //Pins for pushbuttons, when button is pressed = LOW
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  long startTime = milis();


}

void loop() {

  //Turn off all LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  
  start = pressedButton();
  if (start>-1{
    lightUp(start);
    startGame();
  }






}
