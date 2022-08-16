#include "gcode.h"

void sendGcode(char** data){
  char *comando;
  char separador[3] = "\\n";
  comando = strtok(data[1], separador);

  //limpar lixo
  while(Serial.available() > 0){
    String lixo = Serial.readString();
  }
  
  do {
    Serial.println(comando);
    comando = strtok(NULL, separador);
    while(1){
      // check if data is available:
      if(Serial.available() > 0){
        // read the incoming string:
        String incomingString = Serial.readStringUntil('\n');
        // Checks if the string read contains "Idle" which means the last command finished execution
        if(incomingString[1] == 'I' && incomingString[2] == 'd'){ break; } // "Idle"
      }
      else { 
        //Envia comando para verificar o status da CNC
        Serial.println("?"); 
        delay(250);
      }      
    }
    
  } while(comando != NULL);
  Serial.println("Finalizado.");
}

void handleEvent(unsigned char* payload){
  char *data[2];
  strtok((char*)payload, "\"");
  data[0] = strtok(NULL, "\"");
  strtok(NULL, "\"");
  data[1] = strtok(NULL, "\"");

  if(strcmp(data[0],"gcode") == 0){
    sendGcode(data);
  }
}
