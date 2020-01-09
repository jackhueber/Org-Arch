// temp sensor pin variables
const int tSensorPin = 0; 
const float baselineTemp = 18.0;

void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600); // opening serial port
}
 
void loop()                
{
 // getting voltage from temperature sensor
 int sensorVal = analogRead(tSensorPin);  
 Serial.print("Sensor Value: "); Serial.println(sensorVal);
 
 // converting that reading to voltage
 float voltage = sensorVal * 5.0;
 voltage /= 1024.0; 
 Serial.print("Voltage: "); Serial.println(voltage);
 
 // print temperature in Celcius
 float temperatureC = (voltage - 0.5) * 100 ;
 
 Serial.print("Temperature: "); Serial.println(temperatureC);
 Serial.println("------------------------------");
 delay(1000);

if(temperatureC < baselineTemp){
   analogWrite(9, 255);
   analogWrite(11, 0);
}

if(temperatureC > baselineTemp){
  float redPercentDiff = (temperatureC / baselineTemp);
  float bluePercentDiff = 1 - (temperatureC / baselineTemp);
  float blueVal = bluePercentDiff * 255;
  float redVal = redPercentDiff * 255;
  analogWrite(9, blueVal);
  analogWrite(11, redVal);


}
delay(1);
 
}
