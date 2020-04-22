#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "your ssid";
const char* password = "password";
const char* aio_key  = "adafruit io key";
const char* url      = "https://io.adafruit.com/api/v2/{userId}/feeds/{feedId}"; // replace {userId} and {feedId}

void connectToWifi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200); // keep trying
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

// get request to adafruit setting header with aio_key
void makeRequest() {
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-AIO-Key", aio_key);
  
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.println();
    Serial.println(httpCode);
    if (httpCode == 200) {
      Serial.println(http.getString());
    }
  }
}

void setup() {
  Serial.begin(115200);
  while(! Serial); // wait till console up
  
  connectToWifi();
  makeRequest();
}

void loop() {
}
