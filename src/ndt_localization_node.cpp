/**
* @file ndt_localization_node.cpp
* @brief ndt_localization node
* @author Shunya Hara
* @date 2022.8.8
* @details 
*/

#include <ros/ros.h>

#include <iostream>
#include <string>


int main(int argc, char **argv){
    
    ros::init(argc, argv, "ndt_localization_node");
    ros::NodeHandle n;
    

    //param setting
    ros::NodeHandle pn("~");
    double looprate=pn.param("looprate",10.0);
    std::string map__id=pn.param("map_id",std::string("map"));
    std::string base_link_id=pn.param("base_link_id",std::string("base_link"));

    ros::Rate loop_rate(looprate);

    //subscliber
    ros::Subscriber map_sub = n.subscribe("global_map", 1, map_callback);
    ros::Subscriber lidar_sub = n.subscribe("velodyne_points", 1, lidar_callback);
    ros::Subscriber initialpose_sub = n.subscribe("initialpose", 10, initialpose_callback);

    //publisher
    

    while (n.ok())  {
        
        ros::spinOnce();//subsucriberの割り込み関数はこの段階で実装される
        loop_rate.sleep();
        
    }
    
    return 0;
}