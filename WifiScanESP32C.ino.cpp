/* ESP32 WiFi Scanning example */

#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciant WiFi...");
  WiFi.mode(WIFI_STA);
  Serial.println("Preparació feta!");
}

void loop() {
  Serial.println("Escanejant...");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("Escanejat fet!");
  if (n == 0) {
    Serial.println("No s'han trobat xarxes.");
  } else {
    Serial.println();
    Serial.print(n);
    Serial.println(" Xarxes trobades");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}