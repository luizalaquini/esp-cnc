#include "gcode.h"

void sendGcode(char** data){
  char *comando;
  char separador[3] = "\\n";
  comando = strtok(data[1], separador);
  
  do {
    Serial.println(comando);
    comando = strtok(NULL, separador);
  } while(comando != NULL);
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
