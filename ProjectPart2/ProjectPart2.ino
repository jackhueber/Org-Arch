/*
 This Simon Says game consists of 4 LED lights that are related to four of the aligned buttons.
 After the setup has started the lights will falsh and to begin the game you must select any button.
 The rues are to press the buttons in order of the sequence played.  A new instruction will be added each round.
 When losing the game will reset to 0 and you may start the same way, same with winning.  Winning and losng have their own songs.
 Good Luck!
 */

//Below we have all of the constants
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
//These are the constants for if the user pressed a button or not and which one

//using bitshifting here to create a "set" of the LEDs
const int userRed  = (1 << 0); //0001 
const int userGreen  = (1 << 1); //0010
const int userBlue = (1 << 2); //0100
const int userYellow = (1 << 3); //1000

//these are the pin numbers for each light
const int ledRed = 10;
const int ledGreen = 3;
const int ledBlue = 13;
const int ledYellow = 5;

//these are the pin numbers for the buttons to each light
const int butRed = 9;
const int butGreen = 2;
const int butBlue = 12;
const int butYellow = 6;

// the speaker pins are here
const int speakerPin1 = 4;
const int speakerPin2 = 7;

// Game rules
const int rounds = 8;   //8 rounds to win
const int TIME_LIMIT = 3000; //In milliseconds this is 3 seconds to press a button or game over

//Keeping track of the elements of the game
byte gameBoard[32]; //The combination of buttons as the player advance
byte gameRound = 0; //Number of rounds player has advanced

void setup()
{
  // put your setup code here, to run once:

  //Using pullups instead of inputs because google said something about internal resistors and the pins the buttons were on
  pinMode(butRed, INPUT_PULLUP);
  pinMode(butGreen, INPUT_PULLUP);
  pinMode(butBlue, INPUT_PULLUP);
  pinMode(butYellow, INPUT_PULLUP);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  pinMode(speakerPin1, OUTPUT);
  pinMode(speakerPin2, OUTPUT);

  //Play the start music
  startTone();
}

void loop()
{
    // put your main code here, to run repeatedly:

  startLights(); // Blink lights while waiting for user to press a button

  setLEDs(userRed | userGreen | userBlue | userYellow);
  delay(1000);
  setLEDs(0);
  delay(250);

    // Play the game and play song based on if player wins or loses
    if (playGame() == true) {
      winTone(); 
    }else{ 
      loseTone();
    }
}

// Play game function, 1 is returned if player wins, 0 if the player loses
//we add the new button/light onto the previous levels
boolean playGame(void)
{
  randomSeed(millis()); // randomly set the time so that the lights are random, lights are based on the millis

  gameRound = 0; //Each time playGame is called the round will start at 0 of 8

  while (gameRound < rounds) 
  {
    addNewButton(); // Add a button to the current moves, then play them back

    previousLevels(); // Play back the current game board

    // the player will now need to repeat the previous levels as well as the added button/light
    for (byte currentButton = 0; currentButton < gameRound ; currentButton++)
    {
      byte choice = waitForPress(); // wait for the players input

      if (choice == 0) return false; // if the player waits too long (3 seconds) the choice is 0 and you lose

      if (choice != gameBoard[currentButton]) return false; // when the player does not follow the sequence we get here and they lose
    }

    delay(1000); // if the player gets the button correct continue
  }

  return true; //return true when the player wins the game
}

// Adds a new random button/light to the game
void addNewButton(void)
{
  byte newButton = random(0, 4);

  // based on the newButton we select the light
  if(newButton == 0){
    newButton = userRed;
  }else if(newButton == 1){
    newButton = userGreen;
  }else if(newButton == 2){
    newButton = userBlue;
  }else if(newButton == 3){
    newButton = userYellow;
  }

  gameBoard[gameRound++] = newButton; // Add this new button to the game array
}

// Plays the previous levels in the game and then you add the next level in playGame()
void previousLevels(void)
{
  for (byte currentButton = 0 ; currentButton < gameRound ; currentButton++) 
  {
    playTone(gameBoard[currentButton], 150);

  //This is the timer between each instruction
    delay(200);
  }
}

