#include "vex.h"

#include "driverFunctions.h"

#include "autonFunctions.h"

using namespace vex;

int chassisMovement(){
  while(true) {
    double front_left = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct));
    double back_left = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct));
    double front_right = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct));
    double back_right = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct));

    double max_raw_sum = (double)(abs(Controller1.Axis3.position(pct)) + abs(Controller1.Axis4.position(pct)));

    double max_XYstick_value = (double)(std::max(abs(Controller1.Axis3.position(pct)), abs(Controller1.Axis4.position(pct))));

    if (max_raw_sum != 0) {
      front_left = front_left / max_raw_sum * max_XYstick_value;
      back_left = back_left / max_raw_sum * max_XYstick_value;
      front_right = front_right / max_raw_sum * max_XYstick_value;
      back_right = back_right / max_raw_sum * max_XYstick_value;
    }

      front_left = front_left + Controller1.Axis1.position(pct);
      back_left = back_left + Controller1.Axis1.position(pct);
      front_right = front_right - Controller1.Axis1.position(pct);
      back_right = back_right - Controller1.Axis1.position(pct);

    max_raw_sum = std::max(fabs(front_left), std::max(fabs(back_left), std::max(fabs(front_right), std::max(fabs(back_right), 100.0))));

    front_left = front_left / max_raw_sum * 100.0;
    back_left = back_left / max_raw_sum * 100.0;
    front_right = front_right / max_raw_sum * 100.0;
    back_right = back_right / max_raw_sum * 100.0;

    FL.spin(forward, front_left , velocityUnits::pct);
    FR.spin(forward, front_right , velocityUnits::pct);
    BL.spin(forward, back_left , velocityUnits::pct);
    BR.spin(forward, back_right , velocityUnits::pct);

    task::sleep(10);
  
  }
}
  int conveyorSpin(){
    while(true){
      if(Controller1.ButtonL1.pressing()){

      Conveyor1.spin(fwd,100,pct);
      Conveyor2.spin(fwd,100,pct);
    }

    else if(Controller1.ButtonL2.pressing()){
      Conveyor1.spin(reverse,100,pct);
      Conveyor2.spin(reverse,100,pct);
    }
    else{
      Conveyor1.stop(brakeType::coast);
      Conveyor2.stop(brakeType::coast);
    }
  }
  }
  int rollerSpin(){
   while (true){
    if(Controller1.ButtonR2.pressing()){
      LeftRoller.spin(reverse,100, pct);
      RightRoller.spin(reverse,100, pct);
    }

    else if(Controller1.ButtonR1.pressing()) {
      LeftRoller.spin(fwd,100, pct);
      RightRoller.spin(fwd,100, pct);
    }
      else{
      LeftRoller.stop(brakeType::coast);
      RightRoller.stop(brakeType::coast);
      
      }
  }
  }
   int Brake(){
    while (true){
     if(Controller1.ButtonY.pressing()){
          BL.stop(brake);
          FR.stop(brake);
          BR.stop(brake);
          FL.stop(brake);
     }
     else{
      BL.stop(coast);
      FR.stop(coast);
      BR.stop(coast);
      FL.stop(coast); 
     }
   }
   }
  int Intake (){
   while (true){
    if(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing()){
         LeftRoller.spin(fwd,100, pct);
         RightRoller.spin(fwd,100, pct);
    }
  }
  }