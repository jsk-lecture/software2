all: bash python

bash:
	xterm -hold -e 'set -x; while [ 1 ]; do mosquitto_pub -t topic -m hello; sleep 1; done' &
	xterm -hold -e 'set -x; while [ 1 ]; do mosquitto_pub -t hello -m world; sleep 1; done' &
	xterm -hold -e 'set -x; mosquitto_sub -t hello' &
	xterm -hold -e 'set -x; mosquitto_sub -t "#"' &

python:
	xterm -hold -e 'set -x; while [ 1 ]; do ./publish.py; sleep 1; done' &
	xterm -hold -e 'set -x; while [ 1 ]; do ./publish.py hello; sleep 1; done' &
	xterm -hold -e 'set -x; ./subscribe.py hello' &
	xterm -hold -e 'set -x; ./subscribe.py'

