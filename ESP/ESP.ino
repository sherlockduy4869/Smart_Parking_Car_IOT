#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Servo.h>    
#include <Arduino_JSON.h>
#include <ESP8266WiFiMulti.h>

int led_full = D7;
int servo_checkout = D6; 

Servo myservo; 
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "CAFE 205";
const char* password = "tohuu205";

// Your IP address or domain name with URL path
const char* serverName = "http://iotprojectvnuk.atwebpages.com/updateData.php";
const char* serverName_payment = "http://iotprojectvnuk.atwebpages.com/payment_status.php";

// Update interval time set to 5 seconds
const long interval = 5000;
unsigned long previousMillis = 0;

int servo_not_allow = 10;
int servo_allow = 180;

String outputsState;

void setup() {
  Serial.begin(57600);
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  myservo.attach(servo_checkout); 
  myservo.write(servo_allow);

  pinMode(led_full, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if ((WiFiMulti.run() == WL_CONNECTED)) {
      outputsState = httpGETRequest(serverName_payment);
      // Serial.println(outputsState);
      JSONVar myObject = JSON.parse(outputsState);
  
      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }
    
      // Serial.print("JSON object = ");
      // Serial.println(myObject);
    
      // myObject.keys() can be used to get an array of all the keys in the object
      JSONVar keys = myObject.keys();
      String value;

      for (int i = 0; i < keys.length(); i++) {
        value = JSON.stringify(myObject[keys[i]]);

        Serial.print(value);
        if (value == "\"yes\""){
          myservo.write(servo_allow);
          digitalWrite(led_full, HIGH);
          delay(500);
        }else{
          myservo.write(servo_not_allow);
          digitalWrite(led_full, LOW);
          delay(500);
        }
      }
      
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
  postData();
}

String httpGETRequest(const char* serverName_payment) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName_payment);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    payload = http.getString();
  }
  http.end();

  return payload;
}

void postData(){
  WiFiClient client;
  HTTPClient http;

  String postData = "";

  if (Serial.available()) {
    while (Serial.available()) { //x??a h???t b??? ?????m
      postData = Serial.readString();
    }
  }

  // Serial.println(postData);

  http.begin(client,serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);
  String payload = http.getString();

  http.end();  
  delay(5000);
}

