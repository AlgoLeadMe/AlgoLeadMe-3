import sys
import heapq

input = sys.stdin.readline

n = int(input())
heap_que = []

for _ in range(n):
    now = int(input())
    if now == 0:
        if len(heap_que)==0:
            print(0)
        else:
            print(heapq.heappop(heap_que))
    else:
        heapq.heappush(heap_que,now)