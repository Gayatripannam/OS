#!/bin/bash

# while loop

# init
# while [ condition ]
# do
#	body
#	modification
# done

echo -n "Enter number : "
read num

echo "$num 's table : "
i=1								# init
while [ $i -lt 11 ]				# cond
do
	echo `expr $i \* $num`		# body
	i=`expr $i + 1`				# mod
done


