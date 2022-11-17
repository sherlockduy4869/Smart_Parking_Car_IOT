#include <Servo.h>     
#include <SoftwareSerial.h>

Servo myservo; 
SoftwareSerial mySerial(12, 13); // RX, TX

#define servo_entrance 11 // Servo entrance
#define infrared_entrance 10 

#define infrared_slot_1 9 
#define infrared_slot_2 8 
#define infrared_slot_3 7 
#define infrared_slot_4 6

#define led_slot_1 5
#define led_slot_2 4
#define led_slot_3 3
#define led_slot_4 2

#define led_entrance 1

int servo_not_allow = 5;
int servo_allow = 95;

void setup() { 
    // ENTRANCE AREA    
    myservo.attach(servo_entrance); 
    pinMode(infrared_entrance,INPUT);
    Serial.begin(57600);
    mySerial.begin(57600);

    pinMode(infrared_slot_1,INPUT);
    pinMode(infrared_slot_2,INPUT);
    pinMode(infrared_slot_3,INPUT);
    pinMode(infrared_slot_4,INPUT);

    pinMode(led_slot_1, OUTPUT); 
    pinMode(led_slot_2, OUTPUT); 
    pinMode(led_slot_3, OUTPUT); 
    pinMode(led_slot_4, OUTPUT); 
} 

void loop() { 
    entrance_checking();
    slot_parking();
}

void entrance_checking(){
  //ENTRANCE AREA
    int sensorValue = digitalRead(infrared_entrance);
    Serial.print("Gia tri cam bien:");
    Serial.println(digitalRead(servo_entrance)); //Nếu sensor = 1 thì không phát hiện vật cản, nếu sensor = 0 thì phát hiện vật cản.
    if(sensorValue == 0){
      myservo.write(servo_allow);
    }
    else{
      myservo.write(servo_not_allow);
    }
    delay(2000);
  //
}

void slot_parking(){
    
    String slot_1 = "available";
    String slot_2 = "available";
    String slot_3 = "available";
    String slot_4 = "available";

    int sensor_slot_1 = digitalRead(infrared_slot_1);
    int sensor_slot_2 = digitalRead(infrared_slot_2);
    int sensor_slot_3 = digitalRead(infrared_slot_3);
    int sensor_slot_4 = digitalRead(infrared_slot_4);

    if(sensor_slot_1 == 1){
      digitalWrite(led_slot_1, HIGH); 
      slot_1 = "available";
    }
    else{
      digitalWrite(led_slot_1, LOW); 
      slot_1 = "not";    
    }

    if(sensor_slot_2 == 1){
      digitalWrite(led_slot_2, HIGH); 
      slot_2 = "available";
    }
    else{
      digitalWrite(led_slot_2, LOW); 
      slot_2 = "not";  
    }

    if(sensor_slot_3 == 1){
      digitalWrite(led_slot_3, HIGH); 
      slot_3 = "available";
    }
    else{
      digitalWrite(led_slot_3, LOW); 
      slot_3 = "not";  
    }

    if(sensor_slot_4 == 1){
      digitalWrite(led_slot_4, HIGH); 
      slot_4 = "available";
    }
    else{
      digitalWrite(led_slot_4, LOW); 
      slot_4 = "not";  
    }

    //Sending data to ESP8266
  String send_data = "slot_1=" + slot_1 + "&slot_2=" + slot_2 + "&slot_3=" + slot_3 + "&slot_4=" + slot_4 ;
  //String send_data = "slot1=" + slot_1 + "&slot_2=" + slot_2 + "&slot_3=" + slot_3 + "&slot_4=not" ;
  mySerial.print(send_data);
  Serial.println(send_data);
  delay(2000);

  // if (mySerial.available() > 0) {
  //   String ch;
    //Serial.println("Serial thu 2 gui gia tri: ");
    //đọc giá trị từ Arduino nếu có
    // delay(20);

    // ch = mySerial.readString(); //đọc
    // String value = "Servo_allow";
    // if(ch == ""){
    //   Serial.println("Servo quay veo veo ne");
    //   delay(500);
    // }
    // else{
    //   Serial.println("Servo dong lai ne");
    //   delay(500);
    // }
    // Serial.println(ch == value);
  // }

}


