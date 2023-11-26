from sys import stdin

total = 0
n = int(stdin.readline())
array = [[0] * 101 for _ in range(101)]

for i in range(n):
    x, y = map(int, stdin.readline().split())
    for row in range(x, x+10):
        for col in range(y, y+10):
            array[row][col] = 1

for j in array:
    total += sum(j)

print(total)