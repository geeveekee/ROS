#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <turtlesim/Pose.h>
#include <string.h>

class rosse{
private:
	ros::Publisher pub;
	ros::Subscriber sub;

public:
	
	void poseCallBack(const turtlesim::Pose::ConstPtr& msg)
	{
		ROS_INFO("Position of the turtle \nx:[%f]\n y:[%f]", msg->x, msg->y);
		move_bot();
	}

	void nodeHandler(ros::NodeHandle *nh)
	{
		pub = nh->advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
		sub = nh->subscribe<turtlesim::Pose>("turtle1/pose", 1000, &rosse::poseCallBack, this);
	}

	void move_bot()
	{
		geometry_msgs::Twist msg;
		msg.linear.x = 1;
        //msg.linear.y = 1;
        msg.angular.z = 1;
		pub.publish(msg);
	}
};


int main(int argc, char **argv)
{
	rosse bot;
	ros::init(argc, argv, "turtle_move");
	ros::NodeHandle nh;
	bot.nodeHandler(&nh);
	ros::Rate rate(1);
	ROS_INFO("Moving the turtle");
	while(ros::ok())
	{
		bot.move_bot();
		rate.sleep();
		ros::spin();

	}
}
