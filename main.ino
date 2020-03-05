#include <dht.h>
int LED = 13;
int smokeA0 = A0;
#define FLAME 3

dht DHT;

#define DHT22_PIN 7

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(FLAME, INPUT);
  digitalWrite(13, '0');
}

void loop()
{
  int chk = DHT.read11(DHT22_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1050);

 
  int fire = digitalRead(FLAME);


  if( fire == HIGH)
  {
    digitalWrite(LED,LOW);
    Serial.println("Fire! Fire!");
  }else{
    digitalWrite(LED,HIGH); 
    Serial.println("Peace");}
 
  if(((DHT.temperature>32)||(fire==LOW))&&(DHT.humidity>50))
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(100);
}




