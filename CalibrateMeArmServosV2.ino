#include <Servo.h>

Servo middle, left, right, claw ;  // creates 4 "servo objects"

void setup()
{
  Serial.begin(9600);
  middle.attach(8);  
  left.attach(10);  
  right.attach(11); 
  claw.attach(9); 
  left.write(45);
  right.write(90);
}

void loop()
{
  //middle.write(90);
  slow_move(right, 90, 180);
  slow_move(right, 180, 90);
  delay(1000);
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

//Ranges middle [0,180], left [0, 90], right [0, 180]
