#include "wifi.h"
#include "socketio.h"

void setup() {
    Serial.begin(115200);
    Serial.println("lixo");
    delay(250);
    init_wifi();
    init_socket();
}

//Conexão do wi-fi
unsigned long previousmillis = 0;
void loop()
{
  connection_socket();
  unsigned long currentmillis = millis();

  if ((WiFi.status() != WL_CONNECTED) && (currentmillis - previousmillis >= 1000))
  {
    //Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    //    WiFi.reconnect();
    init_wifi();
    previousmillis = currentmillis;
  }

  else if (currentmillis - previousmillis >= 1000)
  {
    if ((WiFi.status() != WL_CONNECTED))
    {
      Serial.println("Sem internet");
    }
    else
    {
      previousmillis = currentmillis;
    }
  }
}
