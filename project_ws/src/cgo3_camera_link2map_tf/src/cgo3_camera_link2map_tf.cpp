#include<ros/ros.h>
#include<tf2_ros/transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>
#include<geometry_msgs/PoseStamped.h>
#include<gazebo_msgs/GetLinkState.h>


int main(int argc, char ** argv)
{
        ros::init(argc,argv,"camera_frame2map_tf");
        ros::NodeHandle n;
        ros::ServiceClient state_client = n.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");

        tf2_ros::TransformBroadcaster pub;
        geometry_msgs::TransformStamped tfs;

        gazebo_msgs::GetLinkState link_states;

        link_states.request.link_name="cgo3_camera_link";
        link_states.request.reference_frame="world";

        while(ros::ok())
        {
                state_client.call(link_states);
                tfs.header.frame_id="map";
                tfs.child_frame_id="cgo3_camera_link";
                tfs.header.stamp=ros::Time::now();

                tfs.transform.translation.x=link_states.response.link_state.pose.position.x;
                tfs.transform.translation.y=link_states.response.link_state.pose.position.y;
                tfs.transform.translation.z=link_states.response.link_state.pose.position.z;

                tfs.transform.rotation.x=link_states.response.link_state.pose.orientation.x;
                tfs.transform.rotation.y=link_states.response.link_state.pose.orientation.y;
                tfs.transform.rotation.z=link_states.response.link_state.pose.orientation.z;
                tfs.transform.rotation.w=link_states.response.link_state.pose.orientation.w;

                pub.sendTransform(tfs);

                
                                

        }
        
        ros::spin();
return 0;
}