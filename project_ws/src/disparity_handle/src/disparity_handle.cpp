#include<ros/ros.h>
#include<iostream>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>
#include<image_transport/image_transport.h>
#include<stereo_msgs/DisparityImage.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<math.h>
using namespace std;
using namespace cv;

double s=255.0/12.0;
Mat img;
Mat imgGray;
Mat imgBlur,imgCanny,imgDil;
 int lower=1 ,upper=15;//定义Canny检测的阈值
 int Dil_kernel_size=13;

Mat kernel_Fl_init(int n){
        Mat kernel(Size(n,n),CV_32FC1);
        float *ptr;
        for (int i=0;i<kernel.rows;i++)
        {
                ptr=kernel.ptr<float>(i);
                for(int j=0;j<kernel.cols;j++)
                {
                        if(j==n/2&&i==n/2)
                        {
                                ptr[j]=1-1.0/float(n*n);
                        }
                        else
                        {
                                ptr[j]=-1.0/float(n*n);
                        }
                }
        }
        return kernel;
}

Mat kernel_Fl_init2(int n){//均值卷积核初始化函数
        Mat kernel(Size(n,n),CV_32FC1);
        float *ptr;
        for (int i=0;i<kernel.rows;i++)
        {
                ptr=kernel.ptr<float>(i);
                for(int j=0;j<kernel.cols;j++)
                {
                   ptr[j]=1.0/float(n*n);  
                }
        }
        return kernel;
}



