#ifndef __MY_HANDLE_FUNCTION
#define __MY_HANDLE_FUNCTION

#include<ros/ros.h>
#include<iostream>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>//ROS图像类型的编码函数
#include<image_transport/image_transport.h>//用来在ROS系统中的话题上发布和订阅图像消息
//opencv标准头文件
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int img_w=752;//图像的宽度
int img_h=480;//图像的高度

class Path_Point
{
        public:
        Path_Point(){}
        Path_Point(Point2i &local ,vector<Point2i> ps):lc(local),pd(0),pl(local),td(0){ 
                point_sets.resize(ps.size());
                point_sets=ps;
                Get_nearPoints();}//生成原点的构造函数

        Path_Point(Path_Point &p,vector<Point2i> ps,int flag):pl(p.lc){
                point_sets.resize(ps.size());
                point_sets=ps;
                if(flag==0) lc.x=p.nl[0].x,lc.y=p.nl[0].y;
                if(flag==1) lc=p.nl[1];
                if(flag==2) lc=p.nl[2];
                pd=(lc.x-p.lc.x)*(lc.x-p.lc.x)+(lc.y-p.lc.y)*(lc.y-p.lc.y);
                td=pd+p.td;
                Get_nearPoints();

        }//输入衍生点坐标，并设置标志，表示本对象是
        //衍生点的第几个最近点


        Point2i lc;//本点的坐标 local
        Point2i pl;//衍生点坐标 parent local
        Point2i nl[3];//最近点的坐标 near local

        int td;//到起点的总距离 total distance
        int pd;//到衍生点的总距离 parent distance
        vector<Point2i> point_sets;//点集

        void Get_nearPoints();
};



void Path_Point::Get_nearPoints()
{
        int num=point_sets.size();
        vector<int> d(num);
        vector<int> ds(num);
        for(int i=0;i<num;i++)
        {
                if(((lc.x==point_sets[i].x)&&(lc.y==point_sets[i].y))||((pl.x==point_sets[i].x)&&(pl.y==point_sets[i].y))) 
                {
                        d[i]=999999999;
                        ds[i]=d[i];
                }
                else
                {
                        int dis=(point_sets[i].x-lc.x)*(point_sets[i].x-lc.x)+(point_sets[i].y-lc.y)*(point_sets[i].y-lc.y);
                        d[i]=dis;
                        ds[i]=dis;
                }
        }
        sort(ds.begin(),ds.end());
        for(int i=0;i<num;i++)
        {
                if(ds[0]==d[i]) {nl[0]=point_sets[i];continue;}
                if(ds[1]==d[i]) {nl[1]=point_sets[i];continue;}
                if(ds[2]==d[i]) {nl[2]=point_sets[i];continue;}
        }
}




vector<Point2i> getContours(Mat & imgDil, Mat &img)
{       
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        Point2f leftup,rightdown;
        vector<Point2i> middle(contours.size());
        int area=0;
        for(int i=0;i<contours.size();i++)
        {
                area=contourArea(contours[i]);
                if(100<area&&area<10000)
                {
                        float peri=arcLength(contours[i],true);//计算轮廓长度
                        approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//由轮廓计算出近似曲线
                        drawContours(img,conPoly,i,Scalar(255,0,255),2);    //画出近似曲线    
                        boundRect[i]=boundingRect(conPoly[i]);  //由近似曲线得到矩形框
                        rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),3);//画出矩形框
                        leftup=boundRect[i].tl();
                        rightdown=boundRect[i].br();
                        middle[i]=0.5*(leftup+rightdown);//备选区域中心
                        circle(img,middle[i],5,Scalar(0,0,255),-1);//画出矩形框的中心点
                }       
        }
        return middle;   
}

void Create_Path(const vector<Point2i> Point_sets,Mat &img)
{
        //Point_sets是方形框的中心点点集，img是得到的图像
        Point2i point_0(img_w/2,img_h/2);
        Path_Point p0(point_0,Point_sets);
        vector<Path_Point> p1(3);
        for(int i=0;i<3;i++)
        {
                p1[i]=Path_Point(p0,Point_sets,i);
        }
        vector<Path_Point>p2(9);
        for(int i=0;i<3;i++)
        {
                for(int ii=0;ii<3;ii++)
                {
                        p2[3*i+ii]=Path_Point(p1[i],Point_sets,ii);
                }
        }
        vector<Path_Point>p3(27);
        for(int i=0;i<3;i++)
        {
                for(int ii=0;ii<3;ii++)
                {
                        for(int iii=0;iii<3;iii++)
                        {
                                p3[9*i+3*ii+iii]=Path_Point(p2[3*i+ii],Point_sets,iii);
                        }
                }
        }
        vector<Path_Point>p4(81);
        for(int i=0;i<3;i++)
        {
                for(int ii=0;ii<3;ii++)
                {
                        for(int iii=0;iii<3;iii++)
                        {
                                for(int iiii=0;iiii<3;iiii++)
                                {
                                        p4[27*i+8*ii+3*iii+iiii]=Path_Point(p3[9*i+3*ii+iii],Point_sets,iiii);
                                }
                        }
                }
        }
        vector<int> dis(81);
        for(int i=0;i<81;i++)
        {
                dis[i]=p4[i].td;
        }
        sort(dis.begin(),dis.end());
        for(vector<int>::iterator it=dis.begin();it<dis.end();it++)
        {
                cout<<*it<<"|";
        }
        int id;
        for(int i=0;i<81;i++)
        {
                if(dis[6]==p4[i].td)//0是选距离最小的，可以改变这
                {
                        id=i;
                        break;
                }
        }
        vector<Point2i> path(5);
         path[0]=point_0;
         path[4]=p4[id].lc;
         path[3]=p4[id].pl;
         for(int i=0;i<27;i++)
         {
                 if(p3[i].lc.x==path[3].x&&p3[i].lc.y==path[3].y)
                 {
                         path[2]=p3[i].pl;
                         break;
                 }
         }
         for(int i=0;i<9;i++)
         {
                  if(p2[i].lc.x==path[2].x&&p2[i].lc.y==path[2].y)
                 {
                         path[1]=p2[i].pl;
                         break;
                 }
         }

         for(int i=0;i<4;i++)
         {
                 line(img,path[i],path[i+1],Scalar(0,0,255),2);
         }
}


void getContours(Mat &img)//对原始彩色图像处理第一步，对图像进行边缘检测，发现所有的建筑物
{
        Mat imgGray , imgBlur , imgCanny , imgDil , imgEro;
        Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
        /********************preprocessing*********************/
        cvtColor(img,imgGray,COLOR_BGR2GRAY);//将图像转化为灰度图
        GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);//高斯去噪
        int lower=15 ,upper=159;//定义Canny检测的阈值
        Canny(imgBlur,imgCanny,lower,upper,3,true);//Canny检测，true使用准确梯度
        dilate(imgCanny,imgDil,kernel);//边沿扩充

        vector<Point2i> Point_sets = getContours(imgDil,img);//获得轮廓，并将轮廓中心点标出，并获得中心点点集
        Create_Path(Point_sets,img);

        imshow("Image",img);
        imshow("Image Dilate",imgDil);

        waitKey(2000);
        
        
}













#endif