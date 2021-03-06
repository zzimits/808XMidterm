/**
 * @file Controller.hpp
 * @author Niket Shah Zachary Zimits
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of a controller for a tricycle
 *        where it can enable the vehicle to make a turn
 *        at a specified orientation and run at a specified
 *        velocity
 *
 */
#include <iostream>
#include <math.h>
#include "Vehicle.hpp"
#include "Controller.hpp"

int main() {
  double steeringAngleConstraint = 45;
  double wheelDiameter = 2;
  double trackWidth = 4;
  double wheelBase = 4;
  double desiredOrientation;
  double desiredVelocity;
  Vehicle tricycle(wheelDiameter, steeringAngleConstraint, trackWidth,
                   wheelBase);
  std::cout << "Please enter the desired orientation (0 to 360 degrees): "
            << std::endl;
  std::cin >> desiredOrientation;
  std::cout << "Please enter the desired velocity: ";
  std::cin >> desiredVelocity;
  tricycle.setVelocity(desiredVelocity);
  tricycle.setOrientation(desiredOrientation);
  while (fabs(tricycle.getOrientation() - desiredOrientation) > 1
      || fabs(tricycle.getVelocity() - desiredVelocity) > .5) {
    tricycle.update();
    std::cout << "Current Orientation: " << tricycle.getOrientation()
              << " Current Velocity: " << tricycle.getVelocity() << "\n";
    }


 std::cout << "You have achieved your desired orientation and velocity!"
            << std::endl;
  return 0;
}
