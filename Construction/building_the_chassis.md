# Building the chassis

To get started with the current version of the Lunar Rover Model, you will first need to build the cardboard chassis. The dimensions are as follows:
- Bottom plate: 140x280mm
- Side plates: 280x20mm
- Front & back plates: 140x20mm

Cut out one piece of cardboard for the bottom plate, two for the side plates and two for the top plate. Use a hot glue gun to glue the pieces together in a box shape. Arrange the yellow motors in the box and mark where the shaft should poke out. Use a pencil or hobby knife to create a generous hole to allow the shaft to turn freely. 

You will also need to 3D print four copies of the wheel provided in the "Construction" folder. When they are ready, you will have to line up the shaft of the motor to fit into the slot in the wheel. (You may have to sand the inside of the slot a bit if it's too tight.)

Position one IR sensor on each side of the front plate, making sure that the wheels don't block their range. Use a piece of masking tape or electrical tape to secure each one in place. Position the two ultrasonic sensors in between the IR sensors, with one or two centimeters in between them (it's okay if they overlap with the IR sensors) and push the four-pin headers through the cardboard. Use a small piece of tape to secure the top so they face forward.

<img width="4624" height="3472" alt="rover-front-closeup" src="https://github.com/user-attachments/assets/0f548936-cc9a-462b-a2e0-e7153ca0971b" />


Place the Arduino Nano on a half-size breadboard and stick the breadboard in the box. Wire the Arduino, sensors, LEDs, photoresistor, servo motor and HC-05 Bluetooth module as shown in the diagram. Secure the motor driver board in the box as well and wire the motors. Be sure to connect a common ground between the Arduino and the motor driver board.

<img width="3000" height="2241" alt="circuit diagram" src="https://github.com/user-attachments/assets/7e96bcaa-8462-477b-b27e-4e81c385aafb" />

Before adding either of the batteries, you will have to cut the red wire of both 9v battery connectors and solder an on/off switch to each one. This will make it so you don't have to pull apart your wiring to turn off the rover. When the switches are soldered and the connections wrapped in electrical tape to prevent short-circuits, connect one of the batteries to the motor driver board and the other to a 9v-5v buck converter. Connect the other side of the converter to the power and ground rails of the breadboard; and connect the 5v and GND pins of the Arduino to their respective rails.

If you are having trouble figuring out where the parts are supposed to go, check the photo gallery to see images of my configuration. It is very messy because this is a prototype so they may or may not be helpful to you. You may have to be creative in your configuration of the chassis, but as long as the wiring matches the diagram, the code will work.
