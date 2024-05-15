/*
  433 MHz RF Module Transmitter Demonstration 1
  RF-Xmit-Demo-1.ino
  Demonstrates 433 MHz RF Transmitter Module
  Use with Receiver Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
const int buttonPin1 = 2; 
const int buttonPin2 = 3; 
int buttonState1 = 0;
int buttonState2 = 0;
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
    // Initialize ASK Object
    rf_driver.init();
}

void loop()
{

    buttonState2 = LOW;
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState1 == HIGH) {
    const char *msg = "1";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
    }
    if (buttonState2 == HIGH) {
    const char *msg = "2";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
    }

} 
