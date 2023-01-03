#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
SoftwareSerial mySerial(0, 1);  // RX, TX

#define servo_entrance 11  // Servo entrance
#define infrared_entrance 10

#define infrared_slot_1 9
#define infrared_slot_2 8
#define infrared_slot_3 7
#define infrared_slot_4 6

int servo_not_allow = 5;
int servo_allow = 95;

void setup() {
  // ENTRANCE AREA
  myservo.attach(servo_entrance);
  pinMode(infrared_entrance, INPUT);
  Serial.begin(57600);
  mySerial.begin(57600);

  pinMode(infrared_slot_1, INPUT);
  pinMode(infrared_slot_2, INPUT);
  pinMode(infrared_slot_3, INPUT);
  pinMode(infrared_slot_4, INPUT);
}

void loop() {
  slot_parking();
}

void slot_parking() {

  String slot_1 = "available";
  String slot_2 = "available";
  String slot_3 = "available";
  String slot_4 = "not";

  int sensor_slot_1 = digitalRead(infrared_slot_1);
  int sensor_slot_2 = digitalRead(infrared_slot_2);
  int sensor_slot_3 = digitalRead(infrared_slot_3);
  int sensor_slot_4 = digitalRead(infrared_slot_4);

  if (sensor_slot_1 == 1) {
    slot_1 = "available";
  } else {
    slot_1 = "not";
  }

  if (sensor_slot_2 == 1) {
    slot_2 = "available";
  } else {
    slot_2 = "not";
  }

  if (sensor_slot_3 == 1) {
    slot_3 = "available";
  } else {
    slot_3 = "not";
  }
  if (sensor_slot_4 == 1) {
    slot_4 = "not";
  } else {
    slot_4 = "not";
  }

  String send_data = "slot_1=" + slot_1 + "&slot_2=" + slot_2 + "&slot_3=" + slot_3 + "&slot_4=" + slot_4;
  if (send_data == "slot_1=not&slot_2=not&slot_3=not&slot_4=not") {
    myservo.write(servo_not_allow);
    delay(2000);
  } else {
    int sensorValue = digitalRead(infrared_entrance);
    // Serial.print("Gia tri cam bien:");
    // Serial.println(digitalRead(servo_entrance));  //Nếu sensor = 1 thì không phát hiện vật cản, nếu sensor = 0 thì phát hiện vật cản.
    if (sensorValue == 0) {
      myservo.write(servo_allow);
      delay(1000);
    } else {
      myservo.write(servo_not_allow);
      delay(1000);
    }
  }

  mySerial.print(send_data);
  delay(4000);
  Serial.println(send_data);
}
