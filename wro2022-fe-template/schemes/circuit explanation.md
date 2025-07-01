# 🤖 Circuit Diagram - WRO Future Engineers

This repository contains the wiring diagram for the electromechanical system of the autonomous vehicle developed for the **WRO Future Engineers 2022** project. The system integrates motors, sensors, controllers, and a regulated power supply to allow coordinated and safe operation of the vehicle.

## 🧩 Components Used

- Arduino UNO  
- 2x DC Motors  
- 1x Servo Motor  
- 1x Left Ultrasonic Sensor (HC-SR04)  
- 1x Right Ultrasonic Sensor (HC-SR04)  
- 1x H-Bridge (L298N)  
- 1x Gyroscope MPU-6050  
- 1x Pixy2 Camera  
- 1x 12V Battery  
- 1x Voltage regulator with capacitors  
- Breadboard and jumper wires

## 📷 Circuit Diagram

> Full connection diagram (created in Tinkercad)

![Circuit Diagram](schemes/circuitdiagram.jpg)

## 🔌 Wiring Explanation

### 🔊 Ultrasonic Sensors

**Left sensor:**
- Trigger (purple) → Pin 13  
- Echo (white) → Pin 12  
- VCC (yellow) → Breadboard power rail  
- GND (brown) → Breadboard ground rail  

**Right sensor:**
- Trigger (gray) → Pin 2  
- Echo (blue) → Pin 4  
- VCC → Breadboard power rail  
- GND → Breadboard ground rail  

### ⚙️ DC Motors and H-Bridge (L298N)

- Motors connected to channel A of the H-Bridge (purple and gray wires)  
- IN1 → Pin 8  
- IN2 → Pin 7  
- H-Bridge GND → Breadboard ground  
- H-Bridge VCC → Output from voltage regulator  

### 🌀 Gyroscope MPU-6050

- VCC (red) → Breadboard power rail  
- GND (black) → Breadboard ground rail  
- SDA (purple) → Pin A4  
- SCL (gold) → Pin A5  
- INT (thin red) → Pin 11  

### 🔁 Servo Motor

- Signal (orange) → Pin 3  
- VCC (red) → Power rail  
- GND (brown) → Ground rail  

### 📷 Pixy2 Camera

- Connected to Arduino via dedicated interface cable (UART or SPI).

### 🔋 Voltage Regulator Circuit

- **12V Battery:**
  - Positive → Right leg of the regulator (input)  
  - Negative → Shared ground  
- **Regulator:**
  - Left leg → 5V output (goes to H-Bridge and breadboard)  
  - Middle leg → GND (connected to ground rail)  
- **Capacitors:**
  - One large capacitor between output and GND  
  - One smaller capacitor between input and GND  

> This setup reduces the 12V from the battery to 5V to avoid overloading the H-Bridge and ensures safe current regulation to protect the motors and board.

## ⚠️ Recommendations

- Make sure all grounds (GND) are unified to avoid floating references.  
- Motors are powered directly from the H-Bridge and battery.  
- The voltage regulator prevents current spikes that could damage components and guarantees stable 5V output for the electronics.

---
