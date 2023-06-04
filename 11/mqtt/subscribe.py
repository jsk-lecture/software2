#!/usr/bin/python

import paho.mqtt.client as mqtt
import time, sys

def on_message(client, userdata, msg):
    print("Received message [{}] on \
topic [{}]".format(msg.payload, msg.topic))

# set topic-filter name
topic = "#"
if len(sys.argv) > 1:
    topic = sys.argv[1]

# Initialize mqtt client
client = mqtt.Client()

# Connect to broaker
client.connect("localhost",
               port=1883,
               keepalive=60)

# Set callback function
client.on_message = on_message

# Topic-based filter
client.subscribe(topic)

# event loop
client.loop_forever()

