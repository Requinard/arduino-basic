#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "DnD The MMO RPG Adventure";
const char *password = "runescape";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setupWifi(){
  // Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

// Start the server
server.begin();
server.on("/", handleRoot);
Serial.println("Server started");

// Print the IP address
Serial.println(WiFi.localIP());
}

void jobWifi(){
  server.handleClient();
}
