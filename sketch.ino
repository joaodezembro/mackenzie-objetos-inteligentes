#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4 
#define DHTTYPE DHT22 
#define RELAY_PIN 2
#define LDR_PIN 34
#define MQTT_SERVER "your_mqtt_server.com"
#define MQTT_PORT 1883
#define MQTT_USER "your_mqtt_username"
#define MQTT_PASSWORD "your_mqtt_password"
#define TOPIC "environment_monitoring"
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != 1) {
    delay(500);
  }
  
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Callback");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    messageTemp += (char)payload[i];
  }

  if(messageTemp == "ON"){
    digitalWrite(RELAY_PIN, LOW);
  }
  else if(messageTemp == "OFF"){
    digitalWrite(RELAY_PIN, HIGH);
  }
}

void reconnect() {
  // Loop until we're reconnected
  int retries = 0;
  while (!client.connected() && retries < 1) {
    Serial.print("Tentando conexão MQTT...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falha");
      Serial.println(client.state());
      // Wait 5 seconds before retrying
      delay(5000);
      retries++;
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int lightValue = analogRead(LDR_PIN);

  String msg = "Umidade: " + String(h) + "%\t";
  msg += "Temperatura: " + String(t) + "C\t";
  msg += "Luz: " + String(lightValue);

  Serial.print("Log: ");
  Serial.println(msg);

  char message[58];
  msg.toCharArray(message,58);
  client.publish(TOPIC, message);

  delay(1500);
}
