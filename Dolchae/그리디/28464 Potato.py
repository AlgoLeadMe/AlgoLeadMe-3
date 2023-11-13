from sys import stdin
n = int(stdin.readline())
park = 0
sw = 0

potato = list(map(int, stdin.readline().split(" ")))
potato.sort()
park_count = n-1
sw_count = 0

for i in range(n):
    if i%2==0:
        park += potato[park_count]
        park_count -= 1

    else:
        sw += potato[sw_count]
        sw_count += 1

print(sw, park)