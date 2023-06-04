#!/usr/bin/env python
# -*- coding: utf-8 -*-                                                                              
import rospy
from geometry_msgs.msg import PoseStamped

if __name__ == '__main__':
    try:
        rospy.init_node('send_goal_topic', anonymous=True)
        pub = rospy.Publisher('move_base_simple/goal', PoseStamped, queue_size=1)
        rospy.sleep(1)
        
        goal = PoseStamped()
        goal.header.frame_id = 'map' # map フレーム相対で目標位置を指定
        goal.pose.position.x=41;
        goal.pose.position.y=17;
        goal.pose.orientation.w = 1
        rospy.loginfo("send goal :")
        rospy.loginfo(goal)        
        pub.publish(goal)
    except rospy.ROSInterruptException: pass
