import sys
input = sys.stdin.readline

n = int(input())
expected_rank = []
ans = 0

for _ in range(n):
  expected_rank.append(int(input()))

expected_rank.sort()

for i in range(n):
  ans += abs(expected_rank[i] - (i+1))

print(ans)