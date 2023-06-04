all:

# sudo apt install libzmqpp-dev

python:
	xterm -hold -e 'set -x; ./publish.py' &
	xterm -hold -e 'set -x; sleep 3; ./publish.py' &
	xterm -hold -e 'set -x; ./subscribe.py'

cpp: subscribe publish
	xterm -hold -e 'set -x; ./publish' &
	xterm -hold -e 'set -x; sleep 3; /publish' &
	xterm -hold -e 'set -x; ./subscribe'

relay: add_two_client
	xterm -hold -e 'set -x; ./add_two_server.py' &
	xterm -hold -e 'set -x; while [ 1 ]; do ./add_two_client.py 1 2; sleep 2; done' &
	xterm -hold -e 'set -x; while [ 1 ]; do ./add_two_client; sleep 3; done'

subscribe: subscribe.cpp
	g++ -o subscribe subscribe.cpp -lzmqpp -lzmq

publish: publish.cpp
	g++ -o publish publish.cpp -lzmqpp -lzmq

add_two_client: add_two_client.cpp
	g++ -o add_two_client add_two_client.cpp -lzmqpp -lzmq -ljsoncpp

clean:
	rm -f subscribe publish add_two_client

