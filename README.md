# Apollo 15 Lunar Rover Model v0
A Bluetooth-controlled model of the Apollo 15 lunar rover using an Arduino Nano and an HC-05 Bluetooth module.

[![Watch the demo!](Images/rover-right-front.jpg)](https://youtu.be/fayXKmGm4Ek?si=QLX--hcnvoJ-vxXC)

Watch the demo on YouTube [here](https://youtu.be/fayXKmGm4Ek?si=QLX--hcnvoJ-vxXC).


#### Check out the project on Stardance! https://stardance.hackclub.com/projects/1942


## Description
The Apollo 15 Lunar Rover Model is a robot controlled by Bluetooth designed to look as similar as possible to the actual lunar roving vehicle used by Commander David Scott and Lunar Module Pilot James Irwin during the Apollo 15 mission. It can be driven using Bluetooth or set to navigate on its own using two ultrasonic sensors and two IR sensors. The ultrasonic sensors detect obstacles in the path of the rover as it moves forward and the IR sensors are used to check which direction is clear to turn backwards when the rover encounters an obstacle. It also has two LED headlights which can be turned on and off using bluetooth or set to turn themselves on and off depending on the light level detected by a photoresistor. The rover is powered by two 9v batteries: one to power the Arduino, HC-05 module and other components through a 9v-5v buck converter and one to provide power to the motors.


At the moment, the model doesn't look very similar to the actual roving vehicle. This is because the current version of the robot is a prototype built with cardboard to test the code and capabilities of the sensors. Version 0 is being shipped simply to show the process of creating the eventual version 1, which will feature a 3D printed chassis, an improved control app, and will resemble the actual rover much more. The rover is not very sturdy and is intended to be used as an educational tool or to be driven inside.

## Inspiration 
After watching NASA's contract award livestream and seeing some cool designs for future lunar rovers, I was inspired to make a robot modeled after the Apollo 15 Lunar Roving Vehicle. While the current version admittedly looks nothing like the actual rover, I am working on designing a 3d-printable chassis and accessories to pay tribute to the only lunar rover used during the Apollo missions.

<img width="1534" height="1143" alt="The actual lunar roving vehicle" src="https://github.com/user-attachments/assets/0b2765d5-6ba3-4b8b-8559-54c67cd2f7a8" />

## Getting started
To get started with the current version of the Lunar Rover Model, you will first need to build the cardboard chassis. For instructions on building and wiring the rover, check out [this guide](Construction/building_the_chassis.md).


Once the chassis is built and the components are wired, it is time to flash the firmware to the Arduino. If you want your rover to simply drive itself around with no help from a driver, copy the code from lunar-rover-obstacle-detectv0.4.ino and paste it in the Arduino IDE. You can also download the file, place it in a folder named [lunar-rover-obstacle-detectv0.4](Firmware/lunar-rover-obstacle-detectv0.4.ino) and open it in the IDE. If you want the rover to be able to be driven or to be set to self-navigation, copy the code from [lunar-rover-completev0.2.ino](Firmware/lunar-rover-completev0.2.ino) and paste it in the Arduino IDE. Before flashing the code to the Arduino, you MUST disconnect the Bluetooth module from the Arduino. This is because if you don't, the Arduino will prioritize its serial communication with the Bluetooth module over the USB connection and you will get an error message.


To control the rover with Bluetooth, you will have to install a controller app on your device. I have used this one with great results: https://play.google.com/store/apps/details?id=com.tools.ArduinoBluetooth on Android. You will also need to make the buttons in the app send the correct code to the Arduino. The serial codes are as follows:

Forward = w

Backwards = s

Left = a

Right = d

Left backwards = z

Right backwards = c

Stop = x

Auto drive on = r

Auto drive off = e

Lights on = f

Lights off = g

Lights auto = h

Your configuration will probably look something like this:

![Screenshot of app layout](Images/app-layout.png)

After configuring the buttons in the app, you will be able to control the rover with your mobile device. If you use an iOs device, you may have to do some troubleshooting to find an app that works well. I was planning to make a custom app for the rover, but I don't know much about it and I wanted to focus on the rover itself. If anyone would like to make an app for this project, they are welcome to and I would appreciate if they let me know.

## Troubleshooting


If you are having issues with the motors, check that you have connected GND on the motor driver board to the ground rail on the breadboard as well as the ground of the battery.


If the rover is moving backwards randomly when when self-navigation is enabled, adjust the angle of the ultrasonic sensors. If they are tilted down they will pick up the floor as an obstacle.


If you are having trouble reconnecting the HC-05 to your phone, try making your phone "forget" the device and pair it again. You may be asked to enter a PIN to connect to the module. The code is usually 1234 or 0000.


If you encounter other problems, feel free to send a question to fish.in.a.puddle42@gmail.com. I'll see if I can help.

## Bill of Materials
|ITEM NAME                |QTY |PRICE (CAD) |PRICE (USD) |LINK                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |NOTES                                                           |
|-------------------------|----|------------|------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
|ELEGOO Arduino Nano      | x1 | $33        | $23.68     | https://www.amazon.ca/ELEGOO-Pre-soldered-ATmega-Compatible-Arduino/dp/B0D5LYFRQP/ref=sr_1_2_sspa?crid=LIVPRKVWZCKQ&dib=eyJ2IjoiMSJ9.qW4RO0YuJFsryiqLau30b8iy0VjwYg3V2vo3YS6uOn7WJ8sSMLAfq_7IkWQYdqdMzxfvCoq1rMRcL2UhhCXvxHveyYgSeLXcbdQb8Msbv6yuFr45plaCz56dHY0PYblBPLJsRjYbfsTAoS-NvVViaDFwgOw2nLcTIMr449pRV6j8GtC-oo2UbDp-dY5TqdG-H4TpnR_Ed-t8o7oH_3gaM1thOCSsumGpLIwd4eaE8LtaHqNF9QTPYCbKfaLCZINiMH_qhUR49GD0lcVYPVMvhWt411WviXpzpaeMbomd7BU.viSK_MhWbk9DFlIYSQGf6IQ2xV7ghxzGQY39kBAu79I&dib_tag=se&keywords=arduino+nano&qid=1786391222&sprefix=arduino+nano%2Caps%2C222&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1                                                                      | The Arduino board used for the rover (Comes in a pack of three)|
|DC Hobby Motors          | x4 | $6.59      | $4.70      | https://www.aliexpress.com/item/1005007259961932.html?spm=a2g0o.productlist.main.15.20ea32286JIPSi&algo_pvid=8a712bff-3023-42ad-8172-65b6e4b477a8&algo_exp_id=8a712bff-3023-42ad-8172-65b6e4b477a8-14&pdp_ext_f=%7B%22order%22%3A%22471%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%216.59%216.58%21%21%2131.29%2131.24%21%4021030cd817869988321333183e0cdc%2112000039978466952%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895%3BpisId%3A5000000211455027&curPageLogUid=3GHzVCjkyNWu&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007259961932%7C_p_origin_prod%3A|                                                                |
|L298N Motor Driver       | x1 | $2.15      | $1.15      | https://www.aliexpress.com/item/1005012608321443.html?spm=a2g0o.productlist.main.2.3dc22000FvqBiT&algo_pvid=e3e82d1d-2444-40da-b42d-ea9c00b3970b&algo_exp_id=e3e82d1d-2444-40da-b42d-ea9c00b3970b-1&pdp_ext_f=%7B%22order%22%3A%228%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%212.15%211.96%21%21%2110.23%219.31%21%402103081117869990306876985e0ea9%2112000058857908264%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895&curPageLogUid=qde4YQvOVEFc&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012608321443%7C_p_origin_prod%3A                                |                                                                |
|HC-05 Bluetooth module   | x1 | $6.90      | $5         | https://www.universal-solder.ca/product/hc-05-bluetooth-module-master-slave/?wmc-currency=CAD                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        | The bluetooth module used for the rover                        |
|9v to 5v buck converter  | x1 | $4.84      | $3.49      | https://www.aliexpress.com/item/1005010708910916.html?spm=a2g0o.productlist.main.49.4683411bJQB49T&algo_pvid=175dc0da-0232-4635-b7f3-90d06269db97&algo_exp_id=175dc0da-0232-4635-b7f3-90d06269db97-48&pdp_ext_f=%7B%22order%22%3A%22895%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%2110.83%214.84%21%21%2151.46%2122.99%21%40210327ef17869991892651378e0d32%2112000053260959705%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895%3BpisId%3A5000000215431818&curPageLogUid=JJSdtcwAG0Vo&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010708910916%7C_p_origin_prod%3A                                   |                                                                |
|Ultrasonic sensor        | x2 | $4         | $2.88      | https://www.universal-solder.ca/product/hc-sr04-ultrasonic-distance-sensor-module-2cm-400cm-range/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | Buy two                                                        |
|IR sensor                | x2 | $1.12      | $0.81      | https://www.aliexpress.com/item/1005009143740555.html?spm=a2g0o.productlist.main.19.532f75593oOqoK&algo_pvid=b7026362-3640-4e1c-b08b-ffc28dc27210&algo_exp_id=b7026362-3640-4e1c-b08b-ffc28dc27210-18&pdp_ext_f=%7B%22order%22%3A%22302%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%211.12%210.95%21%21%210.79%210.67%21%402101de2517869992975282361e0c59%2112000059729027802%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895&curPageLogUid=lEQn0PeL5ev5&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005009143740555%7C_p_origin_prod%3A                                                                 | Buy two                                                        |
|220 Ω resistor           | x1 | $4.27      | $3.08      | https://www.aliexpress.com/item/1005011767578775.html?spm=a2g0o.productlist.main.2.51d9txO1txO1YJ&algo_pvid=d6179486-a371-4a0c-b9d6-2bcd54cdbd8a&algo_exp_id=d6179486-a371-4a0c-b9d6-2bcd54cdbd8a-1&pdp_ext_f=%7B%22order%22%3A%221468%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%214.27%211.40%21%21%2120.29%216.63%21%40210328c017869994159455516e0fe8%2112000056498243073%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895%3BpisId%3A5000000210902393&curPageLogUid=LDdDC600lY9L&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005011767578775%7C_p_origin_prod%3A                                      | Pack of 20                                                     |
|Photoresistor            | x1 | $1.61      | $1.16      | https://www.amazon.ca/dp/B09ZTQL935/ref=sspa_dk_detail_2?psc=1&pd_rd_i=B09ZTQL935&pd_rd_w=LNRKE&content-id=amzn1.sym.74d8946d-6fd5-4629-bffd-b0df65e80145&pf_rd_p=74d8946d-6fd5-4629-bffd-b0df65e80145&pf_rd_r=EF9Z2CE755N2EH8KH4T9&pd_rd_wg=PDUkh&pd_rd_r=8bdfeb4e-f817-4e1e-9683-fd0c72104751&sp_csd=d2lkZ2V0TmFtZT1zcF9kZXRhaWw                                                                                                                                                                                                                                                                                                                                                                   | Pack of 20                                                     |
|Yellow LED               | x2 | $4         | $2.88      | https://www.universal-solder.ca/product/100-x-led-yellow-3mm-round-tinted-clear-standard-package-t-1/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                | Pack of 100                                                    |
|Micro Servo Motor        | x1 | $8.49      | $6.12      | https://www.aliexpress.com/item/1005010200002677.html?spm=a2g0o.productlist.main.47.9e721d2fXGlZIF&algo_pvid=47b943a4-c905-484a-b70c-fa416fcdf74e&algo_exp_id=47b943a4-c905-484a-b70c-fa416fcdf74e-44&pdp_ext_f=%7B%22order%22%3A%2219%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%214.79%214.79%21%21%2122.76%2122.76%21%4021033b3317869995782337036e103a%2112000051507994709%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895&curPageLogUid=Q6LZJYQiWAFX&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010200002677%7C_p_origin_prod%3A                                                                |                                                                |
|Rechargeable 9v batteries| x2 | $3.48      | $2.51      | https://www.aliexpress.com/item/1005007104927891.html?spm=a2g0o.productlist.main.13.4b5e9622CGyQX9&algo_pvid=7e1d28a0-f33b-41e2-8120-be7d0d961a79&algo_exp_id=7e1d28a0-f33b-41e2-8120-be7d0d961a79-12&pdp_ext_f=%7B%22order%22%3A%22281%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%213.48%213.47%21%21%2116.53%2116.48%21%402103117b17869997172547248e0cf7%2112000039419765469%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ac4e1993a%3Bm03_new_user%3A-29895%3BpisId%3A5000000211455027&curPageLogUid=n3Ls8NBlcGkf&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007104927891%7C_p_origin_prod%3A                                    | Pack of 10                                                     |
|9v battery connectors    | x2 | $3         | $2.16      | https://www.amazon.ca/Battery-Connector-Leather-Housing-Connection/dp/B0DHY6VX3L/ref=sr_1_31?crid=297O2U9Q8E33B&dib=eyJ2IjoiMSJ9.B6Y5pJopWcZX4GvTMD7hodi-oxhgIbo_6Lngoj75REp0WBZg2VA3BLkSELMTjh7GjXfETQPmUTPY04lsCGPL9za9RBlNVJg8cKg43A7x6Bdc5appVyfWLr_Up25egcf-_ZLVMP_tadA_0JHrjyWTc63lifP35Ok2HsDQCA7-UktO4UaOZGDGF9k8YMPlmT2P9WYb9g9gErRKpP6g1c68HOKRoLKSeaLOeez46doK2zFtKtLs8t293qJ0Z_AnKz5ufPxEDLQxITKRgKEUz3BCHE32zo9hUd0pkF2h8J10xNw.eTYZC-tMGUBB0K9_JwkK8lAT43D3QZzalz8fCfgQ5dQ&dib_tag=se&keywords=9v+battery+connector+with+switch&qid=1786722157&sprefix=9v+battery+connector+with+switch%2Caps%2C126&sr=8-31                                                                            | Pack of 10                                                     |
|On/Off rocker switch     | x2 | $2         | $1.45      | https://www.amazon.ca/Boat-Rocker-Switch-5Pcs-Position/dp/B0DCNQHKDB/ref=sr_1_4?crid=3HZKVFZZ3PZ9S&dib=eyJ2IjoiMSJ9.G9rSX0vxm4Ddn62THDMAvPl4BnpdZvVdr-yZND7PnJZs1KgeHDuff9sepDyQsPe6nrpFWWQb_3qoYJcaPAnpOB3nt8tA1JRmkpaG2TZZRdsqRJqa4Qlsqnu3MtLgWUNeYlno7DRgZ_Xbm09S_YGY597BRpu_9BVw111uCSO31Fy6Me5rQjrwlZr-s_uOXmLh2XpOfkXDKp59P2epKAeG4agXW6W4SfvWYX_wzdtZbF4pbspbLXFvGk4XlsdAXk2E6e5ipT8_CFDiBwJ4aKxzSx643B-viD3t4L71uYHLfrw.j11K6sOHAKBTlewZX_77d4IU1IYegQkk9ybC6z5KiYI&dib_tag=se&keywords=on+off+switch&qid=1786722338&sprefix=on+off%2Caps%2C138&sr=8-4                                                                                                                                       | Pack of 5                                                      |

## Credits


Original wheel models: https://www.thingiverse.com/thing:5636299









