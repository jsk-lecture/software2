#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xmlrpclib
server = xmlrpclib.Server('http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php')
result = server.examples.addtwo(4,7)
print result #　　結果が返ってくる

