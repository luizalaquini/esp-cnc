#include "socketio.h"

SocketIOclient socket;

// inicializa o socket.io-client
void init_socket()
{
  socket.begin("server-cnc.herokuapp.com", 80, "/socket.io/?EIO=4");
  //socket.begin("172.20.10.6", 5000, "/socket.io/?EIO=4");

  socket.onEvent(socketIOEvent);

  Serial.println("Configurado o socket.io");

  delay(500);
}

void connection_socket()
{
  socket.loop();
}

void socketIOEvent(socketIOmessageType_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case sIOtype_DISCONNECT:
            Serial.printf("[IOc] [Desconectado]\n");
            break;
        case sIOtype_CONNECT:
            Serial.printf("[IOc] [Conectado ao url: %s]\n", payload);

            // join default namespace (no auto join in Socket.IO V3)
            socket.send(sIOtype_CONNECT, "/");
            break;
        case sIOtype_EVENT:
            Serial.printf("[IOc] get event: %s\n", payload);
            handleEvent(payload);
            break;
        case sIOtype_ACK:
            Serial.printf("[IOc] get ack: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_ERROR:
            Serial.printf("[IOc] get error: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_EVENT:
            Serial.printf("[IOc] get binary: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_ACK:
            Serial.printf("[IOc] get binary ack: %u\n", length);
            hexdump(payload, length);
            break;
    }
}


// envia uma mensagem para o servidor via socket
void send_socket(String info)
{

  DynamicJsonDocument doc(1024);
  JsonArray array = doc.to<JsonArray>();

  array.add("newinfo");

  // add payload (parameters) for the event
  JsonObject param1 = array.createNestedObject();
  param1["now"] = info;

  // JSON to String (serializion)
  String output;
  serializeJson(doc, output);

  // Send event
  socket.sendEVENT(output);

  //  char msg[300];
  //  String infoTosend = "\"" + info + "\"";
  //
  //  infoTosend.toCharArray(msg, 300);
  //
  ////  socket.sendEVENT("newinfo", msg);
  //  socket.sendEVENT(msg);
}

// Recebe algo do servidor
void event(const char *payload, size_t length)
{
  Serial.printf("got message: %s\n", payload);
}
