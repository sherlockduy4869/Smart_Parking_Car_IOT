#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "CAFE 205";
const char* password = "tohuu205";

// Your IP address or domain name with URL path
const char* serverName = "http://iotprojectvnuk.atwebpages.com/updateData.php";

// Update interval time set to 5 seconds
const long interval = 5000;
unsigned long previousMillis = 0;

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
}

void loop() {
  // unsigned long currentMillis = millis();
  
  // if(currentMillis - previousMillis >= interval) {
  //    // Check WiFi connection status
  //   if ((WiFiMulti.run() == WL_CONNECTED)) {
  //     outputsState = httpGETRequest(serverName);
  //     Serial.println(outputsState);
  //     JSONVar myObject = JSON.parse(outputsState);
  
  //     // JSON.typeof(jsonVar) can be used to get the type of the var
  //     if (JSON.typeof(myObject) == "undefined") {
  //       Serial.println("Parsing input failed!");
  //       return;
  //     }
    
  //     Serial.print("JSON object = ");
  //     Serial.println(myObject);
    
  //     // myObject.keys() can be used to get an array of all the keys in the object
  //     JSONVar keys = myObject.keys();
    
  //     for (int i = 0; i < keys.length(); i++) {
  //       JSONVar value = myObject[keys[i]];
  //       Serial.print("GPIO: ");
  //       Serial.print(keys[i]);
  //       Serial.print(" - SET to: ");
  //       Serial.println(value);
  //       pinMode(atoi(keys[i]), OUTPUT);
  //       digitalWrite(atoi(keys[i]), atoi(value));
  //     }
  //     // save the last HTTP GET Request
  //     previousMillis = currentMillis;
  //   }
  //   else {
  //     Serial.println("WiFi Disconnected");
  //   }
  // }
  postData();
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void postData(){
  WiFiClient client;
  HTTPClient http;

  String postData = "";

  if (Serial.available()) {
    while (Serial.available()) { //xóa hết bộ đệm
      postData = Serial.readString();
    }
  }

  http.begin(client,serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.println(payload);
  http.end();  
  delay(15000);
}

