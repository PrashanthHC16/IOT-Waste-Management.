#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

long  i;
int j;
long ultrason_16() {
   long duration, distance;
   digitalWrite(16,LOW);
   delayMicroseconds(2);
   digitalWrite(16, HIGH);   delayMicroseconds(10);
   digitalWrite(16, LOW);
   duration = pulseIn(5, HIGH);
   distance = duration * 340 / (2 * 10000);
   return distance;
}

WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

void setup()
{
  i = 0;
  pinMode(16, OUTPUT);
  pinMode(5, INPUT);
    WiFi.disconnect();
   WiFi.begin("Redmi","b4a9515c2b92");

}


void loop()
{
///////////////////////////////////////////////////////ultrasonic sensor
    i = ultrason_16();
    j=0;
    if (client.connect("api.thingspeak.com",80)) 
    {
      writeAPIKey = "key=JYLKR4WVJ5NPEPOC";
      tsfield1Name = "&field1=10";
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "FBHFNS2Y6ZK3UQOO";
      request_string += "&";
      request_string += "field1";
      request_string += "=";
      request_string += i;
      http.begin(request_string);
      http.GET();
      http.end();
      
    }
        if (15 > i) 
        {
            j++;
        }
delay(10000);
    
      
      
////////////////////////////////////////////////////////////////////Gas sensor
    i=analogRead(A0);
    if (client.connect("api.thingspeak.com",80))
    {
      writeAPIKey = "key=JYLKR4WVJ5NPEPOC";
      tsfield1Name = "&field1=10";
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "FBHFNS2Y6ZK3UQOO";
      request_string += "&";
      request_string += "field2";
      request_string += "=";
      request_string += i;
      http.begin(request_string);
      http.GET();
      http.end();
     
    }
      if (350 < i) 
        {
        j++;
        }
 delay(10000);
//////////////////////////////////////////////////////////attention update
     if (client.connect("api.thingspeak.com",80)) 
     {
        if (j>0) 
        {
        writeAPIKey = "key=JYLKR4WVJ5NPEPOC";
        tsfield1Name = "&field1=10";
        request_string = thingSpeakAddress;
        request_string += "key=";
        request_string += "FBHFNS2Y6ZK3UQOO";
        request_string += "&";
        request_string += "field3";
        request_string += "=";
        request_string += 1;
        http.begin(request_string);
        http.GET();
        http.end();
        }
       else 
       {
        writeAPIKey = "key=JYLKR4WVJ5NPEPOC";
        tsfield1Name = "&field1=10";
        request_string = thingSpeakAddress;
        request_string += "key=";
        request_string += "FBHFNS2Y6ZK3UQOO";
        request_string += "&";
        request_string += "field3";
        request_string += "=";
        request_string += 0;
        http.begin(request_string);
        http.GET();
        http.end();
        }
  delay(10000);
    }
}
