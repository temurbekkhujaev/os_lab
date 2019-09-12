#!/bin/bash

for ((i=0;i<10;i++)); 
do 
	gcc ex1.c -o ex1
	./ex1 "$i"
	rm ex1
done
