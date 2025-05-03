<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>ISRO_Rover Repository</title>
</head>
<body>

  <h1>ISRO_Rover</h1>

  <p>This repository contains all the source code required to operate and test various components of a six-legged, robust rover developed as part of a project inspired by ISRO. The rover is equipped with a range of automated features including:</p>

  <ul>
    <li>Terrain detection</li>
    <li>Object detection and tracking</li>
    <li>Autonomous directional control</li>
    <li>360° motion capability</li>
    <li>First-Person View (FPV) camera integration</li>
    <li>Real-time object mapping</li>
  </ul>

  <h2>Repository Structure</h2>

  <p>The repository is organized into several folders, each dedicated to a specific subsystem or feature of the rover:</p>

  <h3>1. <strong>Sensors</strong></h3>
  <p>Contains code for interfacing and testing various sensors such as:</p>
  <ul>
    <li>DHT11 Temperature and Humidity Sensor</li>
    <li>Ultrasonic Distance Sensor</li>
    <li>Infrared (IR) Sensor</li>
    <li>Color Sensor</li>
    <li>Other sensors for environmental data and obstacle detection</li>
  </ul>

  <h3>2. <strong>Relay</strong></h3>
  <p>Includes scripts for controlling relay modules that manage the coordinated operation of multiple components such as:</p>
  <ul>
    <li>Robotic legs</li>
    <li>Servo motors</li>
    <li>Mechanical arms</li>
  </ul>

  <h3>3. <strong>RF24_Transceiver</strong></h3>
  <p>Implements communication protocols using the NRF24L01 transceiver module for wireless data transmission over a fixed frequency range.</p>

  <h3>4. <strong>Rover_Legs</strong></h3>
  <p>Provides functions for various leg movement capabilities, including:</p>
  <ul>
    <li>Forward and backward motion</li>
    <li>Sideways movement</li>
    <li>360° rotational control</li>
  </ul>

</body>
</html>
