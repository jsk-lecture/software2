all: comment indent define getopt

comment: test-comment.c
	gcc -o test-comment test-comment.c
	# extract comment
	# https://stackoverflow.com/questions/47565090/need-help-to-extract-comments-from-c-file
	cat test-comment.c | awk '/\/\// {print $0}; /\/\*/ {aux=1}; {if(aux) print $0}; /\*\// {aux=0}' | sed '/^$$/d' | tee /tmp/test-comment.txt
	# check comment is more than 10 lines
	# https://stackoverflow.com/questions/25947072/how-to-check-that-a-file-has-more-than-1-line-in-a-bash-conditionalp
	bash -c 'mapfile -n 11 < /tmp/test-comment.txt; echo "test0.c has $${#MAPFILE[@]} lines"; [[ $${#MAPFILE[@]} -gt 10 ]] || exit 1'
	# check comment differ from original text
	bash -c 'export DIFF_LINE=$$(diff -y --suppress-common-lines /tmp/test-comment.txt test-comment.txt | wc -l); echo $$DIFF_LINE; [[ $$DIFF_LINE -gt 5 ]]'

indent: test-indent.c
	gcc -o test-indent test-indent.c
	indent -br -ce -npcs -npsl -brf test-indent.c -o /tmp/test-indent.c; diff test-indent.c /tmp/test-indent.c

define: fact-define.c
	gcc -o fact-define fact-define.c
	./fact-define 10 | tee /tmp/fact-define.txt; [ "$$(cat /tmp/fact-define.txt)" = "ret = 3628800" ]
	gcc -o fact-define -DDEBUG fact-define.c
	./fact-define 10 | tee /tmp/fact-define.txt; bash -c 'mapfile -n 11 < /tmp/fact-define.txt; [ $${#MAPFILE[@]} -gt 10 ]'

getopt: fact-getopt.c
	gcc -o fact-getopt fact-getopt.c
	./fact-getopt 10 | tee /tmp/fact-define.txt; [ "$$(cat /tmp/fact-define.txt)" = "ret = 3628800" ]
	./fact-getopt -d 10 | tee /tmp/fact-define.txt; bash -c 'mapfile -n 11 < /tmp/fact-define.txt; [ $${#MAPFILE[@]} -gt 10 ]'
