# Lucky Slot Machine
A lucky slot machine using four LEDs, a passive buzzer, and a pushbutton.

---

## 🚀 How It Works

When the button is pressed, the lights flash up randomly. They start flashing slowly until they stop completely. The end result can be considered a "win" if 3 lights next to each other are on or all four are on. The code does not rig the machine, rather it uses random seeds from an unused pin to decide which lights to turn on.

### Hardware
- **Development Board:** Arduino Nano
- **Main Components:** Passive Buzzer + LEDs
- **Software:** Arduino IDE

### Cool Features
- Random flashing + sound effects
- Flashing slowing down (simulating a real slot machine)
- Portability
- Amplified sound (using transistor and diode)

---

## 📊 Circuit Layouts

### Wiring Diagram

Below is the wiring diagram for the project:

![Wiring Diagram](Lucky_Slot_Machine.png)

**Note: This wiring diagram was made in Wokwi. Since Wokwi doesn't have a Power MB V2, transistor, or diode in the actual build, the wiring diagram is an approximation of the physical build but retains the correct wiring and functionality.**

### Schematic

Below is the schematic generated in Tinkercad:

[![Schematic](Schematic.png)](Schematic.png)

*Schematic coming soon*

## 🔗 Wokwi Simulation
Try the interactive simulation of the project here:

[Open in Wokwi](https://wokwi.com/projects/478240792839430145)

---
## 🖼️ Project Photo

See the project (may have some issues viewing it on desktop):

[Click here](Lucky_Slot_Machine_Image.png)

## 🎥 Video Demonstration

Watch the project in action + an explanation of the build:

[▶ Watch the Video](https://www.youtube.com/watch?v=-f2DpEiu2OI)

---

## 📁 Repository Contents

- `Lucky_Slot_Machine.ino` — Arduino source code
- `README.md` — Project documentation
- `LICENSE` — Apache License 2.0
- `Lucky_Slot_Machine_Image.png` — Project photo
- `Lucky_Slot_Machine.png` — Wiring Diagram 
- `Schematic.png` — Coming Soon!

---

## 🛠️ Components Used

- Arduino Nano Board
- Passive Buzzer
- 4 LEDs
- Pushbutton
- Transistor
- Diode
- Resistors
- Power MB V2 + 9V Battery
- Jumper wires

---

## 💡 What I Learned

I practiced my ability to use the sound-amplification circuit to amplify sound of the buzzer. It uses a transistor & diode, and allows amplified sound with the **same buzzer**.

---

## 📜 License

This project is licensed under the Apache License 2.0.
