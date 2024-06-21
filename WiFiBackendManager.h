#ifndef WIFI_BACKEND_MANAGER_H
#define WIFI_BACKEND_MANAGER_H

#include "WiFi.h"
#include <HTTPClient.h>

class WiFiBackendManager {
  private:
    HTTPClient client_http;
    const char* ssid;
    const char* password;
    const char* backendUrl;

  public:
    WiFiBackendManager(const char* ssid, const char* password, const char* backendUrl);
    void connectWifi();
    void connectBackend();
    void sendData(int occupiedCount);
};

#endif
