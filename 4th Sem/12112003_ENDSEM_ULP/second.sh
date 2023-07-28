#!/usr/bin/bash

gcc brute.c -o brute
gcc optimal.c -o optimal

for ((i=0;i<100;i++))
do
	gcc tc.c -o tc
	./tc > testcase.txt
	cat testcase.txt
	cat testcase.txt | ./brute > brute.txt
	cat testcase.txt | ./optimal > optimal.txt
	./test
done
