/*

OUTPUT COMMA SEPARATED MAGNETOMETER READINGS

Designed to work with Adafruit's FXOS8700 + FXAS21002 9-DOF IMU
module. See link below:
    https://www.adafruit.com/product/3463

Code By: Michael Wrona
Created: 14 Jan. 2021

Arduino Uno Pin Layout
----------------------
    (Sensor) - (Arduino)
    VIN - +3V3
    GND - GND
    SCL - A5
    SDA - A4

*/



#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>



// Create accelerometer/magnetometer object
Adafruit_FXOS8700 AccelMag = Adafruit_FXOS8700(0x8700A, 0x8700B);

sensors_event_t AccelEvent, MagEvent;  // Measurement types

void setup() {
    Serial.begin(115200);  // Baud rate

    // Initialize accel/mag sensor
    if (AccelMag.begin(ACCEL_RANGE_4G) == false) {
        Serial.println("Error initializing FXOS8700 sensor. Check connections.");
        while(1);
    }

    delay(500);
}



void loop()
{
    AccelMag.getEvent(&AccelEvent, &MagEvent);  // Get data

    // Transmit over serial
    Serial.print(MagEvent.magnetic.x, 6); Serial.print(",");
    Serial.print(MagEvent.magnetic.y, 6); Serial.print(",");
    Serial.println(MagEvent.magnetic.z, 6);

    delay(100);  // 10 Hz
}

