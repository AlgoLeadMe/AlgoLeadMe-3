from collections import deque

input = open(0).readline

height, width = map(int,input().split())
paint = [list(map(int, input().split())) for _ in range(height)]

def bfs(graph,a,b):
    queue = deque()
    queue.append((a,b))
    graph[a][b] = 0
    count = 1

    while queue:
        x,y = queue.popleft()
        for dx,dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = x+dx, y+dy

            if nx<0 or nx>=height or ny<0 or ny >= width:
                continue

            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
                count += 1

    return count


ans = []
for i in range(height):
    for j in range(width):
        if paint[i][j] == 1:
            ans.append(bfs(paint,i,j))

if len(ans) == 0:
    print(0)
    print(0)
else:
    print(len(ans))
    print(max(ans))

