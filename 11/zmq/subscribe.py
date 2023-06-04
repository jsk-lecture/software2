#!/usr/bin/env python
#
# Subscriber program
#   Read message from publisher

import zmq

context = zmq.Context()

print("Wait for Connecting")
socket = context.socket(zmq.SUB)
socket.bind("tcp://*:5555")

# set filter option "" means pass through
socket.setsockopt(zmq.SUBSCRIBE, "")

while True:
    #  Wait for next request from client
    message = socket.recv()
    print("Received: {}".format(message))
