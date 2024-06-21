#include "WiFiBackendManager.h"
#include <Arduino.h>

WiFiBackendManager::WiFiBackendManager(const char* ssid, const char* password, const char* backendUrl)
  : ssid(ssid), password(password), backendUrl(backendUrl) {}

void WiFiBackendManager::connectWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());
}

void WiFiBackendManager::connectBackend() {
  client_http.begin(backendUrl); // Specify the URL
  client_http.addHeader("Content-Type", "application/json"); // Add header for JSON
}

void WiFiBackendManager::sendData(int occupiedCount) {
  // Prepare JSON data
  String jsonData = "{\"occupied_seats\":" + String(occupiedCount) + "}";

  // Send HTTP POST request
  int httpCode = client_http.POST(jsonData);

  if (httpCode > 0) {
    String payload = client_http.getString();
    Serial.println("\nStatus code: " + String(httpCode));
    Serial.println("Payload: " + payload);
  } else {
    Serial.println("Error sending data to backend");
  }
}
