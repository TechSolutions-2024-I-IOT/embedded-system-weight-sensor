#ifndef CONFIG_H
#define CONFIG_H

// WiFi configuration
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// Backend URL
#define EDGE_BACKEND_URL "https://taskedgelayerservice.azurewebsites.net/api/v1/sensor-data"

// Sensor pins
const int DOUT_PINS[] = {19, 21, 17, 25, 4, 14};
const int CLK_PINS[] = {18, 22, 16, 26, 0, 12};
const int NUM_SENSORS = 6;

// Calibration factor
#define CALIBRATION_FACTOR 420.00

#endif // CONFIG_H
