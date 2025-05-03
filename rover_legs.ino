#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the minimum and maximum pulse width corresponding to the desired angle range
#define SERVO_MIN_PULSE_WIDTH  150 // Min pulse width out of 4096
#define SERVO_MAX_PULSE_WIDTH  600 // Max pulse width out of 4096

// Define the minimum and maximum angles supported by the servo
#define SERVO_MIN_ANGLE 0   // Minimum angle in degrees
#define SERVO_MAX_ANGLE 180 // Maximum angle in degrees

// Function to set the angle of the servo on a specified channel
void setServoAngle(uint8_t channel, uint8_t angle) {
  // Convert the angle to pulse width
  uint16_t pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  
  // Set the pulse width for the specified channel
  pwm.setPWM(channel, 0, pulse_width);
}

void setup() {
  // Initialize the PWM servo driver
  pwm.begin();
  
  // Set the PWM frequency (default is 50 Hz)
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
   setServoAngle(7, 60); 
    setServoAngle(6, 120);   // 0 6
  delay(1000); 
   setServoAngle(5, 0); 
    setServoAngle(4,180);   // 0 6
  delay(1000);  // 0 6
   setServoAngle(10, 90);   // 0 6
  delay(1000);
   setServoAngle(8,0); 
   delay(1000);// 180 7
   setServoAngle(10, 90);   // 0 6
  delay(1000);
  // Set the angle of servo 0 to 0 degrees
  setServoAngle(8, 90);
  delay(1000); // 180 7
  setServoAngle(11, 30);   // 0 6
  delay(1000);
  setServoAngle(11, 150); // 180 7
  //setServoAngle(4, 90);   // 0 6
  delay(3000);
 /*  setServoAngle(5, 180); // 180 7
  setServoAngle(4, 0);   // 0 6
  delay(1000);
   setServoAngle(7, 180); // 180 7
  setServoAngle(6, 0);   // 0 6
  delay(1000);
   setServoAngle(10, 180); // 180 7
  //setServoAngle(4, 0);   // 0 6
  delay(5000);
  //setServoAngle(10, 180);
  //setServoAngle(6, 90);*/
  

  //setServoAngle(2, 0);  
}