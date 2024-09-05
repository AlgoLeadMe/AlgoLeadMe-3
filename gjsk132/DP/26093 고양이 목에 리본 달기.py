input = open(0).readline

cat, ribbon = map(int,input().split())

dp = [0*ribbon] + [list(map(int,input().split()))]

for cnt in range(cat-1):

    max_first, mf_idx = 0, 0
    max_second = -1

    dp[cnt%2] = list(map(int,input().split()))

    for idx, perf in enumerate(dp[cnt%2-1]):
        if max_first < perf:
            max_second = max_first
            mf_idx = idx
            max_first = perf
        elif max_second < perf:
            max_second = perf
    
    for idx in range(ribbon):
        dp[cnt%2][idx] += max_first if idx != mf_idx else max_second

print(max(dp[cat%2]))