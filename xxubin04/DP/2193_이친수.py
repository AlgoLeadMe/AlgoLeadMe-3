input = open(0).readline

dp = [1, 1] + [0] * 88
for i in range((N := int(input()))-2):
    dp[i+2] = dp[i] + dp[i+1]

print(dp[N-1])