#!/bin/bash
var=`cat /proc/cpuinfo`
echo $var | ./ex2 ex2.txt
