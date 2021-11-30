#include<ros/ros.h>
#include<tf2_ros/transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>
#include<geometry_msgs/PoseStamped.h>
#include<gazebo_msgs/GetModelState.h>

void poseCallback(const geometry_msgs::PoseStamped & msg )
{       
         ros::NodeHandle nh;
         ros::ServiceClient states_client = nh.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");
        static  tf2_ros::TransformBroadcaster pub;
        geometry_msgs::TransformStamped tfs;

        gazebo_msgs::GetModelState model_states;
        model_states.request.model_name="iris";
        model_states.request.relative_entity_name="world";
        states_client.call(model_states);

        tfs.header.frame_id = "map";
        tfs.child_frame_id="odom";
        tfs.header.stamp = ros::Time::now();
        

        tfs.transform.translation.x=model_states.response.pose.position.x-msg.pose.position.x;
        tfs.transform.translation.y=model_states.response.pose.position.y-msg.pose.position.y;
        tfs.transform.translation.z=model_states.response.pose.position.z-msg.pose.position.z;

       
        tfs.transform.rotation.x=0;
        tfs.transform.rotation.y=0;
        tfs.transform.rotation.z=0;
        tfs.transform.rotation.w=1;
        
        pub.sendTransform(tfs);

}



int main(int argc,char ** argv)
{
        ros::init(argc,argv,"odom2map_tf");
        
        

        ros::NodeHandle n;

        ros::ServiceClient states_client = n.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");

        ros::Subscriber pose_sub = n.subscribe("/mavros/local_position/pose",100,poseCallback);

        
        ros::spin();

        return 0;
}
