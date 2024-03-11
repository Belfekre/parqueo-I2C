
#include <NewPing.h> //libreria para detectar varios sensores de ultrasonido
#include <Wire.h> //libreria para la conexion entre arduinos

// se definen los pines para el sensor 1 
#define TRIGGER_sensor_1  2
#define ECHO_sensor_1     3

// se definen los pines para el sensor 2 
#define TRIGGER_sensor_2  8
#define ECHO_sensor_2     9

// se definen los pines para el sensor 3 
#define TRIGGER_sensor_3  10
#define ECHO_sensor_3     11

// se define el LED VERDE 1
const int LEDV1=4;

// se define el LED ROJO 1
const int LEDR1=5;

// se define el LED VERDE 2
const int LEDV2=6;

// se define el LED ROJO 2
const int LEDR2=7;

// se define el LED VERDE 3
const int LEDV3=12;

// se define el LED ROJO 3
const int LEDR3=13;

#define MAX_DISTANCE 200
 
NewPing sensor_1(TRIGGER_sensor_1, ECHO_sensor_1, MAX_DISTANCE);
NewPing sensor_2(TRIGGER_sensor_2, ECHO_sensor_2, MAX_DISTANCE);
NewPing sensor_3(TRIGGER_sensor_3, ECHO_sensor_3, MAX_DISTANCE);
byte sensor_4;
//byte sensor_5;

 
void setup() {
Wire.begin();// ARDUINO MAESTRO
Serial.begin(9600);
  // mandamos un comando para la hiperterminal limpiar pantalla
Serial.write(12);

pinMode(LEDV1,OUTPUT);
pinMode(LEDR1,OUTPUT);          

pinMode(LEDV2,OUTPUT);
pinMode(LEDR2,OUTPUT);

pinMode(LEDV3,OUTPUT);
pinMode(LEDR3,OUTPUT);

}

void loop() {
  
Wire.requestFrom(0x01,8);
  sensor_4=Wire.read();
  Wire.endTransmission();
  
// realizamos la validación de la información recibida
 if (sensor_4<=10)
  {
    delay(500);
    Serial.print(" OCUPADO4 ");  
    Serial.println(sensor_4);  
  } 
 else
  {
    delay(500);
    Serial.print(" LIBRE4  ");  
    Serial.println(sensor_4);  
  }  
  
  
  if (sensor_1.ping_cm()<=10)
  {
    delay(500);
    Serial.print(" OCUPADO1 ");  
    Serial.println(sensor_1.ping_cm());  

    digitalWrite(LEDR1,HIGH);
    delay(500);
    digitalWrite(LEDV1,LOW);
    delay(500);
  } 
 else
  {
    delay(500);
    Serial.print(" LIBRE1  ");  
    Serial.println(sensor_1.ping_cm());

    digitalWrite(LEDV1,HIGH);
    delay(500);
    digitalWrite(LEDR1,LOW);
    delay(500);
  } 


   if (sensor_2.ping_cm()<=10)
  {
    delay(500);
    Serial.print(" OCUPADO2  ");  
    Serial.println(sensor_2.ping_cm());

    digitalWrite(LEDR2,HIGH);
    delay(500);
    digitalWrite(LEDV2,LOW);
    delay(500);
    
  } 
 else
  {
    delay(500);
    Serial.print(" LIBRE2  ");  
    Serial.println(sensor_2.ping_cm());

    digitalWrite(LEDV2,HIGH);
    delay(500);
    digitalWrite(LEDR2,LOW);
    delay(500);
  } 

    if (sensor_3.ping_cm()<=10)
  {
    delay(500);
    Serial.print(" OCUPADO3  ");  
    Serial.println(sensor_3.ping_cm());  

    digitalWrite(LEDR3,HIGH);
    delay(500);
    digitalWrite(LEDV3,LOW);
    delay(500);
    
  } 
 else
  {
    delay(500);
    Serial.print(" LIBRE3  ");  
    Serial.println(sensor_3.ping_cm());  
    
    digitalWrite(LEDV3,HIGH);
    delay(500);
    digitalWrite(LEDR3,LOW);
    delay(500);
  }  

}


/*
delay(2000);
  Serial.print("distancia del sensor 1: ");
  Serial.print(sensor_1.ping_cm());
  Serial.println("cm");


  delay(2000);
  Serial.print("distancia del sensor 2: ");
  Serial.print(sensor_2.ping_cm());
  Serial.println("cm");

  delay(2000);
  Serial.print("distancia del sensor 3: ");
  Serial.print(sensor_3.ping_cm());
  Serial.println("cm");

  */
