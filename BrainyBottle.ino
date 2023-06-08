// program for ESP32 4 sensors

#include <WiFi.h> 
#include "ThingSpeak.h"  
String apiKey = "J1OYALRV15EHAIIJ";//"JL2QOXS4MCBKCG4G";     //  Enter your Write API key from ThingSpeak
const char *ssid =  "maniraj";     // replace with your wifi ssid and wpa2 key
const char *pass =  "IMANIRAJ";
const char* server = "api.thingspeak.com";
const char * myWriteAPIKey = "T24JHK0L4IP0HRCU";//"JL2QOXS4MCBKCG4G";
unsigned long myChannelNumber = 1951205;//1809084;  
WiFiClient client;
void setup()
{
  pinMode(26,INPUT);//TERBIDITY
  pinMode(34,INPUT);//PH SENSOR
  pinMode(25,INPUT);//TDS sensor
  pinMode(27,INPUT);//Temperature
  Serial.begin(115200);
  Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
       while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
      ThingSpeak.begin(client);

}

void loop() 
{
int c= analogRead(26);
float b= analogRead(34);
int e= analogRead(25);
int a= analogRead(27);

//float b=(float)b*5.0/1024/6; //convert the analog into millivolt
//b=3.5*b; 

Serial.print("TEMPARETURE :");
Serial.println(a); 
Serial.print("PH :");
Serial.println(b);
Serial.print("TURBIDITY :");
Serial.println(c);
Serial.print("TDS  :");
Serial.println(e);

ThingSpeak.writeField(myChannelNumber, 1, a, myWriteAPIKey);    
ThingSpeak.writeField(myChannelNumber, 2, b, myWriteAPIKey);  
ThingSpeak.writeField(myChannelNumber, 3, c, myWriteAPIKey); 
ThingSpeak.writeField(myChannelNumber, 4, e, myWriteAPIKey);   
delay(1000); 
}
