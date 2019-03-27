#!/bin/bash

j="1"
for i in ~/modul3/files/*.txt
do
	if [ `echo "$j % 3" | bc` -eq 0 ];
	 then
		#echo $j;
		cat $i
	fi 
j=$(($j+1))
done

