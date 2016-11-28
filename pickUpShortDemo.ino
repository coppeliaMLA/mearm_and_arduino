#include <Servo.h>

Servo middle, left, right, claw ;  // creates 4 "servo objects"

//positions 30, 45, 60, 75, 90, 105, 120, 135, 150

void setup()
{
  middle.attach(8);  
  left.attach(10);  
  right.attach(11); 
  claw.attach(9); 
  claw.write(90);
  middle.write(90);
  left.write(45);
  right.write(90);
}

void loop()
{

 // 4 to 9
 grab(75);
 drop(150);

 // 1 to 8
 grab(75);
 drop(135);

 // 2 to 1
 grab(75);
 drop(30);

 // 6 to 2
 grab(75);
 drop(45);

 // 9 to 6
 grab(75);
 drop(105);

 //Celebrate

 slow_move(left, 45, 5);
 laugh();
 
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
