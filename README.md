# Irrigation-System
This project automates the process of watering plants by monitoring soil moisture levels. The system turns on the irrigation pump when the soil is too dry and turns it off once the soil reaches an optimal moisture level.

## Features
- **Soil Moisture Detection**: Automatically monitors soil moisture using capacitive sensors.
- **Automatic Watering**: Activates the irrigation pump when moisture levels fall below the set threshold.
- **Real-Time Display**: Displays current moisture levels and system status on an LCD screen.
- **Data Logging**: Logs soil moisture data to a microSD card for future analysis.
- **Mode Switching**: Choose between "Dry," "Moist," "Wet," or "Custom" modes to set moisture thresholds.

## Hardware Used
- **Arduino UNO**: Microcontroller to control the system.
- **Capacitive Soil Moisture Sensor**: Used to measure the moisture level of the soil.
- **5V Relay Module**: Controls the water pump.
- **5V Submersible Water Pump**: Pumps water to the plants.
- **16x2 LCD with I2C**: Displays the soil moisture readings and system status.
- **MicroSD Card Adapter**: Stores the moisture readings and logs.
- **9V Battery**: Powers the Arduino and other components.

## Libraries Used
- `Wire.h`: For I2C communication with the LCD display.
- `LiquidCrystal_I2C`: To control the LCD display via I2C.
- `SD.h`: For reading/writing to the microSD card.

## Setup Instructions
1. **Wiring**: Connect the components as follows:
   - Soil moisture sensor to **A0** pin.
   - Relay module to **pin 7**.
   - LCD screen connected via **I2C** interface (SDA to A4, SCL to A5).
   - Water pump controlled via relay.

2. **Libraries**: Install the necessary libraries in Arduino IDE:
   - `Wire.h`
   - `LiquidCrystal_I2C`
   - `SD.h`

3. **Upload the Code**: Upload the Arduino sketch to the Arduino board using the Arduino IDE.

4. **Powering Up**: Power the system using a 9V battery or external power source.

## Versioning

### Software Versioning
- **Arduino IDE Version**: 1.8.13
- **Libraries**:
  - `Wire.h`: Version 1.0.1
  - `LiquidCrystal_I2C`: Version 1.2.0

### Hardware Versioning
- **Arduino UNO**: Version 1.0.0
- **Soil Moisture Sensor**: Capacitive,
