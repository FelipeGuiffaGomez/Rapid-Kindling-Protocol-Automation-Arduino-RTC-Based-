# Rapid Kindling Protocol Automation (Arduino-Based)

This repository contains the code and documentation for automating the **rapid kindling protocol (RK)** used to induce epileptogenesis in rodent models, based on well-established methodologies in neuroscience research.

## 🧠 Overview

The RK protocol consists of controlled electrical stimulation applied to the **basolateral amygdala (BLA)** using implanted electrodes. This Arduino-based script initiates a stimulation sequence that matches experimental timelines described in:

- Álvarez-Ferradas et al., 2015  
- Morales et al., 2014  

The device displays real-time feedback via an LCD screen, allows manual control via a push button, and activates a digital output pin connected to an external stimulator at specific intervals over several hours.

## 🔧 Hardware Requirements

- **Arduino Uno or compatible board**  
- **I2C LCD Display (16x2, address 0x27)**  
- **Momentary push button (connected to pin 2)**  
- **Output relay or pulse generator interface (connected to pin 3)**  
- Optional: Housing, electrodes, data logger

## ⏱️ Protocol Timing

The stimulation pin is activated for 10 seconds at these precise time points:

| Time | Event             |
|------|-------------------|
| 00:20:00 | Stimulation 1 |
| 01:00:00 | Stimulation 2 |
| 01:40:00 | Stimulation 3 |
| 02:20:00 | Stimulation 4 |
| 03:00:00 | Stimulation 5 |
| 03:40:00 | Stimulation 6 |

These intervals replicate the RK pattern used to generate **after-discharges (ADs)** and progressively induce seizure activity in kindled subjects.

## 💡 Features

- Manual start and cancel options via button interface  
- Chronometer display with real-time updates  
- Visual feedback for stimulation status  
- Simple and adaptable codebase using `FlexiTimer2` for timing logic

## 📚 Scientific Context

This project is inspired by experimental protocols designed to model **epileptogenesis** in vivo. Fully kindled animals display generalized seizures and ADs detectable via EEG. The code provides a timing scaffold for interfacing with commercial or custom stimulation devices.

## 📄 License

This project is licensed under the MIT License — feel free to use, modify, and expand it for educational or research purposes.

## 🤝 Contributions

Pull requests and community feedback are welcome. You can contribute by:
- Enhancing timing precision using hardware timers or RTC modules  
- Integrating data logging features  
- Porting to other microcontroller platforms  
- Sharing alternative protocol implementations or experimental data

## 📎 References
- Martorell et al., Neurobiology of Disease, 2020
- Álvarez-Ferradas et al., Neurobiology of Disease, 2015  
- Morales et al., Frontiers in Cellular Neuroscience, 2014  


