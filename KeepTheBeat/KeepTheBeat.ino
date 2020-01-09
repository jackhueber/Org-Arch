const int a = 440;
const int b = 466;
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;

const int speakerPin = 8;
// Notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

const int green = 4;
const int blue = 5;
const int yellow = 6;
const int red = 7;

unsigned long previousTime = 0;
long interval = 2000;
int led = 4;
//vars for switchpin and servo
//switchpin decided not to work
const int switchPin = 9;
unsigned long prevTime = 0;
unsigned long currentTime = millis();
int tiltSwitch = 0;
int prevSwitch = 0;
#include <Servo.h>
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //lights go on then off before song
 
   digitalWrite(green, HIGH);
   delay(2000);
   digitalWrite(blue, HIGH);
   delay(2000);
   digitalWrite(yellow, HIGH);
   delay(2000);
   digitalWrite(red, HIGH);
   delay(2000);
   //turn leds off
   digitalWrite(green, LOW);
   digitalWrite(blue, LOW);
   digitalWrite(yellow, LOW);
   digitalWrite(red, LOW);
   
   // start the song
   GameOfThrones();
   myServo.attach(10);//Relating the servo to the pin 10
   delay(1000);
 myServo.write(0);
 delay(1000);
  myServo.write(170);
  

 
}
void GameOfThrones()
  {
    for(int i=0; i<4; i++)
    {
    tone(speakerPin, NOTE_G4);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_DS4);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_F4);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(250);
    noTone(speakerPin);
    }
    for(int i=0; i<4; i++)
    {
    tone(speakerPin, NOTE_G4);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
   digitalWrite(red, LOW);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    digitalWrite(yellow, LOW);
   digitalWrite(red, HIGH);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_E4);
    digitalWrite(yellow, HIGH);
   digitalWrite(red, LOW);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_F4);
    digitalWrite(yellow, LOW);
   digitalWrite(red, HIGH);
    delay(250);
    noTone(speakerPin);
    }
        tone(speakerPin, NOTE_G4);
        digitalWrite(green, LOW);
   digitalWrite(red, HIGH);
        delay(500);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        digitalWrite(green, HIGH);
   digitalWrite(red, LOW);
        delay(500);
        tone(speakerPin, NOTE_DS4);
        digitalWrite(green, LOW);
   digitalWrite(red, HIGH);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_F4);
        digitalWrite(green, HIGH);
   digitalWrite(red, LOW);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        digitalWrite(green, LOW);
   digitalWrite(red, HIGH);
        delay(500);
        noTone(speakerPin);
    for(int i=0; i<3; i++)
    {
    tone(speakerPin, NOTE_G3);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
   digitalWrite(red, LOW);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_AS3);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_D4);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(500);
    noTone(speakerPin);
    }//
        tone(speakerPin, NOTE_G3);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(500);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(1000);
        noTone(speakerPin);
        
        tone(speakerPin, NOTE_F4);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_DS4);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_F4);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_AS3);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(1000);
        noTone(speakerPin);
        tone(speakerPin, NOTE_DS4);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_D4);
        digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
        delay(250);
        noTone(speakerPin);
        tone(speakerPin, NOTE_C4);
        digitalWrite(blue, LOW);
    digitalWrite(yellow, HIGH);
        delay(500);
        noTone(speakerPin);
    for(int i=0; i<3; i++)
    {
    tone(speakerPin, NOTE_GS3);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_AS3);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_F3);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(500);
    noTone(speakerPin);
    }
          tone(speakerPin, NOTE_G4);
          digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
          delay(1000);
          noTone(speakerPin);
          tone(speakerPin, NOTE_C4);
          digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
          delay(1000);
          noTone(speakerPin);
          tone(speakerPin, NOTE_DS4);
          digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
          delay(250);
          noTone(speakerPin);
          tone(speakerPin, NOTE_F4);
          digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
          delay(250);
          noTone(speakerPin);
          tone(speakerPin, NOTE_G4);
          digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
          delay(1000);
          noTone(speakerPin);
          tone(speakerPin, NOTE_C4);
          digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
          delay(1000);
          noTone(speakerPin);
          tone(speakerPin, NOTE_DS4);
          digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
          delay(250);
          noTone(speakerPin);
          tone(speakerPin, NOTE_F4);
          digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
          delay(250);
          noTone(speakerPin);
          tone(speakerPin, NOTE_D4);
          digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
          delay(500);
          noTone(speakerPin);
    for(int i=0; i<4; i++)
    {
    tone(speakerPin, NOTE_G3);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(500);
    noTone(speakerPin);
    tone(speakerPin, NOTE_AS3);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_C4);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(250);
    noTone(speakerPin);
    tone(speakerPin, NOTE_D4);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(yellow, LOW);
    delay(500);
    noTone(speakerPin);
    }
  }
