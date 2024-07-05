# electronics
📟 Home of my electronic projects and anything electronics related

## Sensor and modules Guide

### LM393

- Voltage Comparator.
- 2 pins to connect to sensor.
- 4 pins to to connect to Arduino: GND, VCC, Analog output (A0), and Digital output (D0).
- It also has a configurable thresould using a Potentiometer. Thresould decides how much voltage should set the digital output (D0) to HIGH stage.

### LM35

- Used to meassure environment temperature.
- 3 pins: GND, VCC, and analog output (A0).
- For every 1 centigrades of temperature, it outputs 10 milli-volts.

```
sensorValue / 1023 = temp / 500
temp = 0.488 * sensorValue
```

### DHT11 Module

- Temperature and Humidity sensor.
- DHT11 component needs pullup resistor, but the DHT11 module already has the built-in pullup resistor on the board.
- Less accurate and slower than LM35. Outputs 1 times in a second. Useful for temperature 0-50 and humidity 20%-80%.

### LCD 1602-I2C

- Liquid Crystal Display

### PIR Sensor

- VCC, GND, and Analog output pings.
- Two potentiometer to config delay and sensitivity.

### LM393 Sound Sensor

- It's a LM393 as described above, but instead of two sensor pins, it has a sound sensor built-in.

### TCRT5000

- Reflective optical color detection module.
- Usually used for object detection, line tracking, and material detection.
- Installed on a LM303 module.
- On white surfaces it outputs 1023 (arduino), and 0 on black surfaces on the analog output.

### L293D

- Used to control the speed and direction of up to 2 DC motors.

### Others

- LED-RGB
- Seven Segments (e.g. TM1637)
- Dot Matrix
- Tilt Switch
- Active Buzzer: Black surface under the module. Use `digitalWrite` to set the pin to HIGH or LOW.
- Passive Buzzer: Green surface under the module (you can see the board). Use `tone(pin, freq, duration)` to generate frequency for playing different musical notes.
- Photoresistor
- DC Motors
- SG90 Servo Motors
- BYJ48 Step Motors (4 Phase) + ULN2003A Driver
- Ultrasonic Sensors
- 74HC595 Shift Register
- DS1302 Clock Module