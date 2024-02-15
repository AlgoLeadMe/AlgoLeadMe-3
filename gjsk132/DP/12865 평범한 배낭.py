input = open(0).readline

loads, bag = map(int,input().split())

dp = [[s for i in range(bag+1)] for s in range(2)]

for step in range(1, loads+1):
    kg, value = map(int,input().split())
    sp = step%2
    
    for p in range(bag+1):
        dp[sp][p] = max(dp[sp-1][p], dp[sp-1][p-kg]+value if p >=kg else 0)

print(dp[loads%2][-1])