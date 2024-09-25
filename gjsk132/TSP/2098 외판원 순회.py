input = open(0).readline

N = int(input())

cost = [list(map(int, input().split())) for _ in range(N)]

INF = float('inf')
dp = [[0]*((1 << N) - 1) for _ in range(N)]

def DFS(now, visited):
    if visited == (1<<N)-1:
        if cost[now][0]:        
            return cost[now][0]
        else:
            return INF
    
    if dp[now][visited] != 0:
        return dp[now][visited]

    dp[now][visited] = INF

    for i in range(1, N):
        if cost[now][i] == 0:
            continue
        if visited & (1<<i):
            continue
        dp[now][visited] = min(dp[now][visited], cost[now][i]+DFS(i,visited | (1<<i)))

    return dp[now][visited]

print(DFS(0,1))