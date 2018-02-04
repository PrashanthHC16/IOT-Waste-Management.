#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

long  i;
WiFiClient client;

String MakerIFTTT_Key ;
;String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void setup()
{
  i = 0;
  ThingSpeak.begin(client);

    WiFi.disconnect();
   WiFi.begin("Redmi","b4a9515c2b92");

}


void loop()
{

    if (client.connect("api.thingspeak.com",80)) {
      i = (ThingSpeak.readIntField(257355,3));
      if (i == 1) {
        if (client.connect("maker.ifttt.com",80)) {
          MakerIFTTT_Key ="iNVPaDINPh1ORlcI4eUZn399RTVby0WYXUNiSmR2_08";
          MakerIFTTT_Event ="node1";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);



        }

      }

    }
    if (client.connect("api.thingspeak.com",80)) {
      i = (ThingSpeak.readIntField(257970,3));
      if (i == 1) {
        if (client.connect("maker.ifttt.com",80)) {
          MakerIFTTT_Key ="iNVPaDINPh1ORlcI4eUZn399RTVby0WYXUNiSmR2_08";
          MakerIFTTT_Event ="node2";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);



        }

      }

    }
    if (client.connect("api.thingspeak.com",80)) {
      i = (ThingSpeak.readIntField(257981,3));
      if (i == 1) {
        if (client.connect("maker.ifttt.com",80)) {
          MakerIFTTT_Key ="iNVPaDINPh1ORlcI4eUZn399RTVby0WYXUNiSmR2_08";
          MakerIFTTT_Event ="node3";
          p = post_rqst;
          p = append_str(p, "POST /trigger/");
          p = append_str(p, MakerIFTTT_Event);
          p = append_str(p, "/with/key/");
          p = append_str(p, MakerIFTTT_Key);
          p = append_str(p, " HTTP/1.1\r\n");
          p = append_str(p, "Host: maker.ifttt.com\r\n");
          p = append_str(p, "Content-Type: application/json\r\n");
          p = append_str(p, "Content-Length: ");
          content_length_here = p;
          p = append_str(p, "NN\r\n");
          p = append_str(p, "\r\n");
          json_start = p;
          p = append_str(p, "{\"value1\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value2\":\"");
          p = append_str(p, "");
          p = append_str(p, "\",\"value3\":\"");
          p = append_str(p, "");
          p = append_str(p, "\"}");

          compi= strlen(json_start);
          content_length_here[0] = '0' + (compi/10);
          content_length_here[1] = '0' + (compi%10);
          client.print(post_rqst);



        }

      }

    }

}