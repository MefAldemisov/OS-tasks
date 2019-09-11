#!/bin/bash
 
count=10
i=0
 
# while loop
while [ $i -lt $count ]; do
   ./ex1
   i=$((i+1))
done