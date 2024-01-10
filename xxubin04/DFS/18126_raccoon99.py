input = open(0).readline

N = int(input())
route = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]
dist = [0 for _ in range(N + 1)]
num = 1

def dfs(x):
    visited[x] = 1
    for k in range(len(route[x])):
        place = route[x][k][0]
        if not visited[place]:
            dist[place] = route[x][k][1] + dist[x]
            dfs(place)

for i in range(N - 1):
    A, B, C = map(int, input().split())
    route[A].append([B, C])
    route[B].append([A, C])

dfs(num)
print(max(dist))