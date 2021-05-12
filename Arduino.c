#include <LiquidCrystal.h>
#define echoPin 3// attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 4 
int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int pirStat = 0;                   // PIR status
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
const int rs = 12, en = 11, d4 = 13, d5 = 10, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
lcd.begin(16, 2);
pinMode(4, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(3, INPUT);
pinMode(7, OUTPUT);  // declare LED as output
pinMode(8, OUTPUT);  // declare LED as output
pinMode(9, OUTPUT);  // declare LED as output
pinMode(2, INPUT);
   Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Street Lighting");
  lcd.setCursor(0, 1);
  lcd.print("->Kartik Kshitij");
delay(1250);
}
void u_sound(){
      // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
}



void loop() {
  

sensorValue = analogRead(sensorPin); // read the value from the sensor

  if (sensorValue<200)
{pirStat = digitalRead(2);  
    if(pirStat==HIGH)
    {	
      u_sound();
      Serial.print(distance);
	  if(distance>30&& distance<165)
      {digitalWrite(7,HIGH);
       digitalWrite(8,HIGH);
       
       
      }
      else if(distance>165&& distance<300)
      {digitalWrite(8,HIGH);
       digitalWrite(9,HIGH);
       
       
      }
      else 
      {digitalWrite(8,HIGH);
       digitalWrite(7,HIGH);
       digitalWrite(9,HIGH);
      }
      
      Serial.println("Distance:"+distance);
      lcd.clear();
      lcd.print("Lights On");
      lcd.setCursor(0,1);
	  if(distance>30&& distance<165)
	  lcd.print("Object Close");
      else if(distance>165&& distance<300)
      lcd.print("Object Far");
      else
      lcd.print("Motion Detected");
      
    }
    
    else{
    
      lcd.clear();
      lcd.print("No Movement"); 
	  delay(1000);
	  lcd.clear();
    }
}
else
{
  	lcd.clear();
      lcd.print("Natural Light"); 
	  lcd.setCursor(0,1);
	  lcd.print("Present"); 
	delay(1000);
	  lcd.clear();
}  
delay(200);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);

}