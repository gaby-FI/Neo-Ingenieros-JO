
#include <Servo.h>
Servo servito;
#define Activa1 6
#define Ma1 11
#define Ma2 9
#define Mb1 8
#define Mb1 8
#define Mb2 7 
#define Activa2 5


int velocidad =200;


void setup() {
  pinMode (Activa1, OUTPUT);
  pinMode (Ma1, OUTPUT);
  pinMode (Ma2, OUTPUT);
  pinMode (Mb1, OUTPUT);
  pinMode (Mb2, OUTPUT);
  pinMode (Activa2, OUTPUT);
  analogWrite(Activa1,velocidad);
  analogWrite(Activa2,velocidad);
  pinMode (13,OUTPUT);
    servito.attach(3);
  
}

void loop() {
//atras
 digitalWrite(Ma1,0);
 digitalWrite(Ma2,1);
 digitalWrite(Mb1,0);
 digitalWrite(Mb2,1);
 digitalWrite(13,0);
 delay(3000);
 //Avanzar
 digitalWrite(Ma1,1);
 digitalWrite(Ma2,0);
 digitalWrite(Mb1,1);
 digitalWrite(Mb2,0);
 digitalWrite(13,1);
  delay(1000);
   servito.write(90);
 delay (1000);
  servito.write(0);
  delay (1000);
  
}
