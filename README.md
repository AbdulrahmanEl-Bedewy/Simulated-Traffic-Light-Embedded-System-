# Simulated-Traffic-Light-Embedded-System-
An embedded system project that simulates a traffic light. Made as a part of FWD Professional Embedded System Nanodegree.

# System Description
#### The system is a simulated traffic light with a pedestrian cross walk. A button is provided for pedestrians to use in case they need to cross the road while the traffic light, for cars, is operating. If pressed, the button causes the cars’ traffic light to switch red allowing the person to safely cross the road without having to wait for the traffic light to turn red on its own. 


# System Design
## Components
* 10 kΩ resistor
* 6 100 Ω resistors
* 2 Green LEDs
* 2 Yellow LEDs
* 2 Red LEDs
* Push button
* ATmega32 microcontroller

## Connections
#### The 3 LEDs of the car traffic light are connected on first 3 pins of port A. The remaining 3 LEDs of the pedestrian traffic light are connected on the first 3 pins of port B. Each LED has a 100 Ω resistance connected with it in series to prevent excess current that can burn out the LED. 
#### The button is connected on pin 2 (INT0) of port D in a pull down configuration.

![image](https://user-images.githubusercontent.com/96942793/205436018-88dee78e-716e-4c91-8d16-e443a41416e7.png)

## System Flowchart
![Flowchart](https://user-images.githubusercontent.com/96942793/205434914-d2512068-4903-4430-8473-f3f780175f11.png)

# System Environment
#### The system was programmed in C and designed to work on the ATmega32 microcontroller. 

## Inputs/Outputs 
####
#### The only input the system accepts comes in the form of a push button. It activates an interrupt on falling edges only (i.e. when the button is released) to prevent the system from responding to long presses. 
#### The system output comes in the form of 6 LEDs that represent car and pedestrian traffic lights.

# Simulation 
![User Stories](https://user-images.githubusercontent.com/96942793/205434846-a9a1ea4f-e9db-4820-83fa-cfca06317143.gif)


