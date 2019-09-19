#!/bin/bash 

if test ! -f numbers
then
    echo 1 > numbers
fi

if ln numbers numbers.lock
	then                              
		for i in `seq 1 1000`;
		do
			nmrlast=`tail -1 numbers` 
			nmrlast=$((nmrlast + 1)) 

			echo $nmrlast >> numbers
		done
	rm numbers.lock
fi
