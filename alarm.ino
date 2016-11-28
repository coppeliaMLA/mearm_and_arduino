#include <NewPing.h>
#include <NewTone.h>

// Select which PWM-capable pins are to be used.
#define RED_PIN    4
#define WHITE_PIN   3
#define GREEN_PIN  2

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).

#define ALARM 13

float sinVal;
int toneVal;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false; 

void setup(){

   pinMode(ALARM, OUTPUT);
   //reset lights
   digitalWrite(RED_PIN,LOW);
   digitalWrite(WHITE_PIN,LOW);
   digitalWrite(GREEN_PIN,LOW);
   Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  
   delay(5000); 
}


void alarm(){
  digitalWrite(RED_PIN, HIGH);
      delay(30);
      digitalWrite(RED_PIN, LOW);
      delay(30);
      digitalWrite(WHITE_PIN, HIGH);
      delay(30);
      digitalWrite(WHITE_PIN, LOW);
      delay(30);
      digitalWrite(GREEN_PIN, HIGH);
      delay(30);
      digitalWrite(GREEN_PIN, LOW);
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 1000+(int(sinVal*100));
    NewTone(ALARM, toneVal);
  }
}


void loop(){
    if(triggered == true){
      alarm();
    }
    else{
      delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      unsigned int distance = uS / US_ROUNDTRIP_CM;
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
      Serial.println("cm");
      if(distance < 80){
         triggered = true;
      }
   }
}

  

