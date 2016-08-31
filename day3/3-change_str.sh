#!/bin/bash

for file in `find *HUMUX*`
do 
	mv $file `echo $file | sed -e 's/HUMUX/HUMAX/'`
done
