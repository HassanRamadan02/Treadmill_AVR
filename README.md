Smart Tradmail System (ATmega32)
📌 Project Overview

This project implements a Smart Tradmail System using the ATmega32 microcontroller running at 1 MHz.
The system integrates a stopwatch display, motor speed control, and external interrupt-based user interaction, displayed using six multiplexed 7-segment displays driven by a 7447 BCD-to-7-segment decoder.

The design focuses on efficient hardware usage, real-time interrupt handling, and precise timing using internal timers.

⚙️ Hardware Specifications

Microcontroller: ATmega32

Clock Frequency: 1 MHz

Display:

6 × Common Anode 7-Segment Displays

1 × 7447 BCD-to-7-Segment Decoder

NPN BJT transistors for display multiplexing

Motor Control: PWM generated using Timer0

Push Buttons:

Internal pull-up & external pull-down configurations

Timers Used:

Timer1 (CTC Mode) → Stopwatch counter

Timer0 → PWM generation

🧠 System Features

Stopwatch starts automatically when power is applied

Six-digit display using multiplexing technique

Motor speed control with increase/decrease buttons

Tradmail start, pause, and resume control

Fully interrupt-driven design for real-time responsiveness

🔌 Pin Configuration
🔹 7-Segment Display

PORTC (PC0–PC3): Connected to 7447 decoder BCD inputs

PORTA (PA0–PA5): Enable/Disable control for the six 7-segment displays using NPN transistors

🔹 External Interrupts
Interrupt	Edge Trigger	Function
INT0	Falling Edge	Start Tradmail
INT1	Rising Edge	Increase Motor Speed
INT2	Falling Edge	Decrease Motor Speed
🔹 Additional Buttons

Pause Button:

External pull-down resistor

Rising edge → Pause tradmail

Resume Button:

External pull-down resistor

Rising edge → Resume tradmail

⏱️ Timers Configuration
🕒 Timer1 (CTC Mode)

Used as a stopwatch counter

Generates precise timing interrupts

Starts counting immediately after power-on

⚡ Timer0 (PWM Mode)

Generates PWM signal for motor speed control

Speed adjusted via external interrupts

🔁 Multiplexing Technique

Only one 7-segment display is active at a time

Displays are rapidly switched using transistor control

Due to persistence of vision, all six digits appear continuously ON

A single 7447 decoder is shared among all displays

🚦 System Workflow

Power ON → Stopwatch starts automatically

INT0 button → Tradmail starts

INT1 button → Motor speed increases

INT2 button → Motor speed decreases

Pause button → Tradmail pauses

Resume button → Tradmail resumes

Display updates continuously using multiplexing


🎯 Learning Outcomes

AVR Timers (CTC & PWM modes)

External Interrupts configuration

Multiplexed 7-segment displays

Hardware-efficient display driving

Real-time embedded system design

🧑‍💻 Author

Hassan Ramadan
Mechatronics Engineer | Embedded Systems & Robotics
