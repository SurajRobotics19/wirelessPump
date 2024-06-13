#include <Arduino.h>
#include <wifi_setup.h>
#include<mqtt.h>

#define LED_PIN 2 //pin D4 in esp8266

// to handle received messages from subscribe topics
// calback function is activated when a message is received, doesnt have to be in the loop. 
void callback (char* topic, byte* payload, unsigned int length){

    //convert payload to string 
    Serial.print("Message received from : ");
    Serial.print(topic);
    Serial.print(". Message : ");
    String message;
    for (int i = 0; i < length; i++){
        message +=(char)payload[i];
    }
    Serial.println(message);

    if (message == "ON") {
        digitalWrite(ledPin, HIGH);  // Turn the LED on
        Serial.print("The pump is ON");
    } else if (message == "OFF") {
        digitalWrite(ledPin, LOW);  // Turn the LED off
        Serial.print("The pump is OFF");
    }

}


void setup(){

    Serial.begin(115200);
    wifi_setup();  // Connect to WiFi using the function from wifi.h
    mqttClient.setServer(mqtt_server, mqtt_port);
    mqttClient.setCallback(callback);  // Set up the MQTT callback
    connectToMQTT();  // Connect to MQTT using the function from mqtt.h  
}




void loop() {
    if (!mqttClient.connected()) {
        connectToMQTT();
    }
    mqttClient.loop();  // Processes incoming messages and maintains the connection
}





