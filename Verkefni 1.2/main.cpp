/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Isak Mani                                        */
/*    Created:      Tue Mar 15 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

void right_turn(){
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 500, mm);
}
void left_turn(){

  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 500, mm);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // turns the robot right 90 degrees
  Drivetrain.setDriveVelocity(50, rpm);
  Drivetrain.setTurnVelocity(50, rpm);
  Drivetrain.driveFor(forward, 500, mm);
  right_turn();
  left_turn();
  left_turn();
  right_turn();
  right_turn();
  left_turn();
  right_turn();
  right_turn();
  left_turn();
  right_turn();
  right_turn();
  left_turn();
  left_turn();
  right_turn();
}