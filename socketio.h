#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include <Arduino.h>
#include <WebSocketsClient.h>
#include <SocketIOclient.h>
#include <ArduinoJson.h>
#include "gcode.h"

void init_socket();
void connection_socket();
void send_socket(String info);
void event(const char * payload, size_t length);
void socketIOEvent(socketIOmessageType_t type, uint8_t * payload, size_t length);


#endif
