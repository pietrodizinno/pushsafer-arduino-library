#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Pushsafer.h>

// Initialize Wifi connection to the router
char ssid[] = "ssid";     // your network SSID (name)
char password[] = "password"; // your network key

#define PushsaferKey "XXXXXXXXXXXXX"

WiFiClientSecure client;
Pushsafer pushsafer(PushsaferKey, client);

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pushsafer.debug = true;

  struct PushSaferInput input;
  input.message = "Hello!";
  input.sound = "8";
  input.vibration = "1";
  input.icon = "1";
  input.device = "a";

  // Other optional Options
  // input.title;
  // input.url;
  // input.urlTitle;
  // input.picture;

  Serial.println(pushsafer.sendEvent(input));
  Serial.println("Sent");
}

void loop() {
}
