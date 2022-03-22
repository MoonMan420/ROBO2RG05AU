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
// MotorArm             motor         19              
// MotorClaw            motor         20              
// RangeFinderG         sonar         G, H            
// BumperA              bumper        A               
// LightB               light         B               
// Vision10             vision        10              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

void avoider(){

}

void userThread(){
  while(true){
    if(LightB.brightness() < 30){
      Drivetrain.stop(hold);
    }else{
      Drivetrain.driveFor(200, mm);
      if(RangeFinderG.distance(mm) < 500){
        Drivetrain.turnFor(90, degrees);
      }
    }
  }
}



int main()
{
    vex::thread ut(userThread);

    while(1)
    {
      if( BumperA || Controller1.ButtonA.pressing())
      {
            ut.interrupt();  // stop user thread
            return 0;
      }
      }
      this_thread::sleep_for( 10 );
}