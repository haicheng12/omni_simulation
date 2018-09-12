#include <ros/ros.h>//ROS头文件
#include <move_base_msgs/MoveBaseAction.h>//move_base头文件
#include <actionlib/client/simple_action_client.h>//actionlib头文件
#include <tf/transform_broadcaster.h>//tf头文件
#include <sstream>//C++头文件

ros::Time current_time, last_time;                //定义现在时间，之前的时间

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;//声明发送目标的结构体

int main(int argc, char** argv)
{
    ros::init(argc, argv, "navigation_goals");//定义一个主题

    MoveBaseClient ac("move_base", true);//开启move_base包

    while(!ac.waitForServer(ros::Duration(5.0)))//等待5秒
    {
        ROS_INFO("Waiting for the move_base action server");
    }

    int count=0;
    while(1)
    {
        move_base_msgs::MoveBaseGoal goal1;//目标1消息头文件

        goal1.target_pose.header.frame_id = "map";
        goal1.target_pose.header.stamp = ros::Time::now();//更新时间

        goal1.target_pose.pose.position.x = 3.0;       //目标点1的x坐标的位置
        goal1.target_pose.pose.position.y = 3.0;       //目标点1的y坐标的位置
        goal1.target_pose.pose.orientation.w = 1.0; //目标点1的角度的位置

        ROS_INFO("Sending goal 1");//打印输出信息
        ac.sendGoal(goal1);//发送目标1
        ac.waitForResult();//等待结果

        move_base_msgs::MoveBaseGoal goal2;//目标2消息头文件

        goal2.target_pose.header.frame_id = "map";
        goal2.target_pose.header.stamp = ros::Time::now();//更新时间

        goal2.target_pose.pose.position.x = -5.0;       //目标点2的x坐标的位置
        goal2.target_pose.pose.position.y = -1.7;       //目标点2的y坐标的位置
        goal2.target_pose.pose.orientation.w = 1.0; //目标点2的角度的位置

        ROS_INFO("Sending goal 2");//打印输出信息
        ac.sendGoal(goal2);//发送目标2
        ac.waitForResult();//等待结果

        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)//如果成功到达目标点，输出成功信息
            ROS_INFO("You have arrived to the goal 1 and goal 2 position");
        else//否则输出失败信息
        {
            ROS_INFO("The base failed for some reason");
        }
        count++;
        ROS_INFO("times: %d",count);
    }

    return 0;
}
