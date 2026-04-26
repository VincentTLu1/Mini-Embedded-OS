# Mini-Embedded-OS

This is a C++ based application that allows users to simulate a embedded system designed operating system.

## Features
- Simulate tasks 
- Timer based applications
- Scheduler based
- More to be added soon

## Project Structure
- `gpio.h` - header file for gpio
- `gpio.cpp` - gpio file for input and output
- `scheduler.cpp` - scheduler file to handle scheduling logic
- `main.cpp` - main cpp file to simulate the tasks
- `timer.cpp` - simulate a timer between switching

## Project Goal
The goal for this project was mainly inspired by my passion for embedded systems and my interest to expand my knowledge in operating system design. In operating system design, we have to consider issues such as context switching, timing constraints, and other priority issues. In embedded system design, we have to consider both hardware and software integration. By simulating a GPIO pin, we can simulate how a Cental Processing Unit (CPU) handles the switching of different tasks that are queued for processing. Incorporating a OS approach to this project gives an important idea of how a CPU processes data.
