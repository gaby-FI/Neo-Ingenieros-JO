
// Librerias
  //Pixy
  #include <Pixy2.h> // Principal para usar la cámara Pixy
  #include <Pixy2CCC.h> // Permite detectar objetos de diferentes colores en la cámara
  #include <Pixy2I2C.h> // Comunicación con la Pixy mediante distintos protocolos (I2C)
  #include <Pixy2SPI_SS.h> // Comunicación con la Pixy mediante distintos protocolos (SPI)
  #include <Pixy2UART.h> // Comunicación con la Pixy mediante distintos protocolos (UART)
  // Servomotor
  #include <Servo.h> // Controla al servomotor
    Servo servito;
  //Arduino
  #include <Arduino.h> // Principal para usar Arduino



/*
  #include <Pixy2Line.h>
  #include <Pixy2Video.h>
  #include <TPixy2.h>
  #include <ZumoBuzzer.h>
  #include <ZumoMotors.h>
  #include <PIDLoop.h>
  #include <SPI.h>
  #include <Wire.h>
  #include <I2Cdev.h>
  #include <string.h>
*/




// Definir variables
// Obstáculos
  #define num // Cantidad de objetos detectados
  #define ancho // Medida del ancho del objeto para calcular la distancia
  #define rojo // Objeto color rojo
  #define verde // Objeto color verde
// Motor
  #define MOTOR_IZQ_ADELANTE 11    //Controla la parte izquierda delantera del motor
  #define MOTOR_IZQ_ATRAS 9    //Controla la parte izquierda trasera del motor    
  #define MOTOR_DER_ADELANTE 8    //Controla la parte derecha delantera del motor
  #define MOTOR_DER_ATRAS 7    //Controla la parte derecha trasera del motor
// Ultrasonidos
  #define trigpin1 5    // Trigger del ultrasonido derecho del robot
  #define echopin1 4    // Eco del ultrasonido derecho del robot
  #define trigpin2 3    // Trigger del ultrasonido izquierdo del robot
  #define echopin2 2    // Eco del ultrasonido izquierdo del robot
// Velocidad
  #define Activa1 6
  #define Activa2 5

  int velocidad=200; // Velocidad inicial del robot
// Temporizador
 unsigned long TiempoInicio=millis(); // Inicio del temporizador
 const unsigned long DuracionTotal=180000; // 3 minutos en los que el robot recorrerá la pista



  void girarDerecha() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 0);
  digitalWrite(MOTOR_IZQ_ATRAS, 0);
  digitalWrite(MOTOR_DER_ADELANTE, 1);
  digitalWrite(MOTOR_DER_ATRAS, 1);
    delay(500); // Ajusta el tiempo de giro según sea necesario
}
void girarIzquierda() {
  digitalWrite(MOTOR_IZQ_ADELANTE, 1);
  digitalWrite(MOTOR_IZQ_ATRAS, 1);
  digitalWrite(MOTOR_DER_ADELANTE, 0);
  digitalWrite(MOTOR_DER_ATRAS, 0);
    delay(500); // Ajusta el tiempo de giro según sea necesario
}



void setup() {
  serial.begin(9600);
  pixy.init(); // Se inicia la Pixy
  pixy.setLamp(1,1); // Encender luces de la cámara
  int servito; // Definir Servomotor
    rojo=pixy.ccc.Block[0].m_signature==1; // Definir rojo
    verde=pixy.ccc.Block[0].m_signature==2; // Definir verde
    ancho=pixy.ccc.Block[0].m_width; // Definir ancho
}
void loop() {
  num=pixy.getblocks(); //
  millis ()-TiempoInicio //

do{
  if(pixy.ccc.Block>0 && rojo){    // Si la Pixy lee un objeto  y es rojo se cumplirá la condición
    if(ancho>60){ // El objeto se encuentra a 3cm
      servito.write(180); // Giro hacia la derecha mediante grados    
    }
  }else{
    if(pixy.ccc.Block>0 && verde){    // Si la Pixy lee un objeto y es verde se cumplirá la condición
      if(ancho>60){ // El objeto se encuentra a 3cm
        servito.write(0); // Giro hacia la izquierda mediante grados 
      }
    }
  }
} while(TiempoInicio<=DuracionTotal); // Si el temporizador no ha llegado a los 3 minutos se repite el ciclo
  pixy.setLamp(0,0); // Apagar luces de la camara

/*
  num=pixy.getblocks();
  if(num>0){
    if(ancho=pixy.blocks[0].width){
      
    }
  }
*/

}
