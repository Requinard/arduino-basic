#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "settings.h"

/* Set these to your desired credentials. */
const char *ssid = "requisuit";
const char *password = "prinspils";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setupWifi(){
	// Connect to WiFi network
	delay(1000);
	Serial.println();
	Serial.print("WIFI: Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("WIFI: HTTP server started");
}

void jobWifi(){
	server.handleClient();
}
