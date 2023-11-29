target = int(open(0).readline())
dp = [1000001 for _ in range(1000001)]
dp[0] = 1000001
dp[1] = 0

i = 2

for i in range(2, target+1):
    dp[i] = min(dp[i//3] if i%3 == 0 else 100001, dp[i//2] if not i%2 else 10001, dp[i-1])+1

print(dp[target])