from collections import deque

input = open(0).readline

row, col = map(int, input().split())
boxes = []

for i in range(col):
    boxes.append(list(map(int, input().split())))
    
deq = deque()

for i in range(col):
    for j in range(row):
        if boxes[i][j] == 1:
            deq.append([i,j])
            boxes[i][j] = 2
            
dy = [1,0,-1,0]
dx = [0,1,0,-1]

day = -1

while len(deq) != 0:
    
    day += 1
    
    for i in range(len(deq)):    
        pos = deq.popleft()
        
        for x, y in zip(dx, dy):
            ny = pos[0] + y
            nx = pos[1] + x
            
            if ny < 0 or ny == col or nx < 0 or nx == row:
                continue
            if boxes[ny][nx] == 0:
                deq.append([ny, nx])
                boxes[ny][nx] = 2 

is_raw = False

for i in boxes:
    for j in i:
        if j == 0:
            is_raw = True
            break;

print(-1 if is_raw else day)