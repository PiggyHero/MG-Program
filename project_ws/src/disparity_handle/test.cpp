#include<ros/ros.h>
#include<iostream>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>
#include<image_transport/image_transport.h>
#include<stereo_msgs/DisparityImage.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


void Callback(const stereo_msgs::DisparityImageConstPtr &msg)
{
        sensor_msgs::Image img_sensor=msg->image;
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(img_sensor,sensor_msgs::image_encodings::BGR8);
        Mat img=cv_ptr->image;
        
        // waitKey(1);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "disparity_handle");
  ros::NodeHandle n;
  ros::Subscriber ic=n.subscribe("/stereo_camera/disparity",10,Callback);
  ros::spin();
  return 0;
}