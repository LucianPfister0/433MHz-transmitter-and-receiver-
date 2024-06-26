/*
  433 MHz RF Module Receiver Demonstration 1
  RF-Rcv-Demo-1.ino
  Demonstrates 433 MHz RF Receiver Module
  Use with Transmitter Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
const int ledPin1 =  2;
const int ledPin2 =  3;

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
  
    // Set buffer to size of expected message
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.println((char*)buf);         
    }
    
}
