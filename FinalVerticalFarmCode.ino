#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
int sensePin=2;
DHT HT(sensePin, Type);
float humidity;
float tempF;
int setTime=500;
int loopcounter=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
delay(setTime);
pinMode(13,1);
pinMode(6,1);
}
void loop() {
  // put your main code here, to run repeatedly:

loopcounter=loopcounter+1;

Serial.print(" Loop Counter: ");
Serial.println(loopcounter);
delay(1000);
digitalWrite(13,1);
delay(2000);
digitalWrite(13,0);

humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print(" Temperature: ");
Serial.print(tempF);
Serial.println(" F ");

if (humidity<60) {
  digitalWrite(6,1);
  Serial.print( "Watering because of low humidity ");
  delay(20000);
  digitalWrite(6,0);
  Serial.print( "Recalculating Humidity ");
  delay(30000);
  Serial.print( "Humidity: ");
  Serial.println(humidity);
}

if (loopcounter==1370) {
  digitalWrite(6,1);
  delay(10000);
  digitalWrite(6,0);
  delay(30000);
  digitalWrite(6,1);
  delay(10000);
  digitalWrite(6,0);
  delay(30000);
  digitalWrite(6,1);
  delay(10000);
  digitalWrite(6,0);
  delay(30000);
  digitalWrite(6,1);
  delay(10000);
  digitalWrite(6,0);
  loopcounter=0;
  Serial.println( "Watered the plants because 24 hours passed ");
}

delay(60000);


}
