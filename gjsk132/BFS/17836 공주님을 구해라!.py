from collections import deque
input = open("input.txt").readline

h, w , limit = map(int,input().split())

maze = [list(map(int, input().split())) for _ in range(h)]

offset = [(0, 1), (1, 0), (0, -1), (-1, 0)]

dq = deque([(0, 0)])
maze[0][0] = -1

sword_px, sword_py = -1, -1

while dq:
    px, py = dq.popleft()

    for dx, dy in offset:
        nx = px + dx
        ny = py + dy

        if nx < 0 or nx == h or ny < 0 or ny == w or maze[nx][ny] < 0 or maze[nx][ny] == 1:
            continue

        if maze[nx][ny] == 2:
            sword_px, sword_py = nx, ny
        
        maze[nx][ny] = maze[px][py] - 1
        dq.append((nx, ny))

not_sword_dist = maze[0][0] - maze[-1][-1]
sword_dist = -1

if not sword_px == -1:
    sword_dist = maze[0][0] - maze[sword_px][sword_py] + h + w - sword_px - sword_py - 2

if sword_dist <= 0 and not_sword_dist <= 0:
    print("Fail")
elif sword_dist <= 0:
    if not_sword_dist > limit:
        print("Fail")
    else:
        print(not_sword_dist)
elif not_sword_dist <= 0:
    if sword_dist > limit:
        print("Fail")
    else:   
        print(sword_dist)
else:
    result = min(sword_dist, not_sword_dist)
    if result > limit:
        print("Fail")
    else:
        print(result)