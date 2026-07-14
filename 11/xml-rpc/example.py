#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xmlrpc.client
server = xmlrpc.client.ServerProxy('http://tanoconsulting.com/sw/xmlrpc/demo/server/server.php')
result = server.examples.addtwo(4,7)
print(result) #　　結果が返ってくる

