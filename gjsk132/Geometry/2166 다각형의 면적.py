input = open(0).readline

polygon = 0

point = int(input())
xy = [tuple(map(int, input().split())) for _ in range(point)]

for i in range(point):
    polygon += xy[i][0]*xy[i-1][1] - xy[i][1]*xy[i-1][0]

print(round(abs(polygon)/2 ,1))