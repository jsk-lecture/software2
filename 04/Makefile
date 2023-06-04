all: sum  cpp double simpson

.PHONY: sum

sum:
	diff -y sum-1.py sum-2.py || echo "OK"
	python2 ./sum-1.py
	python2 ./sum-2.py
	python2 ./sum-3.py

cpp:
	g++ -o sum sum.cpp
	./sum

# homework
simpson:
	python2 -c 'execfile("./simpson-1.py")'
	python2 -c 'execfile("./simpson-2.py")'

double:
	python2 -c 'execfile("./double.py"); print(double(inc))'
	python2 -c 'execfile("./double.py"); print(double(inc)(0))'
	python2 -c 'execfile("./double.py"); print((double(double))(inc)(0))'


