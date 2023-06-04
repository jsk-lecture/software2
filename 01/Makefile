all: c scheme pascal java python go fortran

c: test0.c
	gcc -o test0-c test0.c
	./test0-c

emacs: test0.el
	emacs --load ./test0.el

scheme: test0.scm
	gosh -e '(progn (load "./test0.scm") (exit))'

pascal: test0.p
	fpc -otest0-p ./test0.p
	./test0-p

java: test0.java
	javac test0.java
	java test0

python: test0.py
	python test0.py

go: test0.go
	go build -o test0-go test0.go
	./test0-go
	go run test0.go

fortran: test0.f
	gfortran test0.f -o test0-f
	./test0-f

go-arm64:
	GOARCH=arm64 go build -o test0-go-arm64 test0.go
	file test0-go-arm64


clean:
	-rm -f test0.s test0.o test0-c test0-f test0-p test0.class test0-go test0-go-arm64
