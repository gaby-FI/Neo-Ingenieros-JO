
// Servomotor
  #include <Servo.h>
  Servo servito;
// Velocidad
  #define Activa1 6
  #define Activa2 5
// Motor
  #define MOTOR_IZQ_ADELANTE 11
  #define MOTOR_IZQ_ATRAS 9
  #define MOTOR_DER_ADELANTE 8
  #define MOTOR_DER_ATRAS 7
// Ultrasonidos
  #define trigpin1 5
  #define echopin1 4
  #define trigpin2 3
  #define echopin2 2
// Velocidad
  int velocidad=200;




// Definir función motor
void avanzarAdelante() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_IZQ_ATRAS, 1);
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 1);
  delay(5000);
  digitalWrite(MOTOR_IZQ_ATRAS, 1);
  digitalWrite(MOTOR_DER_ATRAS, 1);
}
void retroceder() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 1);
  digitalWrite(MOTOR_IZQ_ATRAS, 0);
  digitalWrite(MOTOR_DER_ADELANTE, 1);
  digitalWrite(MOTOR_DER_ATRAS, 0);
  delay(5000);
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ADELANTE, 0);
}

// Definir giros
void girarDerecha() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_IZQ_ATRAS, 0);
  digitalWrite(MOTOR_DER_ADELANTE, 1);
  digitalWrite(MOTOR_DER_ATRAS, 1);
  delay(500); // Ajusta el tiempo de giro según sea necesario
  detenerMotor();
}
void girarIzquierda() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_IZQ_ATRAS, 1);
  digitalWrite(MOTOR_DER_ADELANTE, 1);
  digitalWrite(MOTOR_DER_ATRAS, 0);
  delay(500);
  detenerMotor();
}
void detenerMotor() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_IZQ_ATRAS, 0);
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 0);
}




void setup() {
  pinMode (Activa1, OUTPUT);
  pinMode(MOTOR_IZQ_ADELANTE, OUTPUT);
  pinMode(MOTOR_IZQ_ATRAS, OUTPUT);
  pinMode(MOTOR_DER_ADELANTE, OUTPUT);
  pinMode(MOTOR_DER_ATRAS, OUTPUT);
  pinMode (Activa2, OUTPUT);
  analogWrite(Activa1,velocidad);
  analogWrite(Activa2,velocidad);
// Inicializar comunicación serial para depuración
  Serial.begin(9600);
/*
  pinMode (13,OUTPUT);
    servito.attach(3);
*/  
}




long medirDistancia(int triggerPin, int echoPin) {
    digitalWrite(triggerPin, 0);
    delayMicroseconds(2);
    digitalWrite(triggerPin, 1);
    delayMicroseconds(10);
    digitalWrite(triggerPin, 0);
    return pulseIn(echoPin, 1) / 58;  // Convierte el tiempo en distancia en cm
}

  
void loop() {
    avanzarAdelante();
      delay(5000); // Espera 5 segundos para retroceder
    retroceder();
      delay(5000);
     
     for(int i = 0; i < 12; i++) {  // Repetir 12 veces
// Medir distancia del sensor IZQUIERDO (trigpin2, echopin2)
    long distanciaIzquierda = medirDistancia(trigpin2, echopin2);
    
    Serial.print("Iteración ");
    Serial.print(i+1);
    Serial.print(": Distancia izquierda = ");
    Serial.print(distanciaIzquierda);
    Serial.println(" cm");
    
    if(distanciaIzquierda > 100) {
      girarIzquierda();  // Si >100cm, gira izquierda
      Serial.println("Girando a la izquierda");
    } else {
      girarDerecha();    // Si <=100cm, gira derecha
      Serial.println("Girando a la derecha");
    }
 
    delay(500);  // Pausa entre iteraciones
  }
      detenerMotor();
    Serial.println("Ciclo completado");
    while(true);  // Detener ejecución
}
/*
      delay(3000); // Espera 5 segundos antes de repetir el movimiento
      long distanciaIzquierda = medirDistancia(trigpin2,echopin2);
      Serial.print("Distancia izquierda: ");
      Serial.println(distanciaIzquierda);      
      if (distanciaIzquierda < ) {  // Umbral para detectar obstáculos
        girarDerecha();
      } else {
      // Mantener el movimiento recto
        digitalWrite(MOTOR_IZQ_ADELANTE, 1);
        digitalWrite(MOTOR_IZQ_ATRAS, 0);
        digitalWrite(MOTOR_DER_ADELANTE, 1);
        digitalWrite(MOTOR_DER_ATRAS, 0);
        delay(3000); // Pequeña pausa para evitar lecturas demasiado frecuentes


      }
*/
}

/*
//Atras
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
*/
