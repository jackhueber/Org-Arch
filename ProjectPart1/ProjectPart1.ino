#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
int leftButPin = 10;
int rightButPin = 9;

int binary1[] = {0,0,0,0,0,0,0,0};
int binary2[] = {0,0,0,0,0,0,0,0};
int carry = 0;
int bitSum = 0;
int solution[] = {0,0,0,0,0,0,0,0};
int insert = 0;
int count = 0;
int change = 0;
void setup(){
  //put your setup code here
  pinMode(leftButPin, INPUT);
  pinMode(rightButPin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  pinMode(switchPin, INPUT);  
  lcd.print("00000000");
}

void loop(){
  //things you want to loop here

  int rightOn = digitalRead(leftButPin);
  int leftOn = digitalRead(rightButPin);
  
  if(leftOn == HIGH){
    count++;
  }else if(rightOn == HIGH){
    lcd.setCursor(count,0);
    if(count < 8){
      lcd.print("1");
      binary1[count] = 1;
    }
  } 
  
  delay(100);
  
  if(leftOn == HIGH && rightOn == HIGH){
    lcd.clear();
    lcd.print("both");
  }
}
