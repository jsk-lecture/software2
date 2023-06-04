all: rat-py rat-cpp lc-cpp sum closure-cpp homework

rat-py:
	python rat1.py
	python rat2.py

rat-cpp:
	g++ -o rat1 rat1.cpp
	./rat1
	g++ -o rat2 rat2.cpp
	./rat2

lc-cpp:
	g++ -c -o lc1.o lc1.cpp
	g++ -o lc1 lc1.o
	./lc1
	nm -A lc1.o
	g++ -c -o lc2.o lc2.cpp
	g++ -o lc2 lc2.o
	./lc2
	nm -A lc2.o

sum:
	g++ -o sum1 sum1.cpp
	./sum1
	g++ -o sum2 sum2.cpp
	./sum2

closure-cpp:
	g++ -o closure closure.cpp
	./closure

### homework
homework: withdraw_py withdraw_cpp sqrt_cpp
withdraw_py:
	python withdraw-class.py

withdraw_cpp:
	g++ -o withdraw_class withdraw_class.cpp
	./withdraw_class
	g++ -o withdraw_closure withdraw_closure.cpp
	./withdraw_closure

sqrt_cpp:
	g++ -o sqrt-template sqrt-template.cpp
	./sqrt-template
	# NOT WORKING??
	# g++ -o sqrt-auto sqrt-auto.cpp
	# ./sqrt-auto

clean:
	rm -fr *.o rat1 rat2 lc1 lc2 sum1 sum2 closure withdraw_class withdraw_closure sqrt-template sqrt-auto
