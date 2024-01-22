from collections import deque

input = open(0).readline

map_size = int(input())
map_list = [list(map(int, (input().strip()))) for _ in range(map_size)]


def bfs(graph,a,b):
    queue = deque()
    queue.append((a,b))
    graph[a][b] = 0
    count = 1

    while queue:
        x,y = queue.popleft()
        for dx,dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = x+dx, y+dy

            if nx < 0 or nx >= map_size or ny < 0 or ny >= map_size:
                continue

            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
                count += 1

    return count


ans = []
for i in range(map_size):
    for j in range(map_size):
        if map_list[i][j] == 1:
            ans.append(bfs(map_list,i,j))

print(len(ans))
ans.sort()
for i in ans:
    print(i)