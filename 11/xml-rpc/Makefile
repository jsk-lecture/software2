all: cpp python bash

www:
	netcat www.jsk.t.u-tokyo.ac.jp 80 < get.txt

SystemProxy.txt:
	xml-rpc-api2cpp http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php examples SystemProxy > SystemProxy.txt

SystemProxy.cc SystemProxy.h: SystemProxy.txt
	sed '/^#endif/q' SystemProxy.txt > SystemProxy.h
	grep -A 1000 '^// SystemProxy.cc' SystemProxy.txt > SystemProxy.cc

cpp: SystemProxy.cc SystemProxy.h
	g++ -o example example.cpp SystemProxy.cc `xmlrpc-c-config c++ libwww-client --cflags --libs`
	./example

python:
	python example.py

bash:
	xmlrpc http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php system.listMethods
	xmlrpc http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php system.methodSignature examples.addtwo
	xmlrpc http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php examples.addtwo i/4 i/7

telnet: #http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php
	netcat gggeek.altervista.org 80 < list-methods.txt
	netcat gggeek.altervista.org 80 < list-signature.txt
	netcat gggeek.altervista.org 80 < add-two.txt


clean:
	rm -fr example SystemProxy.cc SystemProxy.h SystemProxy.txt

