all: my_sqrt_py my_sqrt_pl my_factorial_py eval_test my_factorial_c plus fib_c fib_py

my_sqrt_py: my_sqrt.py
	python2 -c 'execfile("./my_sqrt.py"); r=my_sqrt(16); print(r)'

my_sqrt_pl: my_sqrt.pl
	echo 'my_sqrt(16, Y), write(Y), nl, halt.' | prolog -q -f my_sqrt.pl
	echo 'my_sqrt(X, 4), write(X), nl, halt.' | prolog -q -f my_sqrt.pl

my_factorial_py: my_factorial.py
	python2 -c 'execfile("./my_factorial.py"); n=my_factorial_1(5); print(n);'
	python2 -c 'execfile("./my_factorial.py"); n=my_factorial_2(5); print(n);'
	python2 -c 'execfile("./my_factorial.py"); n=my_factorial_3(5); print(n);'
	python2 -c 'execfile("./my_factorial.py"); n=my_factorial_4(5); print(n);'

eval_test: eval_test.py eval_test.rkt eval_test.c
	-python2 -c 'execfile("./eval_test.py");'
	racket -l lazy -e '(load "eval_test.rkt")'
	gcc -O0 -o eval_test_O0 eval_test.c
	./eval_test_O0

my_factorial_c: my_factorial_1.c my_factorial_2.cpp
	gcc -g -O0 -o my_factorial_1_c my_factorial_1.c
	gcc -g -O0 -o my_factorial_2_c my_factorial_2.c
	./my_factorial_1_c 5
	./my_factorial_1_c 15
	./my_factorial_2_c 5
	./my_factorial_2_c 15
	g++ -g -O0 -o my_factorial_1_cpp my_factorial_1.cpp -lgmp -lgmpxx
	./my_factorial_1_cpp 10000 2> /dev/null
	./my_factorial_1_cpp 12000 2> /dev/null
	./my_factorial_1_cpp 14000 2> /dev/null
	./my_factorial_1_cpp 16000 2> /dev/null
	./my_factorial_1_cpp 10000 2> /dev/null
	./my_factorial_1_cpp 12000 2> /dev/null
	./my_factorial_1_cpp 14000 2> /dev/null
	./my_factorial_1_cpp 16000 2> /dev/null
	g++ -g -O0 -o my_factorial_2_cpp my_factorial_2.cpp -lgmp -lgmpxx
	./my_factorial_2_cpp 10000 2> /dev/null
	./my_factorial_2_cpp 12000 2> /dev/null
	./my_factorial_2_cpp 14000 2> /dev/null
	./my_factorial_2_cpp 16000 2> /dev/null
	./my_factorial_2_cpp 10000 2> /dev/null
	./my_factorial_2_cpp 12000 2> /dev/null
	./my_factorial_2_cpp 14000 2> /dev/null
	./my_factorial_2_cpp 16000 2> /dev/null
	#	gcc -g -O0 -o my_factorial_2 my_factorial_2.c
	# gdb --batch --command=my_factorial.gdb --args my_factorial_1 5
	# valgrind --tool=massif --massif-out-file=my_factorial_1.out ./my_factorial_1 5
	# ms_print my_factorial_1.out

scope: scope.py scope.bash
	python2 ./scope.py
	bash ./scope.bash

## homework
plus: plus.py
	python -m trace --trace plus.py

fib_c: fib.c
	gcc -pg -g -O0 -o fib fib.c
	./fib  5; mv gmon.out  fib_5.out
	gprof --brief ./fib ./fib_5.out
	./fib 15; mv gmon.out fib_15.out
	gprof --brief ./fib ./fib_15.out
	g++ -pg -g -O0 -o fib_fat fib_fat.cpp
	bash -c 'for (( i = 5; i <= 15; ++i )); do ./fib_fat $$i; done'

fib_py: fib.py fib_fat.py
	python2 -m trace --count -C . ./fib.py  5; mv fib.cover fib_5.cover; cat fib_5.cover
	python2 -m trace --count -C . ./fib.py 15; mv fib.cover fib_15.cover; cat fib_15.cover
	bash -c 'for (( i = 5; i <= 15; ++i )); do python2 ./fib_fat.py $$i; done'

decompile: fact-toc.c
	gcc -S -c -O0 -o fact-toc-O0.s fact-toc.c
	sed -n -e '/^fact:/,/.cfi_endproc/ p' fact-toc-O0.s
	gcc -S -c -O2 -o fact-toc-O2.s fact-toc.c
	sed -n -e '/^fact:/,/.cfi_endproc/ p' fact-toc-O2.s
	gcc -g -O0 -o fact-toc-O0 fact-toc.c
	docker run --rm -v `pwd`:/samples cincan/snowman-decompile -v /samples/fact-toc-O0 2>&1 | sed -n -e '/^int.*_t fact/,/^int.*_t / p'
	gcc -g -O2 -o fact-toc-O2 fact-toc.c
	docker run --rm -v `pwd`:/samples cincan/snowman-decompile -v /samples/fact-toc-O2 2>&1 | sed -n -e '/^int.*_t fact/,/^int.*_t / p'
