all: subscribe publish add_two_client

# sudo apt install libzmqpp-dev

python:
	xterm -e ./publish.py &
	(sleep 3; xterm -e ./publish.py) &
	./subscribe.py

cpp: subscribe publish
	xterm -e ./publish &
	(sleep 3; xterm -hold -e ./publish ) & ## this fails
	./subscribe

relay: add_two_client
	xterm -e ./add_two_server.py &
	./add_two_client.py 1 2
	./add_two_client

subscribe: subscribe.cpp
	g++ -o subscribe subscribe.cpp -lzmq

publish: publish.cpp
	g++ -o publish publish.cpp -lzmq

add_two_client: add_two_client.cpp
	g++ -o add_two_client add_two_client.cpp -lzmq -ljsoncpp

clean:
	rm -f subscribe publish add_two_client

