#!/usr/bin/env python
#
# Publisher program
#   Sends "Hello World" to subscriber

import time
import zmq

print("Connecting to 5555")
context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.connect("tcp://localhost:5555")

#  Do 10 publish
for request in range(10):
    ss = "Hello World! {}".format(request)
    print("Sending: {}".format(ss))
    socket.send(ss)

    time.sleep(1)
