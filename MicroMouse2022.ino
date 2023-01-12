
#include "MicroMouseHBridge.h"
// Micromouse pinout
// Left Motor
const uint8_t IN1_pin = 18;  // blue
const uint8_t IN2_pin = 19;  // green
const uint8_t ENA_pin = 16;

// Right Motor
const uint8_t IN3_pin = 20;  // yellow
const uint8_t IN4_pin = 21;  // red
const uint8_t ENB_pin = 17;

// Encoders
const uint8_t left_encoder_A_pin = 23;    // blue IIII
const uint8_t left_encoder_B_pin = 22;    // blue III
const uint8_t right_encoder_A_pin = 38;   // blue II
const uint8_t right_encoder_B_pin = 39;   // blue I

// Ultrasonic Sensor
const uint8_t ultrasonic_pin = 37;    // white

// IR Sensors
const uint8_t IR_left_pin = 14;   // white II
const uint8_t IR_right_pin = 15;  // white I

// Button
//const uint8_t button_pin = 30;  // gray/white

// Dip Switches
const uint8_t dip_1_pin = 6;   // red
const uint8_t dip_2_pin = 7;   // red
const uint8_t dip_3_pin = 8;   // red
const uint8_t dip_4_pin = 9;   // red

// RGB LED
const uint8_t rgb_led_pin = 10;

//internal status led
const uint8_t led_pin = 13;


//hbridge setup

auto hbridge_left  = MicroMouse::HBridge(IN1_pin, IN2_pin, ENA_pin);
auto hbridge_right = MicroMouse::HBridge(IN3_pin, IN4_pin, ENB_pin);

void setup() {
  // put your setup code here, to run once:

  //hbridge_left.spin(50);
  //hbridge_right.spin(50);
  hbridge_left.spin(0);
  hbridge_right.spin(0);
  pinMode(led_pin,OUTPUT);
  pinMode(rgb_led_pin,OUTPUT);
  boolean toggle = false;
  for(int i=0; i<20; i++){ //give user time to disconnect from computer
    delay(100);
    toggle=!toggle;
    digitalWrite(led_pin,toggle);
  }
  //hbridge_left.spin(50);
  //hbridge_right.spin(0);
 }


void loop() {
  //digitalWrite(led_pin, LOW);
  //delay(1000);
  //digitalWrite(led_pin, HIGH);
  //delay(1000);
  // put your main code here, to run repeatedly:
  long distanceus = usrfIn();
  long inch = microsecondsToInches(distanceus);
  Serial.print("inches:");
  Serial.println(inch);
  if (inch < 5){
    digitalWrite(led_pin, HIGH);
    digitalWrite(rgb_led_pin, HIGH);
    hbridge_left.spin(50);
    hbridge_right.spin(-50);
    
  } else {
     digitalWrite(led_pin, LOW);
         digitalWrite(rgb_led_pin, LOW);
     hbridge_left.spin(50);
     hbridge_right.spin(50);
  }
}


long usrfIn(){
  pinMode(ultrasonic_pin,OUTPUT);
  delay(1);
  digitalWrite(ultrasonic_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonic_pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(ultrasonic_pin,LOW);
  pinMode(ultrasonic_pin,INPUT);
  return (pulseIn(ultrasonic_pin, HIGH));
  
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
