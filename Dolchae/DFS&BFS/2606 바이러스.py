import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
ans = 0
computers = [[] for _ in range(n+1)]

for _ in range(m):
    x, y = map(int, input().split())
    computers[x].append(y)
    computers[y].append(x)

visited = [False] * (n + 1)
stack = [1]
while stack:
    node = stack.pop()
    visited[node] = True

    for neighbor in computers[node]:
        if not visited[neighbor]:
            visited[neighbor] = True
            stack.append(neighbor)
    ans += 1

print(ans-1)