# ⚡ Rapid Kindling Protocol Automation (Arduino + RTC-Based)

This repository provides firmware and documentation for automating the **Rapid Kindling (RK)** protocol used in epilepsy research. Unlike versions relying on microcontroller timing, this system uses a **DS3231 Real-Time Clock (RTC)** to guarantee long-duration precision.

---

## 🧠 Overview

Electrical stimulation is applied to the **basolateral amygdala (BLA)** in rodent models using surgically implanted electrodes. The Arduino-based system initiates stimulus trains at predefined intervals, following protocols described in:

- Álvarez-Ferradas et al., *Neurobiology of Disease*, 2015  
- Morales et al., *Frontiers in Cellular Neuroscience*, 2014  

The system includes:

- RTC-controlled stimulation timing  
- Manual start/cancel via push button  
- LCD display for time and status feedback  
- TTL signal output for external trigger control

---

## 🔧 Hardware Requirements

| Component               | Description                                 |
|-------------------------|---------------------------------------------|
| Arduino Uno / Nano      | Microcontroller                             |
| DS3231 RTC Module       | Precision timekeeping                       |
| I2C LCD (16x2, addr 0x27)| Real-time display                           |
| Push Button             | Starts/cancels protocol (connected to D2)   |
| Relay Output            | Triggers external stimulator (connected to D3) |
| Bipolar Stimulus Isolator | Safely delivers stimulation current        |
| Square-Wave Pulse Generator | Defines waveform (frequency, amplitude)   |

> ✅ Optional add-ons: buzzer, SD logger, multichannel expansion

---

## ⏱️ Protocol Timing

The Arduino gates stimulation trains at key intervals after button-press initiation. Each train lasts 10 seconds. The exact timing replicates RK paradigms:

| Elapsed Time | Event         |
|--------------|---------------|
| 00:20:00     | Stimulus 1    |
| 01:00:00     | Stimulus 2    |
| 01:40:00     | Stimulus 3    |
| 02:20:00     | Stimulus 4    |
| 03:00:00     | Stimulus 5    |
| 03:40:00     | Stimulus 6    |

The real-time clock ensures consistent delivery over long durations.

---

## ⚡ External Triggering & Bipolar Stimulus Isolation

This system acts as an **external trigger controller**, not a waveform generator. The relay output sends TTL-level pulses to gate an external **square-wave stimulator**, configured with:

- **Frequency**: 50–60 Hz  
- **Pulse Duration**: ~1 ms  
- **Train Duration**: 10 seconds  
- **Current Amplitude**: Subthreshold, based on post-discharge threshold (AD) testing

Stimulation is delivered via a **bipolar stimulus isolator**, ensuring:

- 🔒 Electrical safety and tissue protection  
- 🧪 Artifact minimization during recording  
- 📏 Reproducible current delivery across sessions

This modular design separates **timing logic (Arduino + RTC)** from **waveform control (external generator)**, following established methodology.

---

## 🖥️ Software Features

- Manual start/cancel protocol interface  
- Chronometer-style time display on LCD  
- Status messages for each stimulation event  
- Modular functions for relay control and timing conversions  
- Cancelable protocol at any time via button press

---

## 📐 Wiring Summary

| Signal               | Arduino Pin | Description                        |
|----------------------|-------------|------------------------------------|
| Push Button          | D2          | Start/cancel protocol              |
| Relay Output (TTL)   | D3          | Gates external stimulator          |
| DS3231 RTC           | SDA/SCL     | Timekeeping                        |
| LCD Display          | SDA/SCL     | Displays feedback                  |

---

## 🧬 Scientific Context

This system facilitates studies of **epileptogenesis and neural plasticity**, particularly involving:

- After-discharges (ADs)  
- Seizure threshold monitoring  
- Kindling progression in limbic regions

Compatible with:

- Optogenetic and chemogenetic stimulation  
- Electrophysiological recording systems  
- EEG and behavioral monitoring setups

---

## ✅ Ethical Compliance

All procedures follow ethical standards approved by the Bioethics Committee of the **University of Valparaíso**, including:

- Minimizing discomfort and stress in animal models  
- Scientific justification for stimulation paradigms  
- Trained personnel for animal handling  
- International compliance for animal research

---

## 🧠 Extensions and Improvements

- Interrupt-driven timing for enhanced stability  
- SD card logging of timestamps and stimulation events  
- Multi-channel expansion for bilateral stimulation  
- Integration with ESP32 or Teensy for wireless control  
- Cloud syncing or serial logging options

---

## 📄 License

Released under the **MIT License**. Free to use, modify, and redistribute for scientific or educational purposes.

---

## 🤝 Contributions

You're welcome to:
- Improve timing logic or modularity  
- Integrate new hardware or data logging  
- Share experimental datasets or outcomes  
- Translate documentation and expand use cases

---

## 📎 References

- Álvarez-Ferradas et al., *Neurobiology of Disease*, 2015  
- Morales et al., *Front. Cell. Neurosci.*, 2014  
- Martorell et al., *Neurobiology of Disease*, 2020  

---

👨‍🔬 Developed by: **Felipe Guiffa Gómez**  
📧 Email: `felipe.guiffa@postgrado.uv.cl`  
🌍 Valparaíso, Chile

