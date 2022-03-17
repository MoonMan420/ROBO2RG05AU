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
// Controller1          controller                    
// MotorClaw            motor         19              
// MotorArm             motor         20              
// StopButton           bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  if (!Controller1.ButtonUp.pressing() or !Controller1.ButtonDown.pressing()) {
    MotorArm.stop(hold);
  };
  if (!Controller1.ButtonX.pressing() or !Controller1.ButtonA.pressing()) {
    MotorClaw.stop(hold);
  };
}