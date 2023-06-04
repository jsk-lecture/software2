#!/usr/bin/env python

import rospy
from beginner_tutorials.msg import NamedPoint

def callback(msg):
    rospy.loginfo("I heard {} x:{}, y:{}, z:{}".format(msg.name,
                                                       msg.point.x, msg.point.y, msg.point.z))

def listener():
    rospy.init_node('listener')
    rospy.Subscriber('chatter', NamedPoint, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        listener()
    except rospy.ROSInterruptException: pass
