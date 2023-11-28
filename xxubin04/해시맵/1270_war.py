from sys import stdin

n = int(stdin.readline())
for _ in range(n):
    soldier = {}
    line = stdin.readline().split()
    N = int(line[0])
    max_val = 0
    max_key = 0
    for i in range(1, len(line)):
        num = int(line[i])
        if num not in soldier:
            soldier[num] = 1
        else:
            soldier[num] += 1
            if soldier[num] > max_val:
                max_val = soldier[num]
                max_key = num
    if max_val > N * 0.5:
        print(max_key)
    else:
        print("SYJKGW")