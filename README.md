# ESP CNC 
![GitHub](https://img.shields.io/github/license/luizalaquini/esp-cnc)
![GitHub repo size](https://img.shields.io/github/repo-size/luizalaquini/esp-cnc)
![GitHub language count](https://img.shields.io/github/languages/count/luizalaquini/esp-cnc)
![GitHub top language](https://img.shields.io/github/languages/top/luizalaquini/esp-cnc)
![GitHub followers](https://img.shields.io/github/followers/luizalaquini?label=follow&style=social)

### Usage
We are using this code in NodeMCU v3 to communicate our CNC with an online server.

### Technologies
- C++
- Arduino IDE

### Behavior
  The esp was programmed with the arduino IDE and has some files. The file esp-cnc.ino is the main one, which has setup and loop structure and simply initializes wi-fi and socket.io and keeps checking if the internet connection is active (trying to reconnect if there is a problem).

The wifi.cpp file is where we enter the name and password of the wifi network that the esp must connect and also where is the logic for making this connection via the <ESP8266WiFi> library.
  
The socketio file manages the websocket connection to the server. It is in him that the server URL is placed, along with the default port 80 for HTTP communication and with the path "/socket.io/?EIO=4", necessary for the connection to work. This file also handles the events received by the server, calling the handleEvent function from the gcode.cpp file. This function makes an initial treatment of the received data, verifying if the event received was called “gcode” and sending it to the sendGcode function if be. sendGcode divides the received string with strtok and sends each command separately. As soon as it sends a command, it waits 250ms and stays sending the character “?” which makes the arduino return to the current position of the CNC. When the CNC finishes executing the command, esp sends the next one, repeating the process until the commands are finished.

### Developers
- Luiza Batista Laquini (LinkedIn: https://www.linkedin.com/in/luizalaquini/)
- Guilherme Goes Zanetti: (LinkedIn: https://www.linkedin.com/in/guilherme-goes-zanetti-0429631a2/)
- Joana Venturin Loureiro
