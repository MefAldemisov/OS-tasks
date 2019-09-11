#!/bin/bash
 
count=10 # amount of execution steps
i=0 # loop variable
 
# while loop
while [ $i -lt $count ]; do
   ./ex1
   i=$((i+1))
done