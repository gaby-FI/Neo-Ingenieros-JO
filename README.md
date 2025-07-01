<div align="center">
  
   # Autonomous Robot Project for WRO - Future Engineers Category
  
</div>

## 🤖 About the Competition

The World Robot Olympiad (WRO) is a prestigious international competition that challenges students from around the globe to solve problems through creative, functional, and technically sound robotic solutions. One of its most engaging categories is **Future Engineers**, which focuses on developing advanced technologies to tackle real-world challenges, encouraging innovation, critical thinking, and collaborative work.

This year's challenge in the Future Engineers category is particularly exciting: to design and build an **autonomous vehicle** capable of making intelligent decisions and adapting to a dynamic environment. The challenge offers a unique opportunity for young engineers to explore the fundamentals of modern robotics, including motor control, sensor processing, and autonomous navigation.

---

## 🚗 Project Description

This repository documents the hardware and software architecture developed to build an autonomous vehicle designed to compete in the Future Engineers category of the WRO. The system has been carefully designed to address two specific challenges defined by the competition:

1. **Open Challenge**: The vehicle must complete three laps on a closed track, where inner walls are randomly placed each run. The robot must avoid collisions through accurate obstacle detection.
   
2. **Obstacle Challenge**: Along the route, the robot will encounter colored pillars acting as traffic signals. **Red** pillars indicate the robot should drive on the right, while **green** pillars indicate it should drive on the left. The vehicle must navigate without knocking over these signals, and at the end of the route, it must detect a **parking zone** and autonomously perform parallel parking.

The design integrates multiple technologies: ultrasonic sensors, a gyroscope, a Pixy2 camera, DC motors, and an H-bridge, all controlled by an Arduino Uno microcontroller. The system includes a voltage regulator and capacitors to protect sensitive components and ensure safe, stable operation. This documentation serves as a technical guide for the development process and as a reference for future teams participating in similar robotics challenges

---

## 🎯 Project Objective

The goal of this project is to design, build, and program an autonomous robot using open-source hardware, environmental sensors, and adaptive motion algorithms. The robot dynamically perceives its surroundings and makes decisions based on sensor feedback, enabling efficient navigation and autonomous obstacle avoidance.

**Core development goals:**

- Strengthen real-world engineering skills such as problem-solving and teamwork.
- Apply sensor-based motion control for precise navigation.
- Develop an optimized autonomous driving strategy for robotics challenges.
- Contribute to the open-source robotics community by documenting the solution for future teams.

---

## 🧩 Components Used

| Quantity | Component             | Image                                              | Description                                                      |
|:---:|:------------------------:|:----------------------------------------:|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| 1   | Arduino UNO              | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/e29c1d823745e0fd7d2edbc1f5f1bfaec5b01044/wro2022-fe-template/others/component%20images/Arduino%201%20img.png" height="100"/>       | - ATmega328P microcontroller<br>- Operating voltage: 5V<br>- 14 digital pins (6 PWM)<br>- 6 analog inputs<br>- Memory: 32 KB flash, 2 KB SRAM, 1 KB EEPROM<br>- Communication: USB, UART, I2C, SPI<br>- Main system control, sensor reading, PWM signal generation, external communication<br>- Power supply: 7-12V<br>- Easy programming via Arduino IDE |
| 1   | Protoboard               | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/804de712fae17f8989ece6b27a821747b9039abf/wro2022-fe-template/others/component%20images/Breadboarding%20img.jpg" height="100" style="width:auto;" />     | - 830 solderless connection points<br>- Enables rapid prototyping<br>- Temporary connections between components<br>- Side rails for power (Vcc and GND)<br>- Compatible with standard cables and pins<br>- Plastic body with internal metal contacts<br>- Ideal for testing circuits without soldering |
| 2   | DC Engine                | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/a22469f03a7eb62f7e6e10bbb9988d80350ef39f/wro2022-fe-template/others/component%20images/engine%20Dc%20IMG.png" height="100"/>        | - Nominal voltage: 6–12V<br>- No-load current: ~300 mA<br>- Brushed DC motor<br>- Provides rotational motion<br>- Controlled via H-bridge for direction and speed<br>- Adequate torque for small vehicles<br>- Compact and lightweight |
| 1   | Servo Motor              | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/ca169623edfa4923ce748c8eb2277a233a8db26c/wro2022-fe-template/others/component%20images/Micro%20servo%20ig.jpg" height="100" />         | - Operating voltage: 4.8–6V<br>- Max current: ~500 mA<br>- Rotation angle: 0° to 180°<br>- Micro servo with plastic gears<br>- Precise angular position control via PWM<br>- Used for moving sensors or steering<br>- Compact and lightweight |
| 2   | Ultrasonic Sensors       | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/9bdc27000639f60ce029bea6939fbbe7ed20875c/wro2022-fe-template/others/component%20images/HC-SR04-Ultrasonic%20img.jpg" height="100"/>        | - Operating voltage: 5V DC<br>- Range: 2 cm to 400 cm<br>- Accuracy: ±3 mm<br>- Ultrasonic frequency: 40 kHz<br>- Pins: Trigger and Echo<br>- Measures distance for obstacle avoidance<br>- Fast response time<br>- Detects objects in a straight line |
| 1   | HG7881 H-Bridge          | <img src="https://github.com/gaby-FI/Neo-Ingenieros-JO/blob/e43f1b1aef36bd6721362ebf63cbc97a949ca593/wro2022-fe-template/others/component%20images/hg7881%20-%20h%20bridge%20img.jpg" height="100"/>       | - Operating voltage: 2.5–12V<br>- Max current: 800 mA per channel<br>- Dual channel motor driver<br>- Controls motor direction and speed via PWM<br>- Includes internal protection diodes<br>- Compact and efficient for small projects |
| 1   | MPU-6050 Gyroscope       | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/55f677960a81f742ac54603f5d3ddecc44bf1f45/wro2022-fe-template/others/component%20images/Mpu6050%20img.jpeg" height="100"/>          | - Power supply: 3.3V–5V<br>- 3-axis gyroscope and 3-axis accelerometer<br>- I2C communication<br>- High precision for orientation and balance<br>- Used for stabilization and motion tracking<br>- Low power consumption |
| 1   | Pixy2 Camera             | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/09fc35eac25f9ff44fde0437d8d9e47c32e0c396/wro2022-fe-template/others/component%20images/Pixy2%20cam%20img.jpg" height="100"/>          | - Operating voltage: 5–10V DC<br>- Communication: SPI, UART, I2C<br>- Smart sensor for object detection and tracking by color<br>- Internal image processing<br>- Sends processed data for decision making<br>- Used for advanced navigation and tracking |
| 1   | Voltage Regulator        | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/f3c6f3d93bc7e534023fb729706fbabbd2ee5b88/wro2022-fe-template/others/component%20images/Voltage%20regulator%20LM7805%20img.jpg" height="100"/>     | - Input voltage: 7–12V DC<br>- Fixed output: 5V DC<br>- Max current: typically 1A<br>- Provides stable and filtered voltage<br>- Overvoltage and thermal protection<br>- Protects sensitive components |
| 3   | Capacitors               | <img src="https://github.com/ItsTheWest/Neo-Ingenieros-JO/blob/72dcc30d27912dda952ebeea4b454c98b80a2417/wro2022-fe-template/others/component%20images/Capacitor.jpg" height="100"/>     | - Electrolytic polarized capacitors (100μF, 10μF)<br>- Filters electrical noise and voltage spikes<br>- Stabilizes power supply<br>- Temporary charge storage<br>- Placed near regulators and modules<br>- Improves system stability and performance |

