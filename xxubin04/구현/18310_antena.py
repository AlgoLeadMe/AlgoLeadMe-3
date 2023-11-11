import sys

N = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
a.sort()
mid = N//2
if N%2 == 0:
    print(a[mid-1])
else:
    print(a[mid])