cmake_minimum_required(VERSION 3.0.2)
project(turtle_control)


## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES turtle_control
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(text_command src/text_command.cpp)
target_link_libraries(text_command ${catkin_LIBRARIES})
add_dependencies(text_command turtle_control_generate_messages_cpp)

add_executable(text_to_cmd_vel src/text_to_cmd_vel.cpp)
target_link_libraries(text_to_cmd_vel ${catkin_LIBRARIES})
add_dependencies(text_to_cmd_vel turtle_control_generate_messages_cpp)
