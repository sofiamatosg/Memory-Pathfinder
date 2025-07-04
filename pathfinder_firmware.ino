#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186

int LED1 = D0; //Red
int LED2 = D1; //Yellow
int LED3 = D2; //Green
int LED4 = D3; //Blue

int SW1 = D4; //Red
int SW2 = D5; //Yellow
int SW3 = D6; //Green
int SW4 = D7; //Blue

int BUZ = D8;

void play_tone(button, time){
  lightUp(button);
  switch (button){
    case 0:
      tone(BUZ, 440, time);
    case 1:
      tone(BUZ, 784, time);
    case 2:
      tone(BUZ, 880, time);
    case 3:
      tone(BUZ, 587, time);

  delay(time);
  noTone(BUZ);
  lightDown(button);    
  }


}

int waitingButton(){
  long startTime = millis();
  while ( (millis() - startTime) < time_limit){
    input = pressedButton();
    if (input != -1){
      play_tone(input, 200)
      while(checkButton() != -1) ;
      delay(10);
      return input;
    }
    return -1;
}
bool startGame(){
  randomSeed(millis());
  int roundToWin = 15;
  int count = 0;
  int seq [20];
  int answer [20];
  int time_limit = 200;
  int time = 200;
  int actualRound = 0;

  
  while(actualRound < roundToWin){
    colour = random(0,4);
    seq[actualRound] = colour;
    for (int i=0;i<actualRound;i++){
      sel = seq[i];
      play_tone(sel, time);
      time -= 1;
    }
    for (int currentMove = 0 ;currentMove < actualRound ;currentMove++){
        move = waitingButton();
        if (move == -1){
          return false;
        }
        if (move != seq[currentMove]){
          return false;
        }
    }
  }
  return true;
}

int pressedButton(){
  if (digitalRead(SW1) == LOW) return 0;
  if (digitalRead(SW2) == LOW) return 1;
  if (digitalRead(SW3) == LOW) return 2;
  if (digitalRead(SW4) == LOW) return 3;
  return -1;
}
void lightUp (button){
    switch (button){
    case 0:
      digitalWrite(LED1, HIGH);
      break;
    case 1:
      digitalWrite(LED2, HIGH);
      break;
    case 2:
      digitalWrite(LED3, HIGH);
      break;
    case 3:
      digitalWrite(LED4, HIGH);
      break;
}

void lightDown (button){
    switch (button){
    case 0:
      digitalWrite(LED1, LOW);
      break;
    case 1:
      digitalWrite(LED2, LOW);
      break;
    case 2:
      digitalWrite(LED3, LOW);
      break;
    case 3:
      digitalWrite(LED4, LOW);
      break;
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

  pinMode(BUZ, OUTPUT);
  long startTime = millis();


}

void loop() {
  if (digitalRead (BUT2) == HIGH) {
but2time = millis();
}
  //Turn off all LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  if (digitalRead (SW1) == HIGH) {
    SW1Time = millis();
  }
  if (digitalRead (SW2) == HIGH) {
    SW2Time = millis();
  }
  if (abs(but2time - but1time) <= 2000) {
    play_rickroll();
  } 
  start = pressedButton();
  if (start>-1){
    play_tone(start);
    if (startGame() == true) {
      play_win();
      }
    else{
      play_lost();
    }
    
  }
}


void play_win(){
int melody[] = {G4, C5, E5, G5, C6, E6, G6, E6, GS4, C4, DS4};

int noteDurations[] = {1,1,1,1,2,3,1,1,1,2,3}

  for (int i=0; i<11; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZ, melody[i], noteDuration);
    delay(noteDuration );
    delay(100);
    noTone(BUZ);
  }

}
void play_rickroll(){
  int melody[] = {G5, A5, C6, A5, E6, E6, D6,   G5, A5, C6, A5, D6, D6, C6   G5, A5, C6, A5, D6, B5, A5, G5, G5, D6, C6};

  int noteDurations[] = {1,1,1,1,2,2,3,1,1,1,1,2,2,3,1,1,1,1,2,2,3, 1, 4};

  for (int i=0; i<25; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZ, melody[i], noteDuration);
    delay(noteDuration);
    delay(100);
    noTone(BUZ);
  }

}
void play_lost(){
  int melody[] = {A4, G4, F4, E4, DS4};

  int noteDurations[] = {1,1,1,1,4};

  for (int i=0; i<5; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZ, melody[i], noteDuration);
    delay(noteDurations);
    delay(100);
    noTone(BUZ);
  }

}

