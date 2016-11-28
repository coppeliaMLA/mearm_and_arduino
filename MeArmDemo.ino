#include <Servo.h>

Servo middle, left, right, claw ;  // creates 4 "servo objects"

void setup()
{
  Serial.begin(9600);
  middle.attach(8);  
  left.attach(10);  
  right.attach(11); 
  claw.attach(9); 
    left.write(30);
  right.write(90);
}

void loop()
{
  move_to(0, 20, 150);
  move_to(180, 40, 90);
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


void move_to(int target_middle, int target_left, int target_right) {
  int current_middle = middle.read();
  int current_left = left.read();
  int current_right = right.read();
  Serial.println( current_middle);
  Serial.println( current_left);
  Serial.println( current_right);
  int range_middle = target_middle - current_middle;
  int range_left = target_left - current_left;
  int range_right = target_right - current_right;
  int abs_range_middle = abs(range_middle);
  int abs_range_left = abs(range_left);
  int abs_range_right = abs(range_right);
  float inc_middle = range_middle/abs_range_middle;
  float inc_left = (float) range_left/(float) abs_range_middle;
  float inc_right = (float) range_right/(float) abs_range_middle;

  int i;
    for (i = 1; i < abs_range_middle; i++) {
      middle.write(current_middle+i*inc_middle);
      left.write(current_left+i*inc_left);
      right.write(current_right+i*inc_right);
       Serial.println("middle");
        Serial.println(current_middle+i*inc_middle);
        Serial.println("left");
        Serial.println(inc_left);
      delay(15);
    }
}

