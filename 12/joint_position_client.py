#!/usr/bin/env python
# -*- coding: utf-8 -*-                                           

import rospy
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

if __name__ == '__main__':
    try:
        rospy.init_node('joint_trajectory_example', anonymous=True)
        pub = rospy.Publisher('/fullbody_controller/command', JointTrajectory, queue_size=1)
        rospy.sleep(1)
        
        joint = JointTrajectory()
        joint.joint_names = ['head_neck_p', 'head_neck_y']
        print(joint)
        print(joint.points)
        joint.points.append(JointTrajectoryPoint(positions=[-1, 1], time_from_start=rospy.Duration(1.0)))
        joint.points.append(JointTrajectoryPoint(positions=[0, -1], time_from_start=rospy.Duration(2.0)))

        rospy.loginfo("send pose :")
        rospy.loginfo(joint)
        pub.publish(joint)
        
    except rospy.ROSInterruptException: pass
