#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// RFID reader pins
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Servo motor pin
Servo doorServo;
int servoPin = 6;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  SPI.begin();  // Initialize SPI
  mfrc522.PCD_Init();  // Initialize MFRC522 RFID reader
  doorServo.attach(servoPin);  // Attach servo to pin
  doorServo.write(0);  // Initial position (locked)
  Serial.println("Scan your RFID card to unlock the door.");
}

void loop() {

  if (mfrc522.PICC_IsNewCardPresent()) {

    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.println("Card detected!");

      String cardID = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        cardID += String(mfrc522.uid.uidByte[i], HEX);
      }

      Serial.print("Card ID: ");
      Serial.println(cardID);

      if (cardID == "719a228") { 
        unlockDoor();
      } else {
        Serial.println("Unauthorized card.");
      }

      mfrc522.PICC_HaltA(); 
    }
  }
}

void unlockDoor() {
  Serial.println("Unlocking door...");
  doorServo.write(180);  
  delay(5000);
  doorServo.write(0);
  Serial.println("Door locked again.");
}