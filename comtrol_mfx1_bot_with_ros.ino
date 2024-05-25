// to control bot you must run "roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch" and control the robot with keyboard
#define USE_USBCON // decomment this line when you programme arduino due
#include "ros.h"
#include "geometry_msgs/Twist.h"

float linear_vel_x,angular_vel_z; 
int motor_speed = 65;

ros::NodeHandle nh;

#define RPWM_1 4
#define LPWM_1 5

#define RPWM_2 6
#define LPWM_2 7




void velCallback(  const geometry_msgs::Twist& vel)
{
     linear_vel_x = vel.linear.x; //- 1.0; // I CAN USE VEL AS I WANT
     angular_vel_z =vel.angular.z;

     if(linear_vel_x > 0){
      Forward(motor_speed );
     }
     else if(linear_vel_x <0){
      Back(motor_speed );
     }
     else{
      stoppe();
     }
}

void Forward(int Speed){
  //motor forward direction
  analogWrite(RPWM_1, LOW);
  analogWrite(LPWM_1, Speed);  
  digitalWrite(RPWM_2, LOW);
  analogWrite(LPWM_2, Speed);  
}

void Back(int Speed){
  //motor back direction
  analogWrite(RPWM_1, Speed);
  analogWrite(LPWM_1, LOW);  
  analogWrite(RPWM_2, Speed);
  digitalWrite(LPWM_2, LOW);  
}
void stoppe(){
  // Stop motors
analogWrite(RPWM_1, 0);
analogWrite(LPWM_1, 0);
analogWrite(RPWM_2, 0);
analogWrite(LPWM_2, 0);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel" , velCallback);

void setup() {
    // Set motor connections as outputs
  pinMode(RPWM_1, OUTPUT);
  pinMode(LPWM_1, OUTPUT);
  pinMode(RPWM_2, OUTPUT);
  pinMode(LPWM_2, OUTPUT);

  // Stop motors
  analogWrite(RPWM_1, 0);
  analogWrite(LPWM_1, 0);
  analogWrite(RPWM_2, 0);
  analogWrite(LPWM_2, 0);
  stoppe();
  
     nh.initNode();
     nh.subscribe(sub);

}

void loop() {
     nh.spinOnce();
     delay(10);
}
