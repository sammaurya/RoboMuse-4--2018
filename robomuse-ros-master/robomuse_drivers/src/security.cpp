#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


void my_handler (int s)
{
 //system("gnome-terminal");
 system("cd ~/ && ./dock.sh");
 while(1);
 exit(1);
}

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
   ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/robomuse/cmd_vel", 1000);
  geometry_msgs::Twist myTwistMsg;
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  struct sigaction sigIntHandler;

  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

  sigaction(SIGINT, &sigIntHandler, NULL);


  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  move_base_msgs::MoveBaseGoal goal;
  geometry_msgs::Point initpose;
  
  //int x1 = initpose.x;
  //while(x1 == initpose.x);

  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  int i=0;
while(1){
  goal.target_pose.pose.position.x = 1.31;
  goal.target_pose.pose.position.y = -8.14;
  goal.target_pose.pose.orientation.z = -0.2;
  goal.target_pose.pose.orientation.w = 1;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 5.9;
  goal.target_pose.pose.position.y = -7.89;
  goal.target_pose.pose.orientation.z = 0.03;
  goal.target_pose.pose.orientation.w = 0.99;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");

goal.target_pose.pose.position.x = 11.46;
  goal.target_pose.pose.position.y = -7.36;
  goal.target_pose.pose.orientation.z = 0.06;
  goal.target_pose.pose.orientation.w = 0.99;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");

  myTwistMsg.linear.x = 0;
  myTwistMsg.linear.y = 0;
  myTwistMsg.linear.z = 0;

  myTwistMsg.angular.x = 0;
  myTwistMsg.angular.y = 0;
  myTwistMsg.angular.z = 0.2;

  ros::Time beginTime = ros::Time::now();
  ros::Duration delay1(31.4);

  while(ros::Time::now() - beginTime <= delay1 )
  {
    pub.publish(myTwistMsg);
    ros::Duration(0.1).sleep();
  }
  goal.target_pose.pose.position.x = 11.46;
  goal.target_pose.pose.position.y = -7.36;
  goal.target_pose.pose.orientation.z = -0.99;
  goal.target_pose.pose.orientation.w = 0.041;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 6.04;
  goal.target_pose.pose.position.y = -7.809;
  goal.target_pose.pose.orientation.z = -0.99;
  goal.target_pose.pose.orientation.w = 0.04;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
  goal.target_pose.pose.position.x = 1.08;
  goal.target_pose.pose.position.y = -7.22;
  goal.target_pose.pose.orientation.z = -0.99;
  goal.target_pose.pose.orientation.w = 0.039;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
    i++;

  goal.target_pose.pose.position.x = -5.27;
  goal.target_pose.pose.position.y = -8.08;
  goal.target_pose.pose.orientation.z = -0.92;
  goal.target_pose.pose.orientation.w = 0.37;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
    i++;

  goal.target_pose.pose.position.x = -8.67;
  goal.target_pose.pose.position.y = -8.31;
  goal.target_pose.pose.orientation.z = -0.99;
  goal.target_pose.pose.orientation.w = 0.14;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");
    
  goal.target_pose.pose.position.x = -10.21;
  goal.target_pose.pose.position.y = -8.31;
  goal.target_pose.pose.orientation.z = -0.99;
  goal.target_pose.pose.orientation.w = 0.001;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");

  goal.target_pose.pose.position.x = -12.03;
  goal.target_pose.pose.position.y = -7.17;
  goal.target_pose.pose.orientation.z = -0.96;
  goal.target_pose.pose.orientation.w = 0.277;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("reached");
  else
    ROS_INFO("not reached");

  i++;
}
  return 0;
}
