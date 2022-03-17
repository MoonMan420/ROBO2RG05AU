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

void RightTurn(){
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 500, mm);
}
void LeftTurn(){
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 500, mm);
}

int circuitCallback(){
  Drivetrain.setDriveVelocity(50, rpm);
  Drivetrain.setTurnVelocity(50, rpm);
  Drivetrain.driveFor(forward, 500, mm);
  RightTurn();
  LeftTurn();
  LeftTurn();
  RightTurn();
  RightTurn();
  LeftTurn();
  RightTurn();
  RightTurn();
  LeftTurn();
  RightTurn();
  RightTurn();
  LeftTurn();
  LeftTurn();
  RightTurn();
  return 0;
};

int stopperCallback() {
  while(!StopButton) {
    return 0;
  };
  return 1;
}


int main() {
  vexcodeInit();
  task circuit = task(circuitCallback);
  task stopper = task(stopperCallback);

  while(stopperCallback() != 1) {
    vex::task::resume(circuit);
  };
  vex::task::suspend(circuit);
};
