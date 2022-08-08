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
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
    
    ros::init(argc, argv, "ndt_localization_node");
    ros::NodeHandle n;
    //制御周期10Hz
    ros::Rate loop_rate(10);

    //param setting
    ros::NodeHandle pn("~");

    while (n.ok())  {
        
        ros::spinOnce();//subsucriberの割り込み関数はこの段階で実装される
        loop_rate.sleep();
        
    }
    
    return 0;
}