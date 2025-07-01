# 🤖 Circuit Diagram - WRO Future Engineers

This repository contains the wiring diagram for the electromechanical system of the autonomous vehicle developed for the **WRO Future Engineers 2022** project. The system integrates motors, sensors, controllers, and a regulated power supply to allow coordinated and safe operation of the vehicle.

## 🧩 Components Used

| Quantity | Component             | Image                                              | Description                                                      |
|:---:|:------------------------:|:----------------------------------------:|:-------------------------:|
| 1   | Arduino UNO              | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/e29c1d823745e0fd7d2edbc1f5f1bfaec5b01044/wro2022-fe-template/others/component%20images/Arduino%201%20img.png " height="200"/>       | Main microcontroller board used to control all components.       |
| 1   | Protoboard               | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/804de712fae17f8989ece6b27a821747b9039abf/wro2022-fe-template/others/component%20images/Breadboarding%20img.jpg " height="200" style="width:auto;" />     | Solderless board used for building and testing electronic circuits. |
| 1   | DC engine                | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/a22469f03a7eb62f7e6e10bbb9988d80350ef39f/wro2022-fe-template/others/component%20images/engine%20Dc%20IMG.png " height="200"/>        | Motors used for the vehicle’s locomotion.                        |
| 1   | Servo Motor              | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/ca169623edfa4923ce748c8eb2277a233a8db26c/wro2022-fe-template/others/component%20images/Micro%20servo%20ig.jpg " height="200" />         | Controls the steering or sensor orientation.                     |
| 2   | Ultrasonic Sensors       | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/9bdc27000639f60ce029bea6939fbbe7ed20875c/wro2022-fe-template/others/component%20images/HC-SR04-Ultrasonic%20img.jpg " height="170"/>        | Distance measurement (Left and Right side).                      |
| 1   | L293D H bridge           | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/62d74b1399613b882055a6f571c6a8ab84b1c17b/wro2022-fe-template/others/component%20images/bridge%20h%20L293D.png " height="200"/>       | Motor driver that allows control of direction and speed for two DC motors.(Used only in the diagram; the actual vehicle circuit uses an HG7881 instead.) |
| 1   | MPU-6050 Gyroscope       | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/55f677960a81f742ac54603f5d3ddecc44bf1f45/wro2022-fe-template/others/component%20images/Mpu6050%20img.jpeg " height="200"/>          | Detects angular motion and helps with orientation.               |
| 1   | Pixy2 Camera             | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/09fc35eac25f9ff44fde0437d8d9e47c32e0c396/wro2022-fe-template/others/component%20images/Pixy2%20cam%20img.jpg " height="200"/>          | Visual object detection system.                                  |
| 1   | 12V Battery              | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/71b76a8db6e236f162cc9bcda27931af8ac9e8a9/wro2022-fe-template/others/component%20images/battery%2012v%20ig.png " height="200"/>       | 12V power source for motors and logic components. (In the actual circuit, three 3.5V batteries connected in series using a battery holder are used instead).                 |
| 1   | Voltage Regulator        | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/f3c6f3d93bc7e534023fb729706fbabbd2ee5b88/wro2022-fe-template/others/component%20images/Voltage%20regulator%20LM7805%20img.jpg " height="200"/>     | Steps down 12V to 5V to protect components from overvoltage.     |
| 2   | Condenser                | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/72dcc30d27912dda952ebeea4b454c98b80a2417/wro2022-fe-template/others/component%20images/Capacitor.jpg " height="200"/>     | Filters electrical interference and stabilizes voltage in the circuit. |

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

## ✅ Justification of Component Selection
### 🧠 **Arduino UNO**  
Chosen as the main microcontroller for its ease of programming, multiple I/O ports, and compatibility with various modules. It handled all sensor inputs, motor control, and decision-making processes efficiently during the development and testing stages.

### ⚙️ **DC Motor**  
Used for the main propulsion system of the vehicle. These motors convert electrical energy into mechanical movement, enabling the robot to navigate the track reliably with sufficient torque and speed.

### 🔌 **Breadboard**  
Used to simplify prototyping without soldering. It allowed rapid assembly and reconfiguration of the circuit, especially for distributing power and connecting sensors during testing and debugging phases.

### 📏 **HC-SR04 Ultrasonic Sensor**  
Implemented for obstacle detection and distance measurement. Mounted on the sides, these sensors allowed the vehicle to maintain a safe distance from walls and objects, supporting lateral alignment and collision avoidance.

### 🌀 **MPU-6050**  
Provided orientation and motion data through its built-in accelerometer and gyroscope. This information was used to stabilize the vehicle and assist in trajectory adjustments during operation.

### ↪️ **Micro Servo Motor (SG90)**  
Controlled the front steering mechanism of the vehicle. Based on inputs from the ultrasonic sensors and vision system, the servo motor dynamically adjusted the wheel direction to avoid obstacles and follow the correct path.

### 🎥 **Pixy2 Cam**  
Served as the visual processing unit for the vehicle. It enabled real-time object detection and line tracking, allowing the robot to follow a predefined path or identify specific targets during competition scenarios.

### 🔋 **Capacitors**  
Added to the circuit to filter out electrical noise and stabilize voltage across sensitive components. This ensured smoother operation, especially under varying motor loads.

### 🔋 **12V Battery**  
Served as the primary power source for motors and control modules. While a 12V battery is shown in the diagram for simplicity, the actual vehicle used three 3.7V batteries connected in series via a battery holder (totaling ~11.1V), which met all power requirements effectively.

### ⚡ **Voltage Regulators**  
Used to supply consistent 5V output to logic-level components from a higher voltage input. This protected the microcontroller and sensors from voltage spikes or drops.

### 🔀 **HG7881 H-Bridge Motor Driver** *(used in the final vehicle)*  
Enabled bidirectional control of DC motors with PWM support. Its compact design and efficient performance made it ideal for integrating into the mobile platform, controlling both speed and direction.

### 🔄 **L293D H-Bridge** *(used only in the diagram)*  
Included in the schematic as a visual placeholder. It supports bidirectional control of two DC motors and represents the logic of the system. *(In the physical vehicle, the HG7881 was used instead.)*

### 🔋 **Batería de 12V**  
Utilizada como fuente principal de energía para los motores y módulos de control. Aunque en el diseño final se utilizaron tres baterías de 3.7V conectadas en serie mediante un portapilas (equivalente a ~11.1V), la batería de 12V fue representada en el esquema por simplicidad y disponibilidad. Ambas opciones cumplen con los requerimientos de potencia del sistema.
