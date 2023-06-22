#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "M12"  // Replace with your network credentials
#define STAPSK  "mohan2003"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
 
void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}
 
void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
        pinMode(5,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(7,OUTPUT);
        pinMode(2,INPUT);
        pinMode(3,INPUT);
        pinMode(4,INPUT);
}

void loop() {
        OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
 //-------------------//
  digitalWrite(5,digitalRead(4));
  digitalWrite(6,digitalRead(!2));
  digitalWrite(7,digitalRead(!3));
  delay(1);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  int state1 =digitalRead(2);
  int state2 =digitalRead(3);
  int state3 =digitalRead(4);
 
Serial.print(state3);
 
Serial.print(state2);
 
Serial.println(state1);
  if (state3 == 0 &&
state2 == 0 && state1 == 0) {
    delay(1000);
   
Serial.println("011");
  }
  else if (state3 ==
0 && state2 == 1 && state1 == 1) {
    delay(1000);
   
Serial.println("101");
  }
  else if (state3 ==
1 && state2 == 0 && state1 == 1) {
    delay(1000);
   
Serial.println("000");
  }
}

