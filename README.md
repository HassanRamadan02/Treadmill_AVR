# Smart Tradmail System (ATmega32)

## 📌 Project Overview
The **Smart Tradmail System** is an embedded systems project implemented using the **ATmega32 microcontroller** operating at a **1 MHz clock frequency**.  
The system combines a **stopwatch**, **motor speed control**, and **interrupt-driven user interaction**, with output displayed on **six multiplexed common-anode 7-segment displays** using a **7447 BCD-to-7-segment decoder**.

The project demonstrates efficient use of timers, external interrupts, and multiplexing techniques commonly used in real-time embedded applications.

---

## ⚙️ Hardware Specifications
- **Microcontroller:** ATmega32  
- **Clock Frequency:** 1 MHz  
- **Display:**
  - 6 × Common Anode 7-Segment Displays
  - 1 × 7447 BCD-to-7-Segment Decoder
  - NPN BJT transistors for display multiplexing
- **Motor:** DC Motor controlled via PWM
- **Push Buttons:** Internal pull-up & external pull-down
- **Timers Used:**
  - **Timer1 (CTC Mode):** Stopwatch counter
  - **Timer0 (PWM Mode):** Motor speed control

---

## 🧠 System Features
- Stopwatch starts automatically when power is applied
- Six-digit display using multiplexing technique
- Motor speed control (increase / decrease)
- Tradmail start, pause, and resume functionality
- Interrupt-driven real-time response

---

## 🔌 Pin Configuration

### 🔹 7-Segment Display Interface
| Component | ATmega32 Port |
|--------|--------------|
| 7447 BCD Inputs | PORTC (PC0–PC3) |
| 7-Segment Enable Pins | PORTA (PA0–PA5) |

Each 7-segment display is enabled using an NPN BJT transistor controlled by PORTA.

---

### 🔹 External Interrupts
| Interrupt | Edge Trigger | Function |
|---------|-------------|----------|
| INT0 | Falling Edge | Start Tradmail |
| INT1 | Rising Edge | Increase Motor Speed |
| INT2 | Falling Edge | Decrease Motor Speed |

---

### 🔹 Additional Control Buttons
| Button | Connection | Trigger | Function |
|------|-----------|--------|----------|
| Pause | External Pull-Down | Rising Edge | Pause Tradmail |
| Resume | External Pull-Down | Rising Edge | Resume Tradmail |

---

## ⏱️ Timers Configuration

### 🕒 Timer1 – CTC Mode
- Used as a **stopwatch counter**
- Generates periodic interrupts
- Starts counting immediately after power-up

### ⚡ Timer0 – PWM Mode
- Generates PWM signal for motor control
- Duty cycle adjusted via external interrupts

---

## 🔁 Multiplexing Technique
- Only **one 7-segment display is active at any time**
- Displays are switched rapidly using transistor control
- A **single 7447 decoder** is shared among all displays
- Due to persistence of vision, all six digits appear continuously ON

---

## 🚦 System Operation Flow
 1. Power ON → Stopwatch starts automatically
 2. INT0 button → Tradmail starts
 3. INT1 button → Motor speed increases
 4. INT2 button → Motor speed decreases
 5. Pause button → Tradmail pauses
 6. Resume button → Tradmail resumes
 7. Display updates continuously using multiplexing

---

## 🎯 Learning Outcomes

-  AVR Timers (CTC & PWM modes)
-  External Interrupts configuration
-  Multiplexed 7-segment displays
-  Hardware-efficient display driving
-  Real-time embedded system design

---

## 🧑‍💻 Author

**Hassan Ramadan**

Mechatronics Engineer | Embedded Systems & Robotics
