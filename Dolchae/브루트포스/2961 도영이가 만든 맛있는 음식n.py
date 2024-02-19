import sys
from itertools import combinations
input = sys.stdin.readline

n = int(input())

ingrid = [[0 for _ in range(2)] for _ in range(n)]
for i in range(n):
    ingrid[i][0],ingrid[i][1] = map(int,input().split())

ans = abs(ingrid[0][0] - ingrid[0][1])
for i in range(1,n+1): #1
    for comb in combinations(ingrid,i): #2
        print(comb)
        sour, bitter = 1,0
        for j in range(i): #3
            sour *= comb[j][0]
            bitter += comb[j][1]
        now_diff = abs(sour-bitter)
        if now_diff < ans: 
            ans = now_diff

print(ans)
