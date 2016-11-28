#include <NewPing.h>
#include <Servo.h>

// Select which PWM-capable pins are to be used.
#define RED_PIN    4
#define WHITE_PIN   3
#define GREEN_PIN  2

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).

#define ALARM 13

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created
int pos = 0;    // variable to store the servo position

float sinVal;
int toneVal;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false; 

void setup(){
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
   Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  
   delay(5000); 
}

void loop() {
  myservo.write(0);
  delay(500); 
  for(pos = 0; pos <= 90; pos += 1)  // goes from 0 degrees to 180 degrees   {                                  // in steps of 1 degree     myservo.write(pos);              // tell servo to go to position in variable 'pos'     delay(15);                       // waits 15ms for the servo to reach the position   }   for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
  {                              
    myservo.write(pos);              // tell servo to go to position in variable ‘pos’
    float uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    float distance = uS / US_ROUNDTRIP_CM;
    Serial.print(pos);
    Serial.print(",");
    Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
    Serial.println();
    delay(500);                       // waits 15ms for the servo to reach the position
  }

  
}


/*void loop(){
      delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      unsigned int distance = uS / US_ROUNDTRIP_CM;
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
      Serial.println("cm");
      if(distance < 5){
         triggered = true;
      }
}
*/
  

