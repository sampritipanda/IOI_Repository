# Representative Selection

from bisect import bisect_left

T = input()

while T > 0:
    N = input()
    arr = []
    for i in range(N):
        arr.append(raw_input())
    check = raw_input()
    pos = bisect_left(arr, check)
    print ("yes" if pos != N and arr[pos] == check else "no")

    T -= 1
