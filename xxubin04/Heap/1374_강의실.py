import heapq
input = open(0).readline

ans = 0
time_table = []

for i in range(N := int(input())):
    num, start, end = map(int, input().split())
    time_table.append((start, end))

time_table.sort()
end_times = []

for start, end in time_table:
    while end_times and end_times[0] <= start:
        heapq.heappop(end_times)
    heapq.heappush(end_times, end)
    ans = max(ans, len(end_times))

print(ans)