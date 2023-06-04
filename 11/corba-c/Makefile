all: corba-sample

corba-sample: echo-server echo-client
	xterm -e "$$(pwd)/echo-server -ORBInitRef NameService=corbaloc:iiop:127.0.0.1:2809/NameService" &
	xterm -hold -e "while [ 1 ]; do $$(pwd)/echo-client -ORBInitRef NameService=corbaloc:iiop:127.0.0.1:2809/NameService; sleep 1; done"

echo.hh echoSK.cc: echo.idl
	omniidl -bcxx echo.idl

echo-server: echo-server.cpp echo.hh echoSK.cc
	g++ -o echo-server echo-server.cpp echo_impl.cpp echoSK.cc `pkg-config omniORB4 --cflags --libs`

echo-client: echo-client.cpp echo.hh echoSK.cc
	g++ -o echo-client echo-client.cpp echoSK.cc `pkg-config omniORB4 --cflags --libs`

clean:
	rm -fr echo-server echo-client echo.hh echoSK.cc
