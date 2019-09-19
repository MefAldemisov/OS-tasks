# 
# Author: Alina Bogdanova BS18-04
# Date: 18.09.19
# Description: Write a shell script that produces a file of sequential
# numbers by reading the last number in the file,
# adding 1 to it, and then appending it to the file. Run
# one instance of the script in the background and one
# in the foreground, each accessing the same file
# How long does it take before a race condition
# manifests itself? What is the critical region?
# Modify the script to prevent the race
# Hint: use ln file file.lock to lock the data file


count=0
while [ $count -le 100 ]
do
    count=$((count+1))
    if (( ! ln numbers.txt numbers.lock))
    then
        var=$(tail -n 1 numbers.txt)
        var=$((var+1))
        echo $var >> numbers.txt
        rm numbers.lock
    else
        echo did not succeed
    fi
done
echo "I'm done"
