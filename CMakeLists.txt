cmake_minimum_required(VERSION 2.8.3)
project(uavv)




find_package(catkin REQUIRED
 cmake_modules
 roscpp
 rospy
 std_msgs
 geometry_msgs
 dynamic_reconfigure
 message_generation
)

find_package(Eigen REQUIRED)


 generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
 )

catkin_package(
   CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime
)


include_directories(include
${catkin_INCLUDE_DIRS}
${Eigen_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(snow
   src/snowy.cpp
)

##
add_executable(code1 src/position_control.cpp)
add_dependencies(code1 uavv_messages_cpp)
#target_link_libraries(code1 ${catkin_LIBRARIES})

## Specify libraries to link a library or executable target against
target_link_libraries(code1 snow
   ${catkin_LIBRARIES}
 )
