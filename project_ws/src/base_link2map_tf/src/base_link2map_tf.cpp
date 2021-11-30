#include<ros/ros.h>
#include<tf2_ros/transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>
#include<geometry_msgs/PoseStamped.h>

void poseCallback(const geometry_msgs::PoseStamped & msg )
{
        static  tf2_ros::TransformBroadcaster pub;
        geometry_msgs::TransformStamped tfs;
        tfs.header.frame_id = "map";
        tfs.child_frame_id="base_link";
        tfs.header.stamp = ros::Time::now();
      

        tfs.transform.translation.x=msg.pose.position.x;
        tfs.transform.translation.y=msg.pose.position.y;
        tfs.transform.translation.z=msg.pose.position.z;

       
        tfs.transform.rotation.x=msg.pose.orientation.x;
        tfs.transform.rotation.y=msg.pose.orientation.y;
        tfs.transform.rotation.z=msg.pose.orientation.z;
        tfs.transform.rotation.w=msg.pose.orientation.w;
        
        pub.sendTransform(tfs);

}

int main(int argc,char ** argv)
{
        ros::init(argc,argv,"base_link2map_tf");
      
        ros::NodeHandle nh;

        ros::Subscriber pose_sub = nh.subscribe("/mavros/local_position/pose",100,poseCallback);
        
        ros::spin();

        return 0;
}
