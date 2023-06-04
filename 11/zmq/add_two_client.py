#!/usr/bin/env python
#

import time
import zmq
import sys

# initialie request argument
i1 = 4
i2 = 7
print(sys.argv, len(sys.argv))
if len(sys.argv) > 1:
    i1 = int(sys.argv[1])
if len(sys.argv) > 2:
    i2 = int(sys.argv[2])
request = {'i1': i1, 'i2': i2}

print("Connecting to 5555")
context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

print("Sending: {}".format(request))
socket.send_json(request)

response = socket.recv_json()
print("Received: {}".format(response))
print("Answer is {}".format(response['i3']))
