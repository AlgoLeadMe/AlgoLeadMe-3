input = open(0).readline

home = int(input())

dp = [list(map(int,input().split())) for i in range(home)]

for i in range(1,home):
    dp[i][0] += min(dp[i-1][1], dp[i-1][2])
    dp[i][1] += min(dp[i-1][0], dp[i-1][2])
    dp[i][2] += min(dp[i-1][0], dp[i-1][1])
    
print(min(dp[-1]))