
//#include <cstdlib>  //c standard library 
#include <stdlib.h>     /* atoi */

//#include "ros/ros.h"
#include "std_msgs/String.h"
//#include "geometry_msgs/PoseStamped.h"
#include <sstream>
#include <Eigen/Eigen>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

#include "snowy.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "uav_position_controller");
    ros::NodeHandle n;
//    n= Snowy::nh;
    ros::Publisher uavPosePublisher = n.advertise<geometry_msgs::PoseStamped>("/mavros/setpoint_position/local", 1000);
    //above line: 10 was 1000 previously
    
    //ros::Rate loop_rate(50);
    ros::Rate loop_rate(100);

    geometry_msgs::PoseStamped newPose;
    geometry_msgs::PoseStamped newPose2;
    
    double x = 0.5;
    double y = 0.5;
    double z = 4.0;
    
    /*
    double xx = atof(argv[1]);
    double yy = atof(argv[2]);
    double zz = atof(argv[3]);
    ROS_INFO("\n x= %f \n y= %f \n z= %f", xx, yy, zz);
    */
    
    Snowy X;
    ROS_INFO("Starting takeoff");
    X.takeoff(argc, argv);
    ROS_INFO("takeoff done");

    double Xs[4]={0,-2,2,0};
    double Ys[4]={-2,0,2,0};
    
    //newPose.pose.position.x  = xx;
    //newPose.pose.position.y  = yy;
    newPose.pose.position.z  = 3;//zz;
    newPose.header.stamp=ros::Time::now();
    newPose.header.frame_id="world";
    tf::Quaternion quaternion = tf::createQuaternionFromRPY(0,0,0);
    newPose.pose.orientation.w = quaternion.w();
    newPose.pose.orientation.x = quaternion.x();
    newPose.pose.orientation.y = quaternion.y();
    newPose.pose.orientation.z = quaternion.z();
    newPose2=newPose;
    
    //    ROS_INFO("Stage 1/6");

    
    //    ROS_INFO("Stage 2/6");
    //    sleep(10);

    /*
    newPose.pose.position.x  = xx+0.5;
    newPose.pose.position.y  = yy;
    uavPosePublisher.publish(newPose);
    
    newPose.pose.position.x  = xx+0.5;
    newPose.pose.position.y  = yy;
    uavPosePublisher.publish(newPose);
    
    newPose.pose.position.x  = xx+0.5;
    newPose.pose.position.y  = yy;
    uavPosePublisher.publish(newPose);
 */
    
    for(int wp=0 ;wp<4 ;wp++)
    {
        ROS_INFO("Going to point Num.%d",wp+1);
        newPose.pose.position.x  = Xs[wp];
        newPose.pose.position.y  = Ys[wp];
        //newPose.header.stamp=ros::Time::now();
        
    for(int i=0; i<5; i++)
    //while (!X.arrived(newPose))
    {
        
        uavPosePublisher.publish(newPose);
        ros::spinOnce();
        loop_rate.sleep();
    }
    sleep(7);
    ROS_INFO("P%d arrived",wp+1);
    sleep(3);
    }

    return 0;
    
    while (ros::ok())
    {
    //ROS_INFO("Stage 4/6");

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
