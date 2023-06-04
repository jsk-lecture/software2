#!/usr/bin/python

import paho.mqtt.client as mqtt
import time, sys

# set topic name
topic = "topic"
if len(sys.argv) > 1:
    topic = sys.argv[1]

# Initialize mqtt client
client = mqtt.Client()

# Connect to broaker
client.connect("localhost",
               port=1883,
               keepalive=60)

#  Do 10 publish
for request in range(10):
    ss = "Hello World! {} on {}".format(
        request, topic)
    print("Sending: {}".format(ss))
    client.publish(topic, ss)

    time.sleep(1)

