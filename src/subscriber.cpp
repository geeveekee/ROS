#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <sstream>

//topis : turtle1/pose


// float32 x
// float32 y
// float32 theta
// float32 linear_velocity
// float32 angular_velocity

void poseCallBack(const turtlesim::Pose::ConstPtr& msg)
{
	ROS_INFO("Position of the turtle \nx:[%f]\n y:[%f]", msg->x, msg->y);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turtle_pos");
	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe<turtlesim::Pose>("turtle1/pose", 1000, poseCallBack);
	ros::spin();

	return 0;
}
