#include <IOXhop_FirebaseESP32.h>
#include <WiFi.h> 


#define FIREBASE_HOST "https://senaitcc-dbfc1-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "7xGw14DVSJNkzHv9qyWY0o4W2YubT8CP8CulenD0"
#define WIFI_SSID "WIFI_ADM_CFP117"                   
#define WIFI_PASSWORD "CnF@Pm1!1j7@AfD3Mt"
String fireStatus = "";  
void setup() {

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando");
  while (WiFi.status() !=WL_CONNECTED) 
  Serial.println();
  Serial.print("conectado");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("Morpheuzada/RESET", "OFF");
}

  
void loop() { 
  fireStatus = Firebase.getString("Morpheuzada/RESET");
  if (fireStatus == "true") {
    Serial.println("REINICIANDO");
    ESP.restart();
}}
