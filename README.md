# AUTOMATIC-WATER-DISPENSER-

AUTOMATIC WATER DISPENSER SYSTEM - PROJECT DOCUMENTATION

Introduction:
The Automatic Water Dispenser is designed to supply water to a grinding machine process in a controlled manner.
The system uses an Arduino microcontroller to monitor water levels via a sensor, control a DC water pump through a MOSFET switch, and provide status feedback via LEDs and buzzer.
The prototype demonstrates how water can be automatically dispensed while ensuring the pump is protected from dry running.

Objectives:
To develop a low-cost, automated water dispenser for grinding processes.
To prevent dry running of the pump using a water level sensor.
To enable manual ON/OFF control via a toggle switch.
To provide status indication through LEDs and buzzer.
To validate that the design works with a 12 V submersible DC pump.

System Components:
Hardware:
Arduino Uno / Nano (microcontroller)
12 V DC Submersible Water Pump (HG 613, Hmax 2.5m, Qmax 300 L/h).
N-channel MOSFET (e.g., IRFZ44N or similar).
Water level sensor (capacitive/analog probe).
12 V Battery (power source).
Voltage regulator (7805 or buck converter) – steps 12 V down to 5 V for Arduino.
LEDs (Pump ON indicator, Pump OFF indicator).
Resistors:
10 kΩ (MOSFET gate pulldown).
220 Ω (LED current limiting).
Switch (Enable ON/OFF).
Breadboard and jumper wires.

Software:
Arduino IDE.
Serial Monitor for debugging.

System Design

Block Diagram

12 V Battery
│
├──> Pump (+) ───────────────┐
│                            │
└──> Buck Converter (5 V) → Arduino + Sensors
│
Water Sensor ─────┘
│
Enable Switch ────┘
│
MOSFET Gate ──────> Pump (–) Control
│
LEDs/Buzzer ─────> Indicators

Circuit Description

1. Power: A 12 V battery powers both the pump and the Arduino (via buck/7805 regulator).


2. Pump Control:



Pump positive → battery +12 V.

Pump negative → MOSFET Drain.

MOSFET Source → Battery GND.

MOSFET Gate → Arduino digital pin (with 10 kΩ pulldown to GND).

3. Water Level Sensor: Connected to Arduino analog input. Detects water presence/absence.


4. Enable Switch: Connected to Arduino pin (INPUT_PULLUP). Allows enabling/disabling of the system.


5. Indicators:



Pump ON → Green LED.

Pump OFF/Refill Needed → Red LED + buzzer alert.

Software Logic (Algorithm)

1. Initialize pins (pump, buzzer, LEDs, switch, sensor).


2. Continuously read:



Enable switch (ON/OFF).

Water level sensor (WET/DRY using thresholds).

3. If Enable OFF → Pump OFF, indicators OFF.


4. If Enable ON →



If sensor detects WET → Pump ON (Green LED).

If sensor detects DRY → Pump OFF, Red LED ON, buzzer alert.

5. Print status to Serial Monitor for debugging.

Testing & Results
Sensor correctly detects water level (dry vs wet).
Pump runs only when vessel contains enough water.
Pump shuts down when vessel empty (prevents dry run).
Enable switch manually controls system ON/OFF.
LEDs show status (Green = Pump ON, Red = Pump OFF).
Buzzer alerts when vessel is empty.

Applications
Grinding machine water feed system.
Automatic livestock/poultry watering.
Household automatic water dispensers.

Conclusion
The prototype demonstrates a working automatic water dispenser system with simple electronics. The design is modular and can be improved with:
