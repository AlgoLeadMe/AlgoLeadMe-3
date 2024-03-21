input = open(0).readline

N = int(input())
cards = list(map(int, input().split()))
dp = [1] + [0] * (N - 1)

for i in range(1, N):
    MAX = 0
    for j in range(i):
        if cards[j] < cards[i]:
            MAX = max(MAX, dp[j])
        dp[i] = MAX + 1

print(max(dp))