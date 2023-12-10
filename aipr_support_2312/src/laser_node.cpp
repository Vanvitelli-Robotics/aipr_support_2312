#include <ros/ros.h>

#include <std_srvs/SetBool.h>

bool laser_active = false;
bool laser_callback(std_srvs::SetBool::Request &request,
                    std_srvs::SetBool::Response &response)

{

  if (request.data) {
    if (laser_active) {
      response.message = "Laser already active!!!!";
    } else {
      response.message = "Laser Activated";
    }

  } else {
    if (laser_active) {
      response.message = "Laser Deactivated!";
    } else {
      response.message = "Laser already deactivated!!!!";
    }
  }

  laser_active = request.data;

  ROS_WARN_STREAM("[LASER] " << response.message);

  return true;
}

int main(int argc, char *argv[]) {

  ros::init(argc, argv, "laser");

  ros::NodeHandle nh;

  ros::ServiceServer laser_srv = nh.advertiseService("laser_on_off", laser_callback);

  ros::spin();

  return 0;
}
