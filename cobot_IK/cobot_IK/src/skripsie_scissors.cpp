#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();
    int flag=1;

    sleep(2.0);

    moveit::planning_interface::MoveGroupInterface group("manipulator");
    
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    ros::Publisher display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
    ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());


    std::vector<double> joint_group_positions = {-3.28645, -1.16937, 2.0333, 3.76118, -1.57603, -0.12217}; 




while(flag<7){
    group.setJointValueTarget(joint_group_positions);

    // Visualize and move to target pose 2
    moveit::planning_interface::MoveGroupInterface::Plan my_plan2;
    moveit::planning_interface::MoveItErrorCode success2 = group.plan(my_plan2);
    //ROS_INFO("Visualizing plan 2: %s", success2.val ? "SUCCESS" : "FAILED");
   
        

         if (success2 == moveit::planning_interface::MoveItErrorCode::SUCCESS)
        {
            // Execute the plan
            moveit::planning_interface::MoveItErrorCode execution_success = group.move();
            if (execution_success == moveit::planning_interface::MoveItErrorCode::SUCCESS)
            {
                ROS_INFO("Visualizing plan 2: %s", success2.val ? "SUCCESS" : "FAILED");
                // Increment only if both planning and execution are successful


                if(flag==1){
                joint_group_positions[1]=-1.11876;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }
                else{
                    if(flag==2){
                joint_group_positions[1]=-1.16937;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }

                else{

                    if(flag==3){
                joint_group_positions[0]=-0.28519;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }
                else{

                    if(flag==4){
                joint_group_positions[1]=-1.09956;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }

                else{
                        if(flag==5){
                joint_group_positions[1]=-1.16937;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }
                else{

                    if(flag==6){
                joint_group_positions[1]=-1.09956;
                ros::WallDuration(1.0).sleep();
                flag=flag+1;
                }
                else{

                }

                                 }


                            }

                         }

                    }
                } 
            }


        }
   
    
    

}


    ros::shutdown();
    return 0;
}