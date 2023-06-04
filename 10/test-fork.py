#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import os
import sys

# test-fork.py

shared_resource = 100

pid = os.fork()

if pid == 0:
    # 子プロセス
    for i in range(10):
        print("Process [{}]: {}\n".format(pid, i))
        shared_resource+=1
        time.sleep(1)

    print("Process {} finished, return {}.\n".format(pid, shared_resource))
    sys.exit(0)
elif pid > 0:
    # 親プロセス
    for i in range(20):
        print("Process [{}]: {}\n".format(pid, i))
        shared_resource+=1
        time.sleep(0.3) # 300 msec

os.waitpid(pid, 0)
print("Process {} finished, return {}.\n".format(pid, shared_resource))
