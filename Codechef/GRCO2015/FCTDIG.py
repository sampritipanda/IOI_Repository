# Digits in Factorial

import math

arr = [0.0]
for i in range(1, 25000 + 1):
	arr.append(math.log10(i) + arr[i - 1])
arr[0] = 1.0
arr[1] = 1.0

T = input()

while T > 0:
	n = input()
	print " ".join([str(int(math.ceil(arr[i]))) for i in map(int, raw_input().split())])
	T -= 1