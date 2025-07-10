# ⚡ Rapid Kindling Protocol Automation (Arduino + RTC-Based)

This repository contains firmware and documentation for automating the **rapid kindling protocol (RK)** used to induce epileptogenesis in rodent models. Unlike versions relying on internal timers, this implementation uses an **external RTC module (DS3231)** to ensure precision over extended durations.

## 🧠 Overview

Electrical stimulation is applied to the **basolateral amygdala (BLA)** via implanted electrodes. The Arduino system triggers a stimulation relay at preset intervals consistent with published protocols:

- Álvarez-Ferradas et al., *Neurobiology of Disease*, 2015  
- Morales et al., *Frontiers in Cellular Neuroscience*, 2014  

A 16x2 I2C LCD screen provides real-time feedback, while a momentary push-button enables manual initiation and cancellation. Precise timing is driven by real-time clock readings, mitigating drift across long protocols.

## 🔧 Hardware Requirements

- **Arduino Uno or Mega 2560**  
- **DS3231 Real-Time Clock (RTC)**  
- **I2C LCD Display (16x2, address 0x27)**  
- **Momentary push button** (connected to D2)  
- **stimulation trigger interface (BNC female conector)** (connected to D3)  
- Optional: buzzer, opto-isolators, SD logger

## ⏱️ Protocol Timing

Stimulation occurs in 10-second bursts at specific intervals after protocol initiation:

| Time (hh:mm:ss) | Stimulation Event |
|------------------|-------------------|
| 00:20:00         | Stimulus 1        |
| 01:00:00         | Stimulus 2        |
| 01:40:00         | Stimulus 3        |
| 02:20:00         | Stimulus 4        |
| 03:00:00         | Stimulus 5        |
| 03:40:00         | Stimulus 6        |


This timeline replicates the RK pattern designed to induce **after-discharges (ADs)** and progressive seizure activity. Timekeeping is maintained via DS3231, and outputs are driven with millisecond-level resolution.

## 💡 Features

- Manual start via push-button interface  
- Cancel at any time during the protocol  
- Chronometer-style display of elapsed time  
- Status feedback for each stimulation pulse  
- RTC-based timing avoids microcontroller drift over hours  
- Scalable and modifiable for extended paradigms

## 📐 Wiring Overview

| Component             | Function                             | Arduino Pin |
|----------------------|--------------------------------------|-------------|
| 🔘 Push Button        | Start/cancel protocol                | D2          |
| ⚡ Stimulation Trigger| Sends HIGH pulse to stim device      | D3          |
| ⏰ DS3231 RTC         | Maintains absolute time              | SDA/SCL     |
| 🖥️ I2C LCD            | Displays time and status             | SDA/SCL     |

### Notes:
- **Button debounce** is handled via `delay(25)` cycles.
- The stimulation logic uses second-based comparisons between RTC values.
- For enhanced feedback, a buzzer or LED could be triggered alongside the relay.

## 🧬 Scientific Context

This setup supports behavioral and electrophysiological studies of **epileptogenesis** by standardizing stimulation delivery. It can be extended to interface with ABF-based data loggers, optogenetic trigger modules, or synchronized EEG acquisition.

## ✅ Ethical Compliance

All procedures comply with **ethical guidelines** approved by the Bioethics Committee of the University of Valparaíso. This includes:

- Minimizing animal discomfort  
- Scientific justification for kindling protocols  
- Trained personnel for humane handling  
- Adherence to international animal research standards

## 📄 License

This repository is shared under the **MIT License**. Feel free to modify, reuse, and extend it for educational or research use.

## 🤝 Contributions

You’re welcome to help improve this project by:
- Refactoring timing logic for interrupt-based routines  
- Integrating multi-channel stimulation  
- Adding data logging or cloud sync features  
- Porting to microcontrollers like Teensy or ESP32  
- Sharing use cases and experimental datasets

## 📎 References

- Álvarez-Ferradas et al., Neurobiology of Disease, 2015  
- Morales et al., Front. Cell. Neurosci., 2014  
- Martorell et al., Neurobiology of Disease, 2020  

---

👨‍🔬 Developed by **Felipe Guiffa Gómez**  
📧 felipe.guiffa@postgrado.uv.cl  
🌍 Valparaíso, Chile


