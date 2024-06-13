#include <Arduino.h>
#include <WiFi.h>




//const char* ssid = "MFP-Guest24";
//const char* password = "testing123";
const char* ssid = "GFguestwifi_AP";
const char* password = "GF@9300@a";


void wifi_setup() {

 Serial.begin(115200);
 WiFi.begin(ssid,password);
Serial.println("Connecting to WiFi...");
while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
 }
Serial.print("Connected to WiFi!");

}
