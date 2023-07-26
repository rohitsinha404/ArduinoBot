# Arduino Code README

## Project Overview

This repository contains Arduino code for a robot control system. The code is designed to control the movement of a robot with three ultrasound sensors to avoid obstacles and navigate its environment.

## Table of Contents

- [Project Overview](#project-overview)
- [Hardware Setup](#hardware-setup)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Hardware Setup

To use this code, you will need the following hardware components:

- Arduino board (e.g., Arduino Uno)
- Motor driver (AFMotor shield)
- Two DC motors for wheels (left and right)
- One DC motor for brushes (optional, used for additional functionality)
- Three ultrasound sensors for obstacle detection
- Infrared (IR) sensor (optional, used for ground detection)

Connect the hardware components as follows:

- Connect the left DC motor to motor port 1 on the AFMotor shield.
- Connect the right DC motor to motor port 2 on the AFMotor shield.
- Connect the brush DC motor (if used) to motor port 3 on the AFMotor shield.
- Connect the three ultrasound sensors to the trig and echo pins specified in the code (trig_L, echo_L, trig_M, echo_M, trig_R, echo_R).
- Connect the IR sensor (if used) to the specified pin (ir).
- ![image](https://github.com/rohitsinha404/ArduinoBot/assets/114895566/a4fae579-2906-4b1a-bc44-5ce6cc67d480)


## Installation

To use this code on your Arduino board, follow these steps:

1. Connect the hardware components according to the hardware setup instructions.
2. Open the Arduino IDE on your computer.
3. Create a new sketch and copy-paste the code from this repository into the sketch.
4. Make sure your Arduino board is connected to your computer via USB.
5. Select the appropriate board and port from the Arduino IDE's "Tools" menu.
6. Click the "Upload" button in the Arduino IDE to upload the code to your Arduino board.

## Usage

After uploading the code to your Arduino board, the robot should start executing its control algorithm using the ultrasound sensors to detect obstacles and avoid them. The robot's behavior is as follows:

- If all three sensors detect obstacles within close proximity (dist_L <= 10, dist_M <= 15, and dist_R <= 10), the robot will perform a turnaround maneuver (turnAround() function).
- If the left and middle sensors detect obstacles within close proximity (dist_L <= 10, dist_M <= 15), the robot will turn right (turnRight() function).
- If the right and middle sensors detect obstacles within close proximity (dist_R <= 10, dist_M <= 15), the robot will turn left (turnLeft() function).
- If only the middle sensor detects an obstacle within close proximity (dist_M < 15), the robot will choose to turn either right or left based on the value of the "turn" variable (turnRight() or turnLeft() function).
- If none of the sensors detect obstacles within close proximity, the robot will move forward (moveForward() function).

Please note that the code also includes functions to read the distance from each ultrasound sensor (readSensor_L(), readSensor_M(), readSensor_R()) and to stop the movement of the robot (moveStop() function).

## Contributing

If you find any issues with the code or have suggestions for improvements, feel free to create an issue or pull request in this repository. Your contributions are welcome!

## License

 Feel free to use, modify, and distribute the code for your own purposes. 
