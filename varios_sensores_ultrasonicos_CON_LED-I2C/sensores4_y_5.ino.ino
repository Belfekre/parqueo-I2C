#include <NewPing.h>
#include <Wire.h>

// se definen los pines para el sensor 4
#define TRIGGER_sensor_4  6
#define ECHO_sensor_4     7
/*
// se definen los pines para el sensor 5 
#define TRIGGER_sensor_5  8
#define ECHO_sensor_5     9
*/

// se define el LED VERDE 4
const int LEDV4=4;

// se define el LED ROJO 4
const int LEDR4=5;
/*
// se define el LED VERDE 5
const int LEDV5=4;

// se define el LED ROJO 5
const int LEDR5=5;*/

#define MAX_DISTANCE 200
 
NewPing sensor_4(TRIGGER_sensor_4, ECHO_sensor_4, MAX_DISTANCE);
//NewPing sensor_5(TRIGGER_sensor_5, ECHO_sensor_5, MAX_DISTANCE);
byte DATO4;
//byte DATO5;
byte entra;

void setup() {
  Serial.begin(9600);
  // mandamos un comando para la hiperterminal limpiar pantalla
Serial.write(12);

pinMode(LEDV4,OUTPUT);
pinMode(LEDR4,OUTPUT);          
/*
pinMode(LEDV5,OUTPUT);
pinMode(LEDR5,OUTPUT);*/

// DEFINIMOS EL CODIGO DEL ESCLAVO
Wire.begin(0x01);// identificamos el nombre
Wire.onReceive(EntSol);
Wire.onRequest(Peti);
}

void loop() {

  if (sensor_4.ping_cm()<=10)
  {
    delay(500);
    Serial.print(" OCUPADO4  ");  
    Serial.println(sensor_4.ping_cm());  
    
    digitalWrite(LEDR4,HIGH);
    delay(500);
    digitalWrite(LEDV4,LOW);
    delay(500);  
    DATO4=sensor_4.ping_cm();
  } 
 else
  {
    delay(500);
    Serial.print(" LIBRE4  ");  
    Serial.println(sensor_4.ping_cm());
   
    digitalWrite(LEDV4,HIGH);
    delay(500);
    digitalWrite(LEDR4,LOW);
    delay(500);
    DATO4=sensor_4.ping_cm();
  } 

 /*  if (sensor_5.ping_cm()<=10)
  {
    delay(1000);
    Serial.print("OCUPADO5");  
    Serial.println(sensor_5.ping_cm());
    DATO5=sensor_5.ping_cm();

    digitalWrite(LEDR5,HIGH);
    delay(1000);
    digitalWrite(LEDV5,LOW);
    delay(1000);
    
  } 
 else
  {
    delay(1000);
    Serial.print(" LIBRE5  ");  
    Serial.println(sensor_5.ping_cm());
    DATO5=sensor_5.ping_cm();

    digitalWrite(LEDV5,HIGH);
    delay(1000);
    digitalWrite(LEDR5,LOW);
    delay(1000);
  } */
}

void EntSol(int re)
{
while (Wire.available())
{
  entra=Wire.read();
}
Serial.println(entra);
}

void Peti()
{
Wire.write(DATO4);
}





