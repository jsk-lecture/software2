#!/usr/bin/env python

import time
import threading
import signal
import sys

# Not working...
# https://mail.python.org/pipermail/python-bugs-list/2007-July/039156.html
def signal_handler(signum, frame):
    print("Signal handler called with wignal", signum)
    sys.exit(-1)

# test-thread.py

shared_resource = 0

def task(loop):
    global shared_resource
    for i in range(loop):
        print("Thread {}: i:{}, shared_resource:{}".format(
            threading.current_thread().ident, i, shared_resource))
        shared_resource = shared_resource + 1
        time.sleep(10.0/loop)

thread1 = threading.Thread(target=task, args=([10]))
thread2 = threading.Thread(target=task, args=([20]))

signal.signal(signal.SIGINT, signal_handler)
print(signal.SIGINT)

thread1.start()
thread2.start()

thread1.join()
thread2.join()
print("shared_resource {}".format(shared_resource))
