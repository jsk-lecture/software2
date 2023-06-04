all: test-fork-c test-thread-c test-thread2-c # test-fork-mmap test-fork-mmap-lock test-thread test-thread2 test-thread3 server client #kernelshark

test-fork-c: test-fork.c
	gcc -o test-fork test-fork.c
	./test-fork

test-thread-c: test-thread.c
	gcc -o test-thread test-thread.c -lpthread
	./test-thread

test-thread2-c: test-thread2.c
	gcc -o test-thread2 test-thread2.c -lpthread
	./test-thread2

client_server: client.c server.c
	gcc -o client client.c
	gcc -o server server.c

test-fork-mmap-c: test-fork-mmap.c
	gcc -o test-fork-mmap test-fork-mmap.c -lrt
	./test-fork-mmap

test-fork-mmap-lock-c: test-fork-mmap-lock.c
	gcc -o test-fork-mmap-lock test-fork-mmap-lock.c -lrt
	./test-fork-mmap-lock

homework: test-thread2-fix-c test-thread-signal-c test-thread2-py test-thread2-fix-py # test-thread-signal-py

test-thread2-fix-c: test-thread2-fix.c
	gcc -o test-thread2-fix test-thread2-fix.c -lpthread
	./test-thread2-fix

test-thread-signal-c: test-thread-signal.c
	gcc -o test-thread-signal test-thread-signal.c -lpthread
	./test-thread-signal

test-thread2-py: test-thread2.py
	python ./test-thread2.py

test-thread2-fix-py: test-thread2-fix.py
	python ./test-thread2-fix.py

test-thread-signal-py: test-thread-signal.py
	python ./test-thread-signal.py


# https://www.slideshare.net/makotoshimazu/ss-33071336
# sudo apt install kernelshark
kernelshark: load.c
	# mount -t debugfs nobody /proc/sys/debug # ?
	gcc -o load load.c
	(./load & PID=$$!; taskset -p 1 $$PID; renice -n  5 -p $$PID)
	(./load & PID=$$!; taskset -p 1 $$PID; renice -n 10 -p $$PID)
	(./load & PID=$$!; taskset -p 1 $$PID; renice -n 15 -p $$PID)
	#for i in $(shell seq 8); do (./load &); done
	sleep 1 # wait for all load starting
	sudo trace-cmd record -e sched_switch &
	top -d 0.1 -n 30
	sudo killall -INT trace-cmd
	sudo killall -KILL load
	sleep 5 # wait for trace-cmd to output logs
	sudo kernelshark
