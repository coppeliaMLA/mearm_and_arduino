#include <Servo.h>
#include <NewPing.h>

Servo middle, left, right, claw ;  // creates 4 "servo objects"
//positions 30, 45, 60, 75, 90, 105, 120, 135, 150
#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false; 
float prev_distance = 100;
float distance = 100;

void setup()
{

  /*left.detach();
  right.detach();
  middle.detach();
  claw.detach();
  */
     Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  
   delay(5000); 
}

void loop(){
    if(triggered == true){
      triggered = false;
      alarm();
      
    }
    else{
      delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
      prev_distance = distance;
      distance = uS / US_ROUNDTRIP_CM;
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
      Serial.println("cm");
      Serial.print(triggered);
      if(distance  < 50 & prev_distance < 50){
         triggered = true;
      }
   }
}

void alarm()
{

  middle.attach(8);  
  left.attach(10);  
  right.attach(11); 
  claw.attach(9); 
  claw.write(90);
  middle.write(20);
  left.write(45);
  right.write(90);
  
 // 4 to 9
 //grab(75);
 //drop(150);

 // 8 to 4
 //grab(135);
 //drop(75);

 // 1 to 8
 //grab(30);
 //drop(135);

 // 2 to 1
 //grab(45);
 //drop(30);

 // 6 to 2
 //grab(105);
 //drop(45);

 // 9 to 6
 //grab(150);
 //drop(105);

 //Celebrate

 claw.write(25);
 slow_move(middle, 20, 90);
 slow_move(right, 90, 130);
 slow_move(left, 45, 5);
 claw.write(130);
 delay(1000);
 claw.write(25);
 slow_move(left, 5, 45);
 slow_move(right, 130, 90);
 slow_move(middle, 90, 180);
 claw.write(130);
 delay(100);
 claw.write(25);
 delay(100);
 slow_move(middle, 180, 20);
 delay(1000);
 
  middle.detach();  
  left.detach();
  right.detach();
  claw.detach();

}


void slow_move(Servo &the_servo, int x, int y) {
  the_servo.write(x);
  int i;
  if (x < y) {
    for (i = x; i < y; i++) {
      the_servo.write(i);
      delay(15);
    }
  } else {
    for (i = x; i > y; i--) {
      the_servo.write(i);
      delay(15);
    }
  }

}

void grab(int middle_angle) {
  //slow_move(left, 10, 45);
  slow_move(middle, 90, middle_angle);
  slow_move(claw, 60, 110);
  slow_move(right, 90, 180);
  //delay(5000);
  slow_move(claw, 110, 60);
  slow_move(right, 180, 90);
  slow_move(middle, middle_angle, 90);
  //slow_move(left, 45, 10);
}

void drop(int middle_angle) {
  //slow_move(left, 10, 45);
  slow_move(middle, 90, middle_angle);
  slow_move(right, 90, 170);
  slow_move(claw, 60, 110);
  slow_move(right, 170, 90);
  slow_move(claw, 110, 60);
  slow_move(middle, middle_angle, 90);
  //slow_move(left, 45, 10);
}

void laugh(){
  for (int i = 1; i < 8; i++) {
    claw.write(160);
    delay(100);
    claw.write(25);
    delay(100);
  }
}

//Ranges middle [0,180], left [0, 90], right [0, 180]
