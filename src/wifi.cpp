#include "wifi.h"
#include "settings.h"

/* Set these to your desired credentials. */
const char *ssid = "requisuit";
const char *password = "prinspils";

ESP8266WebServer server(80);

extern struct Settings settings;

void handleRoot() {
	server.send(200, "text/plain", "connected to RequiSuit v1.0");
}

void handleLed(){
	int readValue = digitalRead(LED_BUILTIN);

	if(readValue == HIGH) digitalWrite(LED_BUILTIN, LOW);
	else digitalWrite(LED_BUILTIN, HIGH);

	server.send(200, "text/plain", "done");
}

/**
* Handle incoming  cheek request.
* Required (in order): red, green, blue
**/
void handleCheeks(){
	if(server.args() == 3 && (
		server.argName(0) == "red" &&
		server.argName(1) == "green" &&
		server.argName(2) == "blue"
	)) {
		Serial.println("Received correct parameters. Setting");
		settings.cheeks.cheek.r = (char) server.arg(0).toInt();
		settings.cheeks.cheek.g = (char)server.arg(1).toInt();
		settings.cheeks.cheek.b = (char)server.arg(2).toInt();

		analogWrite(D4, settings.cheeks.cheek.r);
		analogWrite(D3, settings.cheeks.cheek.g);
		analogWrite(D2, settings.cheeks.cheek.b);

		server.send(200, "text/plain", "Changed Cheek settings");
	} else {
		server.send(400, "text/plain", "Please include red green blue parameters (in that order)");
	}
}

void handleNotFound() {
	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";

	for ( uint8_t i = 0; i < server.args(); i++ ) {
		message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
	}

	server.send ( 404, "text/plain", message );
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
	server.on("/led", handleLed);
	server.on("/cheeks", handleCheeks);
	server.onNotFound(handleNotFound);
	server.begin();
	Serial.println("WIFI: HTTP server started");

	pinMode(D4, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D2, OUTPUT);
}


void jobWifi(){
	server.handleClient();
}
