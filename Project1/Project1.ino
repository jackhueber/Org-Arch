#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up switchPins
const int leftButPin = 10;
const int rightButPin = 9;
const int contPin = 6;

// variable to hold the value of the switchPin
int switchleft = 0;
int switchright = 0;

int binary1[] = {0,0,0,0,0,0,0,0};
int element1 = 0;
int binary2[] = {0,0,0,0,0,0,0,0};
int element2 = 0;
int solution[] = {0,0,0,0,0,0,0,0,0};

bool checkTrue = false;
int contrast = 0;

int screen = 0;

void setup() {
  //put your setup code here
  
  lcd.begin(16, 2);
  pinMode(leftButPin,INPUT);
  pinMode(rightButPin,INPUT);
  lcd.print("Press both");
  lcd.setCursor(0,1);
  lcd.print("to begin:");
  Serial.begin(9600);
  pinMode(contPin, OUTPUT);
  analogWrite(contPin, 0);
}

void(*resetFunc)(void)=0;

void loop() {
//things you want to loop here

  switchleft = digitalRead(leftButPin);
  switchright = digitalRead(rightButPin);
  
  if (switchleft == LOW && switchright == LOW){
  checkTrue = true;
 }

  else if (switchright == HIGH && switchleft == HIGH && checkTrue == true && screen != 3){
    checkTrue = false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("First number:");
    lcd.setCursor(0,1);
    screen = 1;
  }
  
  else if (screen == 1) {
    if (checkTrue == true && switchleft == HIGH && switchright == LOW){
          lcd.setCursor(element1,1);
          binary1[element1] = 1;
          lcd.print("1");
          checkTrue = false;
          element1++;  
    } else if (checkTrue == true && switchright == HIGH){
          lcd.setCursor(element1,1);
          binary1[element1] = 0;
          lcd.print("0");
          checkTrue = false;
          element1++;
    } else if (element1 == 8){
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Second number:");
        lcd.setCursor(0,1);
        screen = 2;
    }
  }

  else if (screen == 2) {
        if (checkTrue == true && switchleft == HIGH && switchright == LOW){
          lcd.setCursor(element2,1);
          binary2[element2] = 1;
          lcd.print("1");
          checkTrue = false;
          element2++;            
       }else if (checkTrue == true && switchright == HIGH){
          lcd.setCursor(element2,1);
          binary2[element2] = 0;
          lcd.print("0");
          checkTrue = false;
          element2++;
       }else if (element2 == 8){
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Your Sum Is:");
        lcd.setCursor(0,1);
        for(int i = 7; i > -1; i--){
    
          if (binary1[i] + binary2[i] + solution[i+1] == 1){
           solution[i+1] = 1;
          }else if (binary1[i] + binary2[i] + solution[i+1] == 2){
             solution[i] = 1;
          }else if (binary1[i] + binary2[i] + solution[i+1] == 3){
             solution[i+1] = 1;
             solution[i] = 1;
          }else{
             solution[i+1] = 0;
          }
        }

  for(int i = 0; i < 9; i++){
    lcd.setCursor(i,1);
    lcd.print(solution[i]);
    Serial.print(solution[i]); 
  }
  
  screen = 3;
  }
  }

else if(screen == 3){
  if (checkTrue == true && switchright == HIGH && switchright == HIGH){
    delay(1000);
  lcd.clear();
  lcd.print("Right: Reduce");
  lcd.setCursor(0,1);
  lcd.print("Left: Increase");
  checkTrue = false;
  screen = 4;
  }
}
  
  else if (screen == 4){
    if  (checkTrue == true && switchright == HIGH){
      contrast++;
      checkTrue = false;
      analogWrite(contPin, contrast);
    }else if  (checkTrue == true && switchleft == HIGH){
      contrast--;
      checkTrue = false;
      analogWrite(contPin, contrast);
    }else if (switchleft == HIGH && switchright == HIGH && screen == 4){
      checkTrue = false;
      lcd.clear();
      screen = 5;      
    }
  }
  
  else if (screen == 5){
    resetFunc();//call reset
  }
}
