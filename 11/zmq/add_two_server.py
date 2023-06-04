#!/usr/bin/env python
#
# Subscriber program
#   Read message from publisher

import zmq
import json

context = zmq.Context()

print("Wait for Connecting")
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5555")

while True:
    #  Wait for next request from client
    message = socket.recv_json()
    print("Received: {}".format(message))
    reply = {'i3': message['i1']+message['i2']}
    print("Returns: {}".format(reply))
    socket.send_json(reply)
