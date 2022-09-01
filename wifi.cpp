#include "wifi.h"

// Rede UFES: 
// "LPRM6"
// "51752927"

const char *ssid = "belkin.fa8";
const char *password = "ym3ddfed";
unsigned long previousMillis = 0;

void init_wifi()
{
  WiFi.begin(ssid, password);

  unsigned long currentMillis = millis();
  unsigned long previousMillis = millis();

  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 12000)
    {
      previousMillis = currentMillis;
      Serial.println("[Failed to connect]");
      return;
    }
  }

  Serial.println("Connected to the WiFi network");
  delay(500);
}