## 🚗 Strategy and Code Deployment for Autonomous Vehicle Project

The designed strategy combines mechanical, electronic, and perception components to simulate an intelligent vehicle that autonomously navigates a route under conditions similar to a controlled urban environment. The key elements to meet the challenges are:

- ⚙️ **Motorization and Steering:**  
  An electric motor drives the rear wheels of the vehicle, while a servo motor on the front axle allows left and right steering maneuvers, imitating a real car's steering system.

- 🎥 **Vision and Perception:**  
  A front-mounted camera enables detection of obstacle distances and traffic light colors (red or green), a critical decision factor to deviate either right or left. This visual component acts as the main perception system for the frontal environment.

- 📡 **Side Sensors:**  
  Two ultrasonic sensors located on the vehicle's sides measure the distance to obstacles on each side. Based on this data, the system determines the safest side to turn when detecting an obstruction or needing to take a curve.

- 🧭 **Orientation System:**  
  A gyroscope allows the vehicle to recognize its spatial orientation, record the initial position, and ensure that at the end of the route it parks parallel at the same starting position. This component is essential to meet the precise navigation requirements of the competition.

---

## 💻 Code Compilation and Upload Process

### ⚙️ Development Environment Installation

To work on this project, you need the appropriate environment. It is recommended to use the Arduino IDE, preferably version 1.8.19 or higher, to ensure compatibility with all the libraries used and to avoid compilation errors.

**📚 Required Libraries:**

- `Servo.h`: Enables control of servo motors.  
- `Pixy2.h`: Provides functions necessary to communicate with the Pixy2 vision sensor.

These libraries can be easily installed from the Arduino IDE Library Manager or manually downloaded from their respective repositories.

### 🗂 Project Structure

The source code must be organized properly to ensure correct functionality. All `.ino` files should be located within the same folder, which must be named exactly as the main file (usually `main.ino`). This structure is required by the Arduino IDE to properly compile the different modules of the project.

### ⚙️ Compilation Process

Before compiling the code, configure the environment as follows:

1. Go to **Tools > Board**, and select the appropriate board model — in this case, **Arduino UNO**.  
2. In the same menu, select the COM port to which your device is connected.  
3. Once configured, click the **Verify** button (✔️) to compile the code. This action translates the source code to machine language and detects syntax errors or library issues.

### 🚀 Uploading the Program

Once the code is compiled:

1. Connect the Arduino UNO board to your computer via USB cable.  
2. Press the **Upload** button (➡️) in the IDE to load the program into the microcontroller’s memory.  
3. After upload completes, you can monitor the system behavior using the **Serial Monitor** accessible from **Tools > Serial Monitor**, which is especially useful for debugging and data flow verification.
