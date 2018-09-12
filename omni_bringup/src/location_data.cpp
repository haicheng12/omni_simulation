// Signal handling
#include <signal.h>

#include "amcl/map/map.h"
#include "amcl/pf/pf.h"
#include "amcl/sensors/amcl_odom.h"
#include "amcl/sensors/amcl_laser.h"

#include "ros/assert.h"

// roscpp
#include "ros/ros.h"

// Messages that I need
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"
#include "nav_msgs/GetMap.h"
#include "nav_msgs/SetMap.h"
#include "std_srvs/Empty.h"

// For transform support
#include "tf/transform_broadcaster.h"
#include "tf/transform_listener.h"
#include "tf/message_filter.h"
#include "tf/tf.h"
#include "message_filters/subscriber.h"

// Dynamic_reconfigure
#include "dynamic_reconfigure/server.h"
#include "amcl/AMCLConfig.h"

// Allows AMCL to run from bag file
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <boost/foreach.hpp>

void poseMessageReceived(const geometry_msgs::PoseWithCovarianceStamped& msg )//回调函数，输出位置信息
{
//   ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=("<< msg.x <<","<< msg.y <<")" <<" *direction="<<msg.theta);
   ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=  ("<< msg.pose.pose.position.x<<","<< msg.pose.pose.position.y <<")" <<" *direction="<< msg.pose.pose.orientation.w);
}

int main(int argv,char** argc)
{
    ros::init(argv,argc,"listener_pose");//定义一个主题来订阅
    ros::NodeHandle node_Handle;//定义一个节点
    ros::Subscriber sub = node_Handle.subscribe("/amcl_pose",100,&poseMessageReceived);//订阅到的节点

    ros::spin();//回旋

    return 0;
}
