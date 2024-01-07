import sys
sys.setrecursionlimit(10**7)
input = open(0).readline

col, row, num = map(int, input().split())
array = [[0]*(row) for _ in range(col)]
visited = [[False]*(row) for _ in range(col)]
trashList = []; ans = 0

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

for _ in range(num):
    c, r = map(int, input().split())
    trashList.append([c,r])
    array[c-1][r-1] = 1

def DFS(x, y):
    global cnt
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < col and 0 <= ny < row:
            if array[nx][ny] == 1 and not visited[nx][ny]:
                cnt += 1
                visited[nx][ny] = True
                DFS(nx, ny)

for a, b in trashList:
    if not visited[a-1][b-1]:
        cnt = 0
        DFS(a-1, b-1)
        ans = max(ans, cnt)
    else:
        pass

print(ans)