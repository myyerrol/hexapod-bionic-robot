# hexapod_bionic_robot

![hexapod_bionic_robot](.images/hexapod_bionic_robot_1.jpg)

## Description

This code repository contains the Arduino embedded codes for hexapod bionic robot. It uses Arduino and multiple sensors to complete the robot's walking, obstacle avoidance, remote control and other functions.

## Principle

![hexapod_bionic_robot_fritzing](.images/hexapod_bionic_robot_fritzing.png)

## Video

The following video show the basic function of the [hexapod_bionic_robot](https://v.youku.com/v_show/id_XMzY1MTU4OTczNg==.html?spm=a2hzp.8244740.0.0).

## Configure

1. Please connect lines correctly.
2. Doanload repository to local computer:

  ```sh
  $> cd Desktop
  $> git clone https://github.com/myyerrol/hexapod_bionic_robot.git
  ```

3. Copy `arduino/HexapodBionicRobot/` directory to `Arduino/libraries/`:

  ```sh
  $> cd ~/Desktop/hexapod_bionic_robot
  $> cp -r arduino/HexapodBionicRobot/ ~/Arduino/libraries/
  ```

4. Start **Arduino IDE**, select `File/Examples/HexapodBionicRobot/hexapod_bionic_robot_test`.

5. Compile code and upload to arduino.

## Summary
