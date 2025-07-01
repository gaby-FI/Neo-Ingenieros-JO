// ======== LIBRARIES ========
#include <Servo.h>        // Library to control the servo motor
#include <Wire.h>         // Library for I2C communication (used with gyroscope)
#include <MPU6050.h>      // Library for the MPU6050 gyroscope
#include <I2Cdev.h>       // Library for I2C device communication

// ======== MOTOR PINS ========
#define MOTOR_DER_ADELANTE 8   // Right motor forward pin
#define MOTOR_DER_ATRAS 7      // Right motor backward pin

// ======== ULTRASONIC SENSOR PINS ========
#define trigpinI 13   // Trigger pin for left ultrasonic sensor
#define echopinI 12   // Echo pin for left ultrasonic sensor
#define trigpinD 2    // Trigger pin for right ultrasonic sensor
#define echopinD 4    // Echo pin for right ultrasonic sensor

// ======== OBJECTS ========
Servo servito;         // Servo motor object
MPU6050 sensor;        // Gyroscope object

// MPU6050 address can be 0x68 or 0x69 depending on the AD0 pin state.
// If not specified, it defaults to 0x68.

// ======== CONSTANTS ========
const int cfloja = 30;            // Acceptable margin between sensor readings
const int umbralGiro = 100;       // If distance is greater than this, it's considered "free space"
const int umbralCorreccion = 10;  // Allowed difference before correcting trajectory

int giros = 0;  // Counter for turns made

// ======== RAW GYROSCOPE VALUES ========
int gx, gy, gz;                   // Raw rotation values from gyroscope (X, Y, Z axes)
long tiempo_prev, dt;            // Time tracking for integration
float gc_ang_x, gc_ang_y;        // Calculated angular position (X and Y)
float gc_ang_x_prev, gc_ang_y_prev;  // Previous angles to integrate over time

void setup() {
  // === MOTOR SETUP ===
  pinMode(MOTOR_DER_ADELANTE, OUTPUT);
  pinMode(MOTOR_DER_ATRAS, OUTPUT);

  // === ULTRASONIC SENSOR SETUP ===
  pinMode(trigpinI, OUTPUT);
  pinMode(echopinI, INPUT);
  pinMode(trigpinD, OUTPUT);
  pinMode(echopinD, INPUT);

  // === SERVO SETUP ===
  servito.attach(3);   // Attach the servo to digital pin 3

  // === SERIAL AND SENSOR INITIALIZATION ===
  Serial.begin(9600);       // Begin serial communication
  Wire.begin();             // Initialize I2C communication
  sensor.initialize();      // Initialize MPU6050

  if (sensor.testConnection()) Serial.println("Sensor initialized correctly");
  else Serial.println("Sensor initialization failed");

  tiempo_prev = millis();   // Store the initial time

  // NOTE: The following lines reference an undefined 'mpu' object.
  // If you use `MPU6050 sensor;`, then `mpu.begin()` and `mpu.getAngleZ()` will cause errors.
  // Uncomment and adjust only if using a different MPU6050 library:
  /*
  mpu.begin();
  delay(1000);
  mpu.calcOffsets();  // Calibrate at rest
  mpu.update();
  anguloInicial = mpu.getAngleZ(); // Store initial orientation
  */
}

// ======== ULTRASONIC MEASUREMENT FUNCTIONS ========

// Measure distance using the left ultrasonic sensor
long MDizquierda(int trigI, int echoI) {
  digitalWrite(trigI, LOW);
  delayMicroseconds(2);
  digitalWrite(trigI, HIGH);        // Send ultrasonic pulse
  delayMicroseconds(10);
  digitalWrite(trigI, LOW);
  long duracion = pulseIn(echoI, HIGH);   // Measure echo return time
  return duracion * 0.0343 / 2;           // Convert time to distance in cm
}

// Measure distance using the right ultrasonic sensor
long MDderecha(int trigD, int echoD) {
  digitalWrite(trigD, LOW);
  delayMicroseconds(2);
  digitalWrite(trigD, HIGH);        // Send ultrasonic pulse
  delayMicroseconds(10);
  digitalWrite(trigD, LOW);
  long duracion = pulseIn(echoD, HIGH);   // Measure echo return time
  return duracion * 0.0343 / 2;           // Convert time to distance in cm
}

// ======== BASIC MOVEMENT FUNCTIONS ========

void avanzar() {
  digitalWrite(MOTOR_DER_ADELANTE, 1);   // Move right motor forward
  digitalWrite(MOTOR_DER_ATRAS, 0);
}

void retroceder() {
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 1);     // Move right motor backward
}

void detener() {
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 0);     // Stop right motor
}

// ======== MAIN LOOP ========
void loop() {
  // Read gyroscope rotational velocities
  sensor.getRotation(&gx, &gy, &gz);

  // Calculate rotation angles by integrating velocity over time
  dt = millis() - tiempo_prev;
  tiempo_prev = millis();

  girosc_ang_x = (gx / 131.0) * dt / 1000.0 + girosc_ang_x_prev;
  girosc_ang_y = (gy / 131.0) * dt / 1000.0 + girosc_ang_y_prev;

  girosc_ang_x_prev = girosc_ang_x;
  girosc_ang_y_prev = girosc_ang_y;

  // Display calculated angles (X and Y rotation)
  Serial.print("Rotation X: ");
  Serial.print(girosc_ang_x);
  Serial.print("\tRotation Y: ");
  Serial.println(girosc_ang_y);

  delay(100);

  /*
  // Example logic to compare distances
  Serial.print(MDizquierda(trigpinI, echopinI));
  Serial.print("\n");
  Serial.print(MDderecha(trigpinD, echopinD));

  if (MDizquierda > MDderecha) {
    servito.write(90);  // Turn servo to center
  } else if (MDderecha > MDizquierda) {
    servito.write(20);  // Turn servo slightly left
  }
  delay(1000);
  */
}
