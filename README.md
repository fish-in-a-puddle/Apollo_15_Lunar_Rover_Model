# Apollo 15 Lunar Rover Model v0
A Bluetooth-controlled model of the Apollo 15 lunar rover using an Arduino Nano and an HC-05 Bluetooth module.

#### Check out the project on Stardance! https://stardance.hackclub.com/projects/1942 

## Description
The Apollo 15 Lunar Rover Model is a robot controlled by Bluetooth designed to look as similar as possible to the actual lunar roving vehicle used by Commander David Scott and Lunar Module Pilot James Irwin during the Apollo 15 mission. It can be driven using Bluetooth or set to navigate on its own using two ultrasonic sensors and two IR sensors. The ultrasonic sensors detect obstacles in the path of the rover as it moves forward and the IR sensors are used to check which direction is clear to turn backwards when the rover encounters an obstacle. It also has two LED headlights which can be turned on and off using bluetooth or set to turn themselves on and off depending on the light level detected by a photoresistor. The rover is powered by two 9v batteries: one to power the Arduino, HC-05 module and other components through a 9v-5v buck converter and one to provide power to the motors. 

At the moment, the model doesn't look very similar to the actual roving vehicle. This is because the current version of the robot is a prototype built with cardboard to test the code and capabilities of the sensors. Version 0 is being shipped simply to show the process of creating the eventual version 1, which will feature a 3D printed chassis, an improved control app, and will resemble the actual rover much more. The rover is not very sturdy and is intended to be used as an educational tool or to be driven inside.

## Getting started
To get started with the current version of the Lunar Rover Model, you will first need to build the cardboard chassis. For instructions on building and wiring the rover, check out [this guide](building_the_chassis.md).

Once the chassis is built and the components are wired, it is time to flash the firmware to the Arduino. If you want your rover to simply drive itself around with no help from a driver, copy the code from lunar-rover-obstacle-detectv0.4.ino and paste it in the Arduino IDE. You can also download the file, place it in a folder named [lunar-rover-obstacle-detectv0.4](/workspaces/Apollo_15_Lunar_Rover_Model/Firmware/lunar-rover-obstacle-detectv0.4.ino) and open it in the IDE. If you want the rover to be able to be driven or to be set to self-navigation, copy the code from [lunar-rover-completev0.2.ino](/workspaces/Apollo_15_Lunar_Rover_Model/Firmware/lunar-rover-completev0.2.ino) and paste it in the Arduino IDE. Before flashing the code to the Arduino, you MUST disconnect the Bluetooth module from the Arduino. This is because if you don't, the Arduino will prioitize its serial communication with the Bluetooth module over the USB connection and you will get an error message.

To control the rover with Bluetooth, you will have to install the app on your mobile device. For Android, download and install the .apk file  in the "Control App" folder. If you have an Apple device, download and install the .ipa file.

## Troubleshooting

If you are having issues with the motors, check that you have connected GND on the motor driver board to the ground rail on the breadboard as well as the ground of the battery.

If the rover is moving backwards randomlyu when when self-navigation is enabled, adjust the angle of the ultrasonic sensors. If they are tilted down they will pick up the floor as an obstacle.

If you are having trouble reconnecting the HC-05 to your phone, try making your phone "forget" the device and pair it again. You may be asked to enter a PIN to connect to the module. The code is usually 1234 or 0000.

If you encounter other problems, feel free to send a question to fish.in.a.puddle42@gmail.com. I'll see if I can help. 

## Credits

Original wheel models: https://www.thingiverse.com/thing:5636299/comments



