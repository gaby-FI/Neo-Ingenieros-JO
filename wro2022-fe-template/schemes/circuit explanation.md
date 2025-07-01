# 🤖 Circuit Diagram - WRO Future Engineers

This repository contains the wiring diagram for the electromechanical system of the autonomous vehicle developed for the **WRO Future Engineers 2022** project. The system integrates motors, sensors, controllers, and a regulated power supply to allow coordinated and safe operation of the vehicle.

| Quantity | Component             | Image                                              | Description                                                      |
|----------|-----------------------|----------------------------------------------------|------------------------------------------------------------------|
| 1        | Arduino UNO           | <img src="component images/Arduino 1 img.png" height="100"/>       | Main microcontroller board used to control all components.       |
| 2        | DC Motors             | <img src="component images/engine Dc IMG.png" height="100"/>        | Motors used for the vehicle’s locomotion.                        |
| 1        | Servo Motor           | <img src="component images/Micro servo ig.jpg" height="100"/>         | Controls the steering or sensor orientation.                     |
| 2        | Ultrasonic Sensors    | <img src="component images/HC-SR04-Ultrasonic img.jpg" height="100"/>        | Distance measurement (Left and Right side).                      |
| 1        | L298N H-Bridge        | <img src="component images/hg7881 - h bridge img.jpg" height="100"/>       | Driver module for controlling the direction and speed of motors. |
| 1        | MPU-6050 Gyroscope    | <img src="component images/Mpu6050 img.jpeg" height="100"/>          | Detects angular motion and helps with orientation.               |
| 1        | Pixy2 Camera          | <img src="component images/Pixy2 cam img.jpg" height="100"/>          | Visual object detection system.                                  |
| 1        | 12V Battery           | <img src="images/battery.jpg" height="100"/>       | Power source for motors and logic components.                    |
| 1        | Voltage Regulator     | <img src="component images/Voltage regulator LM7805 im..." height="100"/>     | Steps down 12V to 5V to protect components from overvoltage.     |

## 🧩 Components Used

- Arduino UNO  
- 1x DC Motors  
- 1x Servo Motor  
- 2x Left Ultrasonic Sensors (HC-SR04)  
- 1x H-Bridge (L298N)  
- 1x Gyroscope MPU-6050  
- 1x Pixy2 Camera  
- 1x 12V Battery  
- 1x Voltage regulator with capacitors  
- Breadboard and jumper wires
## 📷 Circuit Diagram

> Full connection diagram (created in Tinkercad)

![Circuit diagram](https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/c19015ff7b8b3c0f9e1593c1dbca7ba38247cd86/wro2022-fe-template/schemes/circuit%20diagram.jpg)


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
