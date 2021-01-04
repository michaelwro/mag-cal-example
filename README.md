# Calibrating 3-Axis Magnetometers

Code By: Michael Wrona, *B.S. Aerospace Engineering*

This repository explains a general procedure to calibrate 3-axis mangetometer sensors. I will use an Arduino to read magnetometer data from an I2C sensor, transmit it over serial to a PC, log the data to a text file, and generate calibration parameters with a software named Magneto.

## What are Magnetometers?

Before explaining the calibration procedure, it would be good to review what magnetometers are and what they measure. Magnetometers are basically 3D compasses - they are used to determine earth's magnetic field vector and therefore compass heading relative to magnetic north. They consist of three individual magnetic field sensors arranged orthogonal to each other to form a triad. Magnetometers are used in many applications across many fields, but since I come from an aerospace background, I will explain them from an aerospace applications perspective. Magnetometers are used whenever heading needs to be known. They are very important navigation sensors in boats, multirotor drones, airplanes, fighter jets, missiles, rockets, and spacecraft. Magnetometers are frequently the source of multirotor navigation errors and crashes, so careful attention must be given to calibration (if you know, you know).

## Magnetometer Error Sources

It would also be a good idea to know what errors we are correcting for with calibration. Here is a brief explaination of the major sources of error in magnetometer measurements we will correct for.

### Hard Iron Distortion

Hard iron distortion (also called hard iron bias) is the most critical distortion we will account for in calibration. Hard iron offset originates from objects that generate their own mangetic fields. Examples of hard iron offset sources include magnets, high-current wires, speaker wires, and magnetized pieces of metal. They produce constant magnetic fields and will cause a constant offset in mangetometer measurements.


### Soft Iron Distortion

Soft iron distortions are created by [paramagnetic materials](https://en.wikipedia.org/wiki/Paramagnetism#:~:text=Paramagnetism%20is%20a%20form%20of,of%20the%20applied%20magnetic%20field.). Earth's magnetic field induces magnetic fields in paramagnetic materials and cause distortions that simultaneously deflect and shrink earth's magnetic field. Soft iron distortions are commonly caused by ferrous materials (iron, steel, etc.), nickel, and carbon fiber.

### Non-Orthogonal Sensor Axes (Misalignment Errors)

Magnetometer sensors are not perfect and are subject to manufacturing errors. The mathematics in navigation equations assume the magnetometer sensor axes are perfectly orthogonal (at right angles) to each other. In reality, they are very slightly non-orthogonal and therefore introduce non-othogonality errors. This effect is much less significant as hard and soft iron distortions, but must still be calibrated for in high-precision applications.

## Other Magnetometer Error Sources

### Temperature Variation

Magnetometers are affected by temperature variations, making calibration parameters also a function of temperature. Tactical-grade and better magnetometers are often temperature-compensated to calibrate for temerature variations. Most hobby-grade ones aren't.

### Sensor Accelerations

Magnetometers are also affected by external accelerations to the sensor. These errors are difficult to compensate for and shouldn't be of concern for primarily static applications.


## Mitigating Magnetometer Errors

Since mangetic field intensity follows the inverse square law, distance will be your best friend in reducing magnetic field distortions. Mounting the accelerometer as far away as pratical from magnetic and electromagnetic sources will reduce hard iron distortions. Keeping the magnetometer away from iron, nickel, and carbon fiber will reduce soft iron distortions. Purchasing high-quality magnetometers will reduce the likelihood of misaligned sensor axes and may be temperature-compensated out-of-the-box.


# Calibration Procedure

## Step 1: Create Code to Output 
My calibration procedure assumes that you can output magnetometer readings to a tab-delimited text file. I will be using an Arduino Uno to read data from my 

