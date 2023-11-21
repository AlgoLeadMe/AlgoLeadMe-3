from queue import Queue

input = open(0).readline
t = int(input())

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

for i in range(t):
        
    # field 정보 & 심어진 배추 위치
    m, n, k = map(int,input().split())
    field = [[0 for _ in range(n)] for _ in range(m)]
    
    for j in range(k):
        col, row = map(int, input().split())
        field[col][row] = 1
    
    cnt = 0
    que = Queue()
    
    for y in range(m):
        for x in range(n):
            if field[y][x] == 1:
                cnt+=1
                que.put([y,x])
                field[y][x] = 2
                
                while not que.empty():
                    p = que.get()
                    for y_,x_ in zip(dy, dx):
                        ny = y_ + p[0]
                        nx = x_ + p[1]
                        if nx < 0 or nx == n or ny <0 or ny == m:
                            continue
                        if field[ny][nx]==1:
                            que.put([ny,nx])
                            field[ny][nx] = 2
    
    print(cnt)