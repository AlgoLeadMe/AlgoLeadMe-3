input = open(0).readline

city, path_cnt = map(int,input().split())

path = [[] for _ in range(city+1)]

for i in range(path_cnt):
    start, end, cost = map(int,input().split())
    path[start].append((end, cost))
    
INF = float("inf")
costs = [INF for _ in range(city+1)]

costs[1] = 0

def check_all_line():
    for start in range(1, city+1):
        for end, cost in path[start]:
            if costs[start] == INF:
                continue
            
            costs[end] = min(costs[end], costs[start]+cost)

for _ in range(city-1):
    check_all_line()

save = [i for i in costs]

check_all_line()

if not save == costs:
    print(-1)
else:
    for c in costs[2:]:
        print(-1 if c == INF else c)