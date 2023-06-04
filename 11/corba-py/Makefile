all: corba-sample

corba-sample: echo_idl.py
	xterm -e "python echo-server.py -ORBInitRef NameService=corbaloc:iiop:127.0.0.1:2809/NameService" &
	xterm -hold -e "while [ 1 ]; do python echo-client.py -ORBInitRef NameService=corbaloc:iiop:127.0.0.1:2809/NameService; sleep 1; done"

echo_idl.py: echo.idl
	omniidl -bpython echo.idl

clean:
	rm -fr echo_idl.py EchoApp EchoApp__POA *.pyc
