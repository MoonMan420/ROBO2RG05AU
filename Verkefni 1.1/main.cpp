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

int main() {
  // Búa til breytuna distance
  int distance = 500;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // While loop til að fara í gegnum aðgerðirnar aftur og aftur með nýju vegalengdunum
  while (distance < 2501) {
    // keyra fram og aftur um vegalengdina distance
    Drivetrain.driveFor(forward, distance, mm);
    Drivetrain.driveFor(reverse, distance, mm);
    // bæta 500 á breytuna distance til þess að lengja vegalengdina um hálfan meter í hverjum loop
    distance += 500;
  }
}