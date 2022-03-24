/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  Detecting Distances                                       */
/*                  This program will use the Range Finder to stop a robot    */
/*                  300 mm away from a wall.                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    3, 4            
// BumperA              bumper        A               
// Controller1          controller                    
// LineTrackerC         line          C               
// LineTrackerD         line          D               
// LineTrackerE         line          E               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
float LTLeft = 0;
float LTCenter = 0;
float LTRight = 0;
float threshold = 30;

float LTLeftOld = 0;
float LTCenterOld = 0;
float LTRightOld = 0;


/*
void userThread(){
  while(true){
    LTLeft = LineTrackerC.reflectivity();
    LTCenter = LineTrackerD.reflectivity();
    LTRight = LineTrackerE.reflectivity();
    Drivetrain.setDriveVelocity(50, rpm);

    if(LTLeft < 30 and LTCenter < 30 and LTRight < 30){
      Drivetrain.drive(forward);
      Drivetrain.stop();
    } else if(LTLeft < 30 and LTCenter < 30 and  LTRight > 30){
      Drivetrain.turn(right);
      Drivetrain.stop();
    } else if(LTLeft > 30 and LTCenter < 30 and LTRight < 30){
      Drivetrain.turn(left);
      Drivetrain.stop();    
    } else if(LTLeft < 30 and LTCenter > 30 and  LTRight > 30){
      Drivetrain.turn(right);
      Drivetrain.stop();
    } else if(LTLeft > 30 and LTCenter > 30 and  LTRight < 30){
      Drivetrain.turn(left);
      Drivetrain.stop();
    } else {
      while(LTLeft > 30 and LTCenter > 30 and  LTRight > 30){
        Drivetrain.turnFor(right, 360, degrees);
        Drivetrain.stop();
        Drivetrain.driveFor(forward, 100, mm);
        Drivetrain.stop();
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
*/
int main(){
  vexcodeInit();
    Drivetrain.setDriveVelocity(15, rpm);
    Drivetrain.setTurnVelocity(15, rpm);
    Drivetrain.driveFor(forward, 100, mm);
    while(true){
      LTLeft = LineTrackerC.reflectivity();
      LTCenter = LineTrackerD.reflectivity();
      LTRight = LineTrackerE.reflectivity();
      Drivetrain.setDriveVelocity(15, rpm);
      Drivetrain.setTurnVelocity(15, rpm);

      if(LTLeft < threshold and LTCenter < threshold and LTRight < threshold){
        Drivetrain.drive(forward);
      }
      if(LTLeft < threshold and LTCenter < threshold and LTRight > threshold){
          Drivetrain.turn(left);
          Drivetrain.drive(forward);
      }
      if(LTLeft > threshold and LTCenter < threshold and LTRight < threshold){
          Drivetrain.turn(right);
          Drivetrain.drive(forward);
      }
      if(LTLeft < threshold and LTCenter > threshold and LTRight > threshold){
          Drivetrain.setTurnVelocity(20, rpm);
          Drivetrain.setDriveVelocity(10, rpm);          
          Drivetrain.turn(left);
          Drivetrain.drive(forward);
      }
      if(LTLeft > threshold and LTCenter > threshold and LTRight < threshold){
          Drivetrain.setTurnVelocity(20, rpm);
          Drivetrain.setDriveVelocity(10, rpm);
          Drivetrain.turn(right);
          Drivetrain.drive(forward);
      }
      if(LTLeft > threshold and LTCenter > threshold and LTRight > threshold){
        Drivetrain.drive(forward);
      }


      /*else {
        Brain.Screen.print("fuck");
        wait(50, msec);
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.clearScreen();
        wait(5, msec);
        }*/
    }
  }
