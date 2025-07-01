// Librerías
#include <Servo.h>         // Librería para controlar el servomotor
#include <Wire.h>          // Librería para I2C
#include <MPU6050.h>       // Librería para giroscopio

// Pines para motor derecho
#define MOTOR_DER_ADELANTE 8
#define MOTOR_DER_ATRAS 7

// Pines para los sensores ultrasónicos izquierdo y derecho
#define trigpinI 13
#define echopinI 12
#define trigpinD 2
#define echopinD 4

// Crear objeto del servomotor
Servo servito;

// Crear objeto del giroscopio
MPU6050 sensor;

// Constantes de configuración
const int cfloja = 30;            // Margen de diferencia permisible entre sensores
const int umbralGiro = 100;       // Si hay más de esta distancia, se considera "espacio libre"
const int umbralCorreccion = 10;  // Diferencia mínima antes de corregir trayectoria

int giros = 0; // Contador de giros realizados

// Variables para datos del giroscopio
int gx, gy, gz;
long tiempo_prev;
float girosc_ang_x, girosc_ang_y;
float girosc_ang_x_prev = 0, girosc_ang_y_prev = 0;

void setup() {
  // Configurar pines de salida para los motores
  pinMode(MOTOR_DER_ADELANTE, OUTPUT);
  pinMode(MOTOR_DER_ATRAS, OUTPUT);

  // Configurar pines para los sensores ultrasónicos
  pinMode(trigpinI, OUTPUT);
  pinMode(echopinI, INPUT);
  pinMode(trigpinD, OUTPUT);
  pinMode(echopinD, INPUT);

  // Asociar el servo al pin correspondiente
  servito.attach(3);

  // Iniciar comunicación serial
  Serial.begin(9600);

  // Inicializar I2C y giroscopio
  Wire.begin();
  sensor.initialize();
  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");

  tiempo_prev = millis(); // Guardar tiempo inicial
}

// Función para medir distancia con sensor ultrasónico izquierdo
long MDizquierda(int trigI, int echoI) {
  digitalWrite(trigI, LOW);
  delayMicroseconds(2);
  digitalWrite(trigI, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigI, LOW);
  long duracion = pulseIn(echoI, HIGH);
  return duracion * 0.0343 / 2;
}

// Función para medir distancia con sensor ultrasónico derecho
long MDderecha(int trigD, int echoD) {
  digitalWrite(trigD, LOW);
  delayMicroseconds(2);
  digitalWrite(trigD, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigD, LOW);
  long duracion = pulseIn(echoD, HIGH);
  return duracion * 0.0343 / 2;
}

// Movimiento hacia adelante
void avanzar(int d) {
  digitalWrite(MOTOR_DER_ADELANTE, 1);
  digitalWrite(MOTOR_DER_ATRAS, 0);
  delay(d);
  detener();
}

// Movimiento hacia atrás
void retroceder(int d) {
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 1);
  delay(d);
  detener();
}

// Detener motor
void detener() {
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 0);
}

// Corrección de trayectoria según diferencia en distancias
void corregirTrayectoria(long izq, long der) {
  long diferencia = izq - der;
  if (abs(diferencia) > umbralCorreccion) {
    if (diferencia > 0) {
      servito.write(80);  // Corregir izquierda
    } else {
      servito.write(100); // Corregir derecha
    }
    delay(200);
    servito.write(90); // Volver a centro
  }
}

void loop() {
  // === Leer giroscopio ===
  sensor.getRotation(&gx, &gy, &gz);

  long dt = millis() - tiempo_prev;
  tiempo_prev = millis();

  girosc_ang_x = (gx / 131.0) * dt / 1000.0 + girosc_ang_x_prev;
  girosc_ang_y = (gy / 131.0) * dt / 1000.0 + girosc_ang_y_prev;

  girosc_ang_x_prev = girosc_ang_x;
  girosc_ang_y_prev = girosc_ang_y;

  Serial.print("Giro X: "); Serial.print(girosc_ang_x);
  Serial.print("\tGiro Y: "); Serial.println(girosc_ang_y);

  // === Leer sensores ultrasónicos ===
  long usIzq = MDizquierda(trigpinI, echopinI);
  long usDer = MDderecha(trigpinD, echopinD);

  Serial.print("Distancia Izq: "); Serial.print(usIzq);
  Serial.print(" | Distancia Der: "); Serial.println(usDer);

  // === Lógica de movimiento ===
  if (usIzq > umbralGiro) {
    servito.write(60); // Gira a la izquierda
    giros++;
    delay(500);
  } else if (usDer > umbralGiro) {
    servito.write(130); // Gira a la derecha
    giros++;
    delay(500);
  } else {
    servito.write(90); // Mantener recto
    avanzar(300);      // Avanzar un poco
    corregirTrayectoria(usIzq, usDer);
  }

  if (giros >= 12) {
    detener(); // Detener después de 12 giros
    while (true); // Detener loop
  }

  delay(100);
}
