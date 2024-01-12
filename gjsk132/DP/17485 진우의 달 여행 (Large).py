input = open(0).readline
N, M = map(int,input().split())
dp = [[[i]*3 for i in map(int,input().split())] for _ in range(N)]

for i in range(0, N-1):
    for j in range(M):
        before = dp[i]
        dp[i+1][j][-1] = 10**7 if j==M-1 else ( dp[i+1][j][-1] + min(before[j][0], before[j+1][1]) )
        dp[i+1][j][0] += min(10**7 if j==0 else before[j-1][-1], 10**7 if j==M-1 else before[j+1][1])
        dp[i+1][j][1] = 10**7 if j==0 else ( dp[i+1][j][1] + min(before[j-1][-1], before[j][0]) )

low = 10**7

for i in dp[N-1]:
    low = min(low, min(i))

print(low)