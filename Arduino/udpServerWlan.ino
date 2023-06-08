#include <WiFiNINA.h> // WLAN-Bibliothek für den Arduino Nano IoT
#include <WiFiUdp.h>  // UDP-Bibliothek für den Arduino Nano IoT

const int ledPin = 13; // Pin 13 für die LED

char ssid[] = "XXXXXXXXXXXXXXXXXXXX"; // your network SSID (name)
char pass[] = "XXXXXXXXXXXXXXXXXXXX"; // your network password (use for WPA, or use as key for WEP)

WiFiUDP Udp; // UDP-Objekt für die Kommunikation

void setup()
{
    pinMode(ledPin, OUTPUT); // LED-Pin als Ausgang festlegen

    // WLAN-Verbindung herstellen
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Verbunden!");

    // UDP-Server starten
    Udp.begin(8888);
}

void loop()
{
    // Auf eingehende UDP-Pakete warten
    int packetSize = Udp.parsePacket();
    if (packetSize)
    {
        char packetData = Udp.read();
        if (packetData == '1')
        {
            digitalWrite(ledPin, HIGH); // LED einschalten
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write("LED eingeschaltet");
            Udp.endPacket();
        }
        else if (packetData == '0')
        {
            digitalWrite(ledPin, LOW); // LED ausschalten
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write("LED ausgeschaltet");
            Udp.endPacket();
        }
    }
}
