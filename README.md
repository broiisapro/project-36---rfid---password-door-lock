This project implements an RFID-based door lock system, which uses an MFRC522 RFID reader and a servo motor to control the locking mechanism. The system will unlock the door when a registered RFID card is scanned, and it will lock the door after a short delay. 

### Components Used:
1. **MFRC522 RFID Reader**: Reads RFID cards.
2. **Servo Motor**: Controls the locking mechanism (e.g., a door lock).
3. **Arduino**: Microcontroller to run the program and interface with the components.
4. **Wires and Breadboard**: For making the necessary connections.

### Connections:
- **MFRC522 RFID Reader**:
  - `RST_PIN` (Reset): Pin 9
  - `SS_PIN` (Slave Select): Pin 10
  - `MISO`, `MOSI`, `SCK`, `GND`, and `VCC` are connected to their corresponding Arduino pins.
  
- **Servo Motor**:
  - `servoPin`: Pin 6 (Control pin for the servo motor)

### How It Works:
1. **RFID Scanning**: When the system detects a new RFID card, it reads the card’s unique ID.
2. **Access Control**: If the RFID card ID matches the pre-set valid card ID (in this case, "719a228"), the system sends a command to the servo motor to unlock the door by rotating it.
3. **Door Locking**: After 5 seconds, the servo motor will rotate back to its initial position, locking the door again.

### Code Explanation:
1. **Library Includes**:
   - `SPI.h`: For communication with the RFID reader over SPI.
   - `MFRC522.h`: For controlling the MFRC522 RFID module.
   - `Servo.h`: For controlling the servo motor.

2. **Pin Definitions**:
   - `RST_PIN` and `SS_PIN` are defined for controlling the RFID module.
   - `servoPin` is defined for controlling the servo motor.

3. **Setup**:
   - Initializes serial communication, SPI, and the RFID module.
   - The servo motor is set to its initial "locked" position (0 degrees).

4. **Main Loop**:
   - Continuously checks for a new RFID card.
   - If a card is detected, its unique ID is read and displayed on the Serial Monitor.
   - If the card ID matches the authorized ID, the door is unlocked by moving the servo to 180 degrees.
   - After 5 seconds, the door is locked again by resetting the servo to 0 degrees.

### Requirements:
- **Arduino IDE**: Installed with the necessary libraries:
  - `MFRC522` library for the RFID reader
  - `Servo` library for controlling the servo motor
  - `SPI` library for communication with the RFID module

### Notes:
- You may need to change the `cardID` in the code (`"719a228"`) to match the ID of your authorized RFID card.
- Ensure the servo motor is properly calibrated to your door lock mechanism for smooth operation.

### Troubleshooting:
- **No card detected**: Check connections to the RFID module, ensure the card is placed correctly on the reader.
- **Servo not moving**: Verify the servo connections and ensure the servo is not overloaded or malfunctioning.

made with the help of AI
