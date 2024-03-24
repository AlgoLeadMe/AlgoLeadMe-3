import sys
from itertools import combinations

input = sys.stdin.readline

n, target = map(int,input().split())
num_list = list(map(int,input().split()))
ans = 0

for i in range(1,n+1):
  now_list = list(combinations(num_list,i))
  for j in range(len(now_list)):
    now = sum(now_list[j])
    if now == target:
      ans += 1

print(ans)