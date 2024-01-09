from collections import deque

input = open(0).readline
n, m = map(int, input().split())

maze = [[int(j) for j in input().strip()] for i in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

queue = deque([(0, 0, 2)])
maze[0][0] = 2

while queue:
    x, y, dist = queue.popleft()

    for x_, y_ in zip(dx, dy):
        nx, ny = x + x_, y + y_

        if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] == 1:
            queue.append((nx, ny, dist + 1))
            maze[nx][ny] = dist + 1

print(maze[n-1][m-1] - 1)