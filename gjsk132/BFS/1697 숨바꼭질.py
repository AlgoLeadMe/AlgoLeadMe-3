from collections import deque
input = open(0).readline
s, e = map(int,input().split())

limit = 100001

check = [-1 for _ in range(limit)]

dq = deque([s])
check[s] = 0

while check[e] == -1:
    point = dq.popleft()
    
    for i in [ 1, -1, point ]:
        np = point+i
        
        if np < 0 or np >= limit or check[np] != -1:
            continue
        
        check[np] = check[point] + 1
        dq.append(np)
        
print(check[e])