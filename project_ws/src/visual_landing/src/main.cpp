#include"my_handle_function.h"



 

//定义一个转换的类
class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;//定义ROS图像接收器
 // image_transport::Publisher image_pub_;

public:
  ImageConverter()
    : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/stereo_camera/left/image_rect_color", 1,//改这，修改订阅的ros话题
      &ImageConverter::imageCb, this);
   // image_pub_ = it_.advertise("/image_converter/output_video", 1);//发布的ros话题

  
  }

  ~ImageConverter()
  { }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)//回调函数，当收到图像后跳入到回调函数
  {                                                                                                             //然后在该函数内将图像进行转换
    cv_bridge::CvImagePtr cv_ptr;                       
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);//这句话就是完成转换，并传回指针
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
     //得到的原始图像：cv_ptr->image;
        Mat img=cv_ptr->image;

     //下面写对图像的处理
        getContours(img);






   

    

    // Output modified video stream
    //image_pub_.publish(cv_ptr->toImageMsg());
  }
};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_converter");
  ImageConverter ic;
  ros::spin();
  return 0;
}