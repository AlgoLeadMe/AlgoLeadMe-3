from heapq import heapify, heappush, heappop
input = open(0).readline 

num = []
total = 0
heapify(num)
for i in range(n := int(input())):
    heappush(num, int(input()))

while len(num) != 1:
    total += (current_mix := heappop(num) + heappop(num))
    heappush(num, current_mix)

print(total) 