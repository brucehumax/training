#! /bin/bash

mkdir DOGANDCAT

for i in {1..50}
do
	touch ./DOGANDCAT/DOG_$i.txt;
	touch ./DOGANDCAT/CAT_$i.txt;
done
