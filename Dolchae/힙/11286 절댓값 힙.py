import sys
import heapq

input = sys.stdin.readline

heap = []
for _ in range(n := int(input())):
    now = int(input())
    if now == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (abs(now),now))
