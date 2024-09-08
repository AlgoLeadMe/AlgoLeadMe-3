import sys
sys.setrecursionlimit(10**7)
input = open(0).readline

N, M = map(int, input().split())
campus = []
people = 0
visited = [[0 for _ in range(M)] for _ in range(N)]

def bfs(graph, node_x, node_y,  visited):
    global people
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    if not visited[node_x][node_y]:
        visited[node_x][node_y] = 1

        for d in range(4):
            nx = node_x + dx[d]
            ny = node_y + dy[d]
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny]:
                if campus[nx][ny] == "P":
                    people += 1
                    bfs(campus, nx, ny, visited)
                elif campus[nx][ny] == "O":
                    bfs(campus, nx, ny, visited)

for i in range(N):
    campus.append(row := list(input().rstrip()))
    if "I" in row:
        row_I = i

bfs(campus, row_I, campus[row_I].index("I"), visited)
print(people) if people else print("TT")