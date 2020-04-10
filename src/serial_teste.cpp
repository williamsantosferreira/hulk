#include "ros/ros.h" 
#include "std_msgs/String.h" 
#include "serial/serial.h"
#include "string.h"

ros::Subscriber sub; 
ros::Subscriber sub2;
std::string porta_serial = "/dev/ttyACM0";
serial::Serial* pserial;
std_msgs::String leitura;
std::string teste = "p\r";


int main(int argc,char **argv) 

{ 
ros::init(argc, argv,"serial_teste"); 
ros::NodeHandle n; 
	
serial::Serial serial(porta_serial,9600,serial::Timeout::simpleTimeout(1000));

	if(serial.isOpen()){
 	ROS_INFO("Porta Serial aberta!");
	} else {
 	ROS_INFO("Problema ao abrir a porta!");
	return -1;
	}	
	pserial = &serial;

	ros::spin();

return 0; 

} 

