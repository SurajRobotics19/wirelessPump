#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>


const int ledPin = 32; 

//MQTT credentials 
const char* mqtt_server = "192.168.99.133";
const int mqtt_port =1883;
const char* topic = "kalai";


//Initialize MQTT

WiFiClient espClient;
PubSubClient mqttClient(espClient);




void connectToMQTT() {
    while (!mqttClient.connected()) {
        Serial.println("Connecting to MQTT...");
        if (mqttClient.connect("ESP32Client")) {
            Serial.println("connected");
            mqttClient.subscribe(topic);
        } else {
            Serial.print("failed with state ");
            Serial.print(mqttClient.state());
            delay(2000);
        }
    }
}


void publishMessage(const char* topic, const char* message) {
    if (mqttClient.connected()) {
        mqttClient.publish(topic, message);
    }
}

