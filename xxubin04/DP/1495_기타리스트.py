input = open(0).readline

num, start, maximum = map(int, input().split())
volumes = list(map(int, input().split()))
dp = [[0]*(maximum+1) for _ in range(num+1)]
dp[0][start] = 1

for i in range(num):
    for j in range(maximum+1):
        if dp[i][j] == 1:
            if 0 <= j-volumes[i] <= maximum:
                dp[i+1][j-volumes[i]] = 1
            if 0 <= j+volumes[i] <= maximum:
                dp[i+1][j+volumes[i]] = 1
for k in range(maximum, -1, -1):
    if dp[num][k] != 0:
        print(k)
        break
    elif k == 0:
        print(-1)