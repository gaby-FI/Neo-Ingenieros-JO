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