void Callback(const stereo_msgs::DisparityImageConstPtr &msg)
{
        sensor_msgs::Image img_sensor=msg->image;
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(img_sensor);

        /*********************************************上面是从ROS的消息转换******************************/

        /*********************************************下面是图像处理*************************************/
        
        /*——————————————————————图像定义与转换——————————————————*/
        img=(-(100*cv_ptr->image)+1300)/100;//校核深度数据
        //深度数据范围[-n，20]，在这里设置一个饱和函数，将范围映射到[0,12]

        //这写一个饱和函数！！！
        img=min(img,12.0);
        img=max(img,0.0);//img是深度矩阵，其范围为[4,9]

      
        
        //img是CV_32FC1的数据，在这里转化成CV_8UC1的类型，s为缩放系数
        //img的数据元素 ÷ 12.0 * 255 先归一化，再映射到[0,255]

        // img.convertTo(imgGray,CV_8UC1,s);
        
        
        /*—————————————————边缘检测————————————————————*/
        // GaussianBlur(imgGray,imgBlur,Size(5,5),2,2);//高斯去噪
        // int lower=1 ,upper=15;//定义Canny检测的阈值
        // Canny(imgBlur,imgCanny,lower,upper,3,true);
        // Mat kernel = getStructuringElement(MORPH_RECT,Size(7,7));//定义膨胀操作核
        // dilate(imgCanny,imgDil,kernel);//膨胀
        // Canny(imgDil,imgCanny,lower,upper,3,true);

/********************************************检测轮廓****************************************/
        // vector<vector<Point>> contours;
        // vector<Vec4i> hierarchy;
        // findContours(imgCanny,contours,hierarchy,RETR_LIST,CHAIN_APPROX_TC89_KCOS);

        
        // for(int i=0;i<contours.size();i++)
        // {
        //                 float peri=arcLength(contours[i],true);
        //                 drawContours(imgGray,contours,i,Scalar(255),2);    //画出近似曲线
        // }




/*****************************************深度精确度打分***************************************************/
 
 //认为[4,9]的范围内，深度是准确的，根据此进行深度准确度打分。

Mat imgDepScore_v,imgDepScore;


 imgDepScore=1-abs(img-6.5)/5.0;//对深度打分公式，深度准确度高的范围为[4,9]在4和9处分数为0.5 ，<1.5  和  >11.5 分数为0
 imgDepScore=max(imgDepScore,0);//过滤掉了分数为负的图像
 imgDepScore.convertTo(imgDepScore,CV_8UC1,255);//将图像转化成CV_8UC1，因为applyColorMap只能接受8位无符号整型数据
 applyColorMap(imgDepScore,imgDepScore_v,COLORMAP_JET);
 
// imshow("Depth Accuracy",imgDepScore_v);





/*————————————————————坡度打分————————————————————————*/
Mat imgStCal,imgStScore,imgSt_x,imgSt_y,imgSt_g,imgSt_g2,imgBlur2,
imgSt_x2,imgSt_y2,imgSt_tan,imgSt_N,imgStScore_v;
GaussianBlur(img,imgBlur2,Size(27,27),5,5);//卷积核13*13 方差为5，5
imgStCal=max(imgBlur2,0.1);

Sobel(imgStCal,imgSt_x,CV_32FC1,1,0,3,0.25,0);
Sobel(imgStCal,imgSt_y,CV_32FC1,0,1,3,0.25,0);
pow(imgSt_x,2,imgSt_x2);
pow(imgSt_y,2,imgSt_y2);
imgSt_g2=imgSt_x2+imgSt_y2;
 sqrt(imgSt_g2,imgSt_g);
imgSt_tan=376*imgSt_g/imgStCal;


float* pt;
for(int i=0;i<imgSt_tan.rows;i++)
{
        pt=imgSt_tan.ptr<float>(i);
        for(int j=0;j<imgSt_tan.cols;j++)
        {
                pt[j]=atan(pt[j]);
        }
}
Mat theta2;
pow(imgSt_tan,2,theta2);
imgSt_N=-theta2/0.55;
exp(imgSt_N,imgStScore);
imgStScore.convertTo(imgStScore,CV_8UC1,255);
applyColorMap(imgStScore,imgStScore_v,COLORMAP_JET);
// imshow("Steep",imgStScore_v);


/**************************************平坦度打分****************************************/
// Mat imgFlCal,imgFlScore,imgFlScore_v;
// //定义平坦度打分的卷积核
// int k_s=11;//卷积核大小31
// Mat kernel_Fl=kernel_Fl_init(k_s);//定义卷积核
// filter2D(img,imgFlCal,img.depth(),kernel_Fl);
// imgFlCal=abs(imgFlCal);

// exp(-10*imgFlCal,imgFlScore);//将分数映射到0，1之间。
// Mat kernel_Fl_bar=kernel_Fl_init2(5);
// filter2D(imgFlScore,imgFlScore,imgFlScore.depth(),kernel_Fl_bar);
// imgFlScore.convertTo(imgFlScore,CV_8UC1,255);

// applyColorMap(imgFlScore,imgFlScore_v,COLORMAP_JET);
// imshow("Flatness",imgFlScore_v);


/**************************************分数叠加******************************************/
Mat imgScore,imgScore_v;
imgScore=0.5*imgDepScore+0.5*imgStScore;//imgScore 是CV_8UC1的图像，其元素值的范围是0-255
applyColorMap(imgScore,imgScore_v,COLORMAP_JET);

/**************************************颜色过滤*****************************************/
Mat imgScore_HSV;
cvtColor(imgScore_v,imgScore_HSV,COLOR_BGR2HSV);
int Hmin=0,Smin=0,Vmin=0;
int Hmax=28,Smax=255,Vmax=255;
Scalar HSVlower(Hmin,Smin,Vmin);
Scalar HSVupper(Hmax,Smax,Vmax);

Mat imgScore_mask;
inRange(imgScore_HSV,HSVlower,HSVupper,imgScore_mask);
//得到的imgScore_mask是最合适的降落区域

/**************************************画一个小圈圈*************************************/
float height=img.at<float>(240,376);
 if(height<4) height=4.0;
 float R=3*370/height;
 circle(imgDepScore_v,Point(376,240),R,Scalar(0,0,255),3);


/**************************************对imgScore_mask处理****************************/
        //因为得到的imgScore_mask的区域会有裂纹，所以要消除这些裂纹
        
        // Canny(imgBlur,imgCanny,lower,upper,3,true);
        Mat kernel = getStructuringElement(MORPH_RECT,Size(Dil_kernel_size,Dil_kernel_size));//定义膨胀操作核
         dilate(imgScore_mask,imgDil,kernel);//膨胀
         imshow("Landing Region",imgDil);
        //  Canny(imgDil,imgCanny,lower,upper,3,true);
        //  imshow("Landing Region Edge",imgCanny);

        //  vector<vector<Point>> contours;
        // vector<Vec4i> hierarchy;
        // findContours(imgCanny,contours,hierarchy,RETR_LIST,CHAIN_APPROX_TC89_KCOS);
        // vector<vector<Point>> conPoly(contours.size());
        // vector<Rect> boundRect(contours.size());
        // Point2f leftup,rightdown;
        // vector<Point2i> middle(contours.size());
        // int area=0;

        // float height=img.at<float>(240,376);
        // if(height<4) height=4.0;
        //  float R=3*370/height;
         

        // for(int i=0;i<contours.size();i++)
        // {
        //                 float peri=arcLength(contours[i],true);
        //                 if(peri<1200)continue;
        //                 drawContours(imgScore_v,contours,i,Scalar(0,0,255),3);    //画出近似曲线
        //                 approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//由轮廓计算出近似曲线
        //                 // drawContours(imgScore_v,conPoly,i,Scalar(255,0,255),2);    //画出近似曲线 
        //                  boundRect[i]=boundingRect(conPoly[i]);  //由近似曲线得到矩形框
        //                  leftup=boundRect[i].tl();
        //                 rightdown=boundRect[i].br();
        //                 middle[i]=0.5*(leftup+rightdown);//备选区域中心
        //                 circle(imgScore_v,middle[i],5,Scalar(255,255,255),-1);//画出矩形框的中心点
        //                 line(imgScore_v,Point(376,240),middle[i],Scalar(255,255,255),2);
        //                 circle(imgScore_v,middle[i],R,Scalar(0,0,255),3);


        // }
     






        /**********************************显示图像********************************************/
       
       
        imshow("Score",imgScore_v);
        imshow("1",imgDepScore_v);
        waitKey(1);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "disparity_handle");
  namedWindow("Trackbars",(640,200));
//   createTrackbar("Canny lower","Trackbars",&lower,20);
//   createTrackbar("Canny upper","Trackbars",&upper,20);
createTrackbar("Dil kernel size","Trackbars",&Dil_kernel_size,20);
  ros::NodeHandle n;
  ros::Subscriber ic=n.subscribe("/stereo_camera/disparity",10,Callback);
  ros::spin();
  return 0;
}