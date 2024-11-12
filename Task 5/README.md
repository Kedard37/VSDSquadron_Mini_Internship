# Task 5 Output:
## Project Name:
### Implementation of a Decade Up & Down Counter using VSDSquadron Mini Board.

## Overview:
The **Decade Up & Down Counter** project showcases a digital counting system designed to increment or decrement through a sequence of ten states, ranging from 0 to 9. This counter is built to count either up or down based on a control input, making it versatile for various applications where sequential counting is required. At the heart of the system is a flip-flop-based architecture or a dedicated counter IC, which tracks the current count and modifies it according to the user's input for up or down counting. Here, we are using a RISC-V based processor to execute the same.

The counter continuously cycles through the ten states in a loop, resetting to 0 after reaching 9 when counting up or transitioning back to 9 from 0 when counting down. This cyclical counting feature makes the Decade Up/Down Counter ideal for applications in digital clocks, timers, frequency division, and other counting-based circuits. The project demonstrates precise, reliable counting and offers users a flexible, programmable solution for tasks that require accurate sequential control in digital systems.

## Components Required:
1. VSDSquadron Mini Board - CH32V003x RISC-V based Microprocessors (Qty. 1)
2. 7 Segment Display - Common Cathode - SUN056CC (Qty. 1)
3. 3 Terminal Slide Switch (Qty. 1)
4. 1KΩ Resistor (Qty. 1)
5. Breadboard - Small (Qty. 1)
6. Jumper Wires (Qty. As per your Requirement)
7. Power Bank - To Power the Circuit (Qty. 1) - Any other Power Sources can be used

## Circuit Connections:
![Decade Up & Down Counter Circuit Diagram](https://github.com/user-attachments/assets/ac190bbe-9002-4a09-bed6-e941a6fd632f) </br>
***Figure 1. Decade Up & Down Counter Circuit Diagram***

The circuit integrates a **7-segment display** with the **VSDSquadron Mini** microcontroller to display numbers from 0 to 9, forming a MOD-10 counter. Each segment of the 7-segment display (labeled A to G) is connected to specific digital pins on the VSDSquadron Mini. The segment pins is connected as follows: segment ***'A'*** to **PD1**, ***'B'*** to **PD2**, ***'C'*** to **PD3**, ***'D'*** to **PD4**, ***'E'*** to **PD5**, ***'F'*** to **PD6**, ***'G'*** to **PD7** and ***'DP'*** to **GND** on the microcontroller. Current-limiting resistor is added in series with each segment pin to protect the LEDs in the display. The common ground pin of the 7-segment display is connected to the **GND** pin of the microcontroller, and the display is powered by the **5V** supply from the VSDSquadron Mini.

A **3-terminal switch** is also used to toggle between up-counting and down-counting modes. The common terminal of the switch is connected to **PD0**, while the other two terminals are connected to **GND** and **5V** on the microcontroller. This configuration allows the microcontroller to read the switch’s state and determine the counting direction. When the switch connects **PD0** to **GND**, the microcontroller interprets it as an down-count command; when **PD0** is connected to **5V**, it counts up. The microcontroller reads these signals, incrementing the count for up mode and decrementing it for down mode, providing dynamic control over the counting direction.

## Pinout Diagram:
![Decade Up & Down Counter Pinout Diagram](https://github.com/user-attachments/assets/15ac4125-31ae-45e2-9a2e-f479514142b4) </br>
***Figure 2. Decade Up & Down Counter Pinout Diagram***

## Table for Pin Connection:
| VSDSquadron Mini Board | 7 Segment Display (Common Cathode) |
| :----: | :----: |
| PD1 | **A** - Pin 7 |
| PD2 | **B** - Pin 6 |
| PD3 | **C** - Pin 4 |
| PD4 | **D** - Pin 2 |
| PD5 | **E** - Pin 1 |
| PD6 | **F** - Pin 9 |
| PD7 | **G** - Pin 10 |
| GND | **DP** - Pin 5 |
| GND | **GND** - Pin 3, 8 |

| VSDSquadron Mini Board | 3 Terminal Slide Switch |
| :----: | :----: |
| 5V | Terminal 1 |
| PD0 | Common Terminal |
| GND | Terminal 2 |
