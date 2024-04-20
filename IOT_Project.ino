#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 25
#define GASPIN 12
#define DHTTYPE DHT11
#define LIGHT_SENSOR_PIN 26
#define LIGHT_THRESHOLD 2457
#define LED_PIN1 27  
#define LED_PIN2 14  
#define LED_PIN3 13
const int BUZZZER_PIN = 15;

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN1, OUTPUT); 
  pinMode(LED_PIN2, OUTPUT); 
  pinMode(LED_PIN3, OUTPUT); 
  pinMode(BUZZZER_PIN, OUTPUT);

}

void loop() {
//   int analogValue = analogRead(LIGHT_SENSOR_PIN);
//   float gasread = analogRead(GASPIN);
//   Serial.println(gasread);
// if (analogValue < LIGHT_THRESHOLD) {
//   if(gasread < 400.00){
//     digitalWrite(LED_PIN1, LOW); // turn on LED
//     digitalWrite(LED_PIN2, LOW); 
//     digitalWrite(LED_PIN3, HIGH); 
//   }
//   else if(gasread >= 400 && gasread <= 1000){
//     digitalWrite(LED_PIN1, LOW); // turn on LED
//     digitalWrite(LED_PIN2, HIGH); 
//     digitalWrite(LED_PIN3, LOW); 
//   }
//   else if(gasread > 1000){
//     digitalWrite(LED_PIN1, HIGH); // turn on LED
//     digitalWrite(LED_PIN2, LOW); 
//     digitalWrite(LED_PIN3, LOW); 
//   }


//   }
// else {
//     digitalWrite(LED_PIN1, LOW); // turn on LED
//     digitalWrite(LED_PIN2, LOW); 
//     digitalWrite(LED_PIN3, LOW); 
//   }





    
  // Serial.print("Analog Value = ");
  // Serial.print(analogValue);
  // if (analogValue < 40) {
  //   Serial.println(" => Dark");
  // } else if (analogValue < 800) {
  //   Serial.println(" => Dim");
  // } else if (analogValue < 2000) {
  //   Serial.println(" => Light");
  // } else if (analogValue < 3200) {
  //   Serial.println(" => Bright");
  // } else {
  //   Serial.println(" => Very bright");
  // }


  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  if(h >= 40 && t >= 26){
    Serial.println("BAD!!!!!");
    digitalWrite(BUZZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZZER_PIN, LOW);
    delay(2000);
  }
  else{
    Serial.println("GOOD!!!!!");
     digitalWrite(BUZZZER_PIN, LOW);
  }
  Serial.print(F("humidity: "));
  Serial.print(h);
  Serial.print(F("% temperature: "));
  Serial.print(t);
  // Serial.print(F("degrees Celsius"));
  //   float rzero = gasSensor.getRZero();
  // Serial.println(rzero);

}
