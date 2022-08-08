cmake_minimum_required(VERSION 3.0.2)
project(ndt_localization)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  pcl_ros
  roscpp
  rospy
  std_msgs
  tf
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ndt_localization
  CATKIN_DEPENDS pcl_ros roscpp rospy std_msgs tf
  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ndt_localization_node src/ndt_localization_node.cpp)
target_link_libraries(ndt_localization_node ${catkin_LIBRARIES})