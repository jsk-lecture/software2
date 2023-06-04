all: list queue_stack search sort tree graph-search homework

list:
	gcc -o list_c list.c
	./list_c
	g++ -o list_cpp list.cpp
	./list_cpp

queue_stack:
	g++ -o queue_stack queue_stack.cpp
	./queue_stack

search:
	python ./search.py

sort:
	python ./sort.py
	gcc -o sort-gen sort-gen.c
	./sort-gen -n 10
	gcc -o sort_c sort.c sortlib.c
	./sort_c

tree:
	python ./traverse.py

graph-search:
	python ./bfs.py
	python ./dfs.py
	python ./dlfs.py

## homework
homework: recursive_sort calc ids

recursive_sort:
	python ./recursive_sort.py

calc:
	python ./calc.py

ids:
	python ./ids.py
