#ifndef SNOWY_H
#define SNOWY_H

#include <cstdlib>
#include <iostream>

#include <ros/ros.h>
#include "geometry_msgs/PoseStamped.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/CommandTOL.h>
#include <mavros_msgs/SetMode.h>

//ros::init(argc, argv, "uav_position_controller");
//ros::NodeHandle noo;


class Snowy
{
private:

public:

    void snowyy( );
    void land();
    void takeoff(int argc, char **argv);
    //int arrived(geometry_msgs::PoseStamped P);
};

#endif // SNOWY_H