// Passes in the byte from the colored the user chose , lights that button's LED
void setLEDs(byte leds)
{
  if ((leds & userRed) != 0){
    digitalWrite(ledRed, HIGH);
  }else{
    digitalWrite(ledRed, LOW);
  }
  if ((leds & userGreen) != 0){
    digitalWrite(ledGreen, HIGH);
  }else{
  digitalWrite(ledGreen, LOW);
  }
  if ((leds & userBlue) != 0){
    digitalWrite(ledBlue, HIGH);
  }else{
    digitalWrite(ledBlue, LOW);
  }
  if ((leds & userYellow) != 0){
    digitalWrite(ledYellow, HIGH);
  }else{
    digitalWrite(ledYellow, LOW);
  }
}

// make the LEDs turn on and off until the user has pressed a button to start the game
void startLights(void)
{
  while(1) 
  {
    setLEDs(userRed);
    delay(100);
    if (checkButton() != 0){
      return;
    }

    setLEDs(userGreen);
    delay(100);
    if (checkButton() != 0){
      return;
    }

    setLEDs(userBlue);
    delay(100);
    if (checkButton() != 0){
      return;
    }

    setLEDs(userYellow);
    delay(100);
    if (checkButton() != 0){
      return;
    }
  }
}

// waitForPress() waits for the user input and will either return the color of the light or 0 if TIME_LIMIT is reached
byte waitForPress(void)
{
  long startTime = millis();

  while ( (millis() - startTime) < TIME_LIMIT) // Loop until 3 seconds has passed
  {
    byte button = checkButton();

    if (button != 0)
    { 
      playTone(button, 150); // Play the button the user just pressed

      while(checkButton() != 0) ;  // Now let's wait for user to release button

      delay(10); // Debouncing delay

      return button;
    }
  }
  return 0; // If we get here return 0 and game over
}

// Returns the bit for where the color chosen is
byte checkButton(void)
{
  if (digitalRead(butRed) == 0){
    return(userRed); 
  }else if (digitalRead(butGreen) == 0){
    return(userGreen); 
  }else if (digitalRead(butBlue) == 0){
    return(userBlue); 
  }else if (digitalRead(butYellow) == 0){
    return(userYellow);
  }
  return(0); // If the user did not select a button then  is returned
}

// speakerNote turns buzzes the speaker for noteDurationMic, for a duration of noteLengthMil.
void speakerNote(int noteLengthMil, int noteDurationMic)
{
  // Convert play time from milliseconds to microseconds
  long noteLengthMic = noteLengthMil * (long)1000;

  // Loop until the remaining play time is less than the noteDurationMic
  while (noteLengthMic > (noteDurationMic * 2))
  {
    noteLengthMic -= noteDurationMic * 2; //this shortens the remaining time to play

    // Toggle the buzzer at various speeds
    digitalWrite(speakerPin1, LOW);
    digitalWrite(speakerPin2, HIGH);
    delayMicroseconds(noteDurationMic);

    digitalWrite(speakerPin1, HIGH);
    digitalWrite(speakerPin2, LOW);
    delayMicroseconds(noteDurationMic);
  }
}

// Light an LED and play tone
void playTone(byte LEDs, int noteLengthMil)
{
  setLEDs(LEDs); //takes the LED from the switch statement

  //this switch set the speaker tone for each light
  switch(LEDs) 
  {
  case userRed:
    speakerNote(noteLengthMil, 1100); 
    break;
  case userGreen:
    speakerNote(noteLengthMil, 600); 
    break;
  case userBlue:
    speakerNote(noteLengthMil, 900); 
    break;
  case userYellow:
    speakerNote(noteLengthMil, 700); 
    break;
  }
  setLEDs(0); //turns off the LEDs
}

// Play the starting sound/lights
void startTone(void)
{
  setLEDs(userRed);
  speakerNote(255, 1100);
  setLEDs(userGreen);
  speakerNote(255, 600);
  setLEDs(userBlue);
  speakerNote(255, 900);
  setLEDs(userYellow);
  speakerNote(255, 700);
}

// Play the winner sound/lights
void winTone(void)
{
  setLEDs(userGreen | userBlue);
  speakerNote(255, 600);
  setLEDs(userRed | userYellow);
  speakerNote(255, 900);
  setLEDs(userGreen | userBlue);
  speakerNote(255, 600);
  setLEDs(userRed | userYellow);
  speakerNote(255, 900);
}

// Play the loser sound/lights
void loseTone(void)
{
  setLEDs(userRed | userGreen);
  speakerNote(255, 1500);
  setLEDs(userBlue | userYellow);
  speakerNote(255, 1500);
  setLEDs(userRed | userGreen);
  speakerNote(255, 1500);
  setLEDs(userBlue | userYellow);
  speakerNote(255, 1500);
}
