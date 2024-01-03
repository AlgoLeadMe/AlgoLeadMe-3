import sys
sys.setrecursionlimit(10**6)

input = open(0).readline
size = int(input())
area = [list(input().strip()) for i in range(size)]
blind = [['G' if j=='R' else j for j in i] for i in area]

def bfs(x, y, color):
    area[x][y] = 'X'
    for dx, dy in zip([-1,0,1,0],[0,1,0,-1]):
        nx = x+dx
        ny = y+dy
        if nx < 0 or ny < 0 or nx == size or ny == size:
            continue
        if not area[nx][ny] == color:
            continue
        bfs(nx,ny,color)
        
def findarea():
    cnt = 0
    for i in range(size):
        for j in range(size):
            if area[i][j] == 'X':
                continue
            cnt += 1
            bfs(i,j,area[i][j])
    print(cnt, end=" ")
    
findarea()
area = blind
findarea()