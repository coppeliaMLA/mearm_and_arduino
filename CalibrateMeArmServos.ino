#include <Servo.h>

Servo middle, left, right, claw ;  // creates 4 "servo objects"

void setup()
{
  Serial.begin(9600);
  middle.attach(8);  // attaches the servo on pin 11 to the middle object
  left.attach(10);  // attaches the servo on pin 10 to the left object
  right.attach(11);  // attaches the servo on pin 9 to the right object
  claw.attach(9);  // attaches the servo on pin 6 to the claw object
}

void loop()
{
  //middle.write(0); // sets the servo position according to the value(degrees)
  //left.write(90);
  //delay(2000);
  //middle.write(90);
  //middle.write(100); // sets the servo position according to the value(degrees)
  //delay(3000);
  //left.write(30); // does the same
  right.write(60); // and again
  claw.write(35); // yes you've guessed it
  middle.write(30);
  left.write(90);
  //right.write(90);
  delay(1000); // doesn't constantly update the servos which can fry them
  slow_move(middle, 30, 180);
  claw.write(90);
  slow_move(left, 90, 160);
  delay(500);
  claw.write(25);
  slow_move(left, 160, 90);
  slow_move(right, 60, 110);
  slow_move(middle, 180, 30);
  slow_move(left, 90, 160);
  claw.write(90);
  slow_move(left, 160, 90);
  claw.write(25);
  slow_move(right, 110, 60);
  claw.write(25);
  delay(100);
  claw.write(90);
  delay(100);
  claw.write(25);
  delay(100);
  claw.write(90);
  delay(100);
  claw.write(25);
  delay(100);
  claw.write(90);
  delay(100);
  claw.write(25);
  delay(100);
  claw.write(90);

 
}

void slow_move(Servo &the_servo, int x, int y) {
  the_servo.write(x);
  int i;
  if (x < y) {
    for (i = x; i < y; i++) {
      the_servo.write(i);
      delay(25);
    }
  } else {
    for (i = x; i > y; i--) {
      the_servo.write(i);
      delay(25);
    }
  }

}


void swoop() {
  int i;
    for (i = 90; i < 160; i++) {
      middle.write(i);
      left.write(i);
      delay(25);
    }
}

