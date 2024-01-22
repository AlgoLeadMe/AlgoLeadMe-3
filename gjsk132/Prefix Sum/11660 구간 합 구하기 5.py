input = open(0).readline

size, order = map(int,input().split())

table = [[0]*(size+1)]+[[0]+list(map(int,input().split())) for i in range(size)]


for i in range(size):

    for j in range(size):
        table[i+1][j+1] += table[i+1][j]

    for j in range(size):
        table[i+1][j+1] += table[i][j+1]


for i in range(order):
    x1, y1, x2, y2 = map(int,input().split())
    print(table[x2][y2]+table[x1-1][y1-1]-table[x2][y1-1]-table[x1-1][y2])