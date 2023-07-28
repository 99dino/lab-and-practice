#!/usr/bin/bash

read -p "enter no of terms of fibonacci series : " n
echo "N : $n"
a=0
b=1
ans=0
if [ $n -eq 1  ]
then 
	ans=1
fi
if [ $n -ge 2 ]
then
	ans=2
fi

for((i=0;i<n-2;i++))
do
	fact=1
	c=$b
	b=` expr $b + $a `
	#echo "b : $b"
	a=$c
	for ((j=1;j<=$b;j++))
	do
		#fact=`expr $fact + $j`
		fact=` expr $fact \* $j `
	done
	ans=` expr $ans + $fact `
	#echo $fact
done
echo "Sum of factorials of $n terms of fibonacci seriesis $ans"
