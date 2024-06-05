from collections import deque
input = open(0).readline

slime_num = int(input())
slime = deque(sorted(list(map(int, input().split()))))
score = 0

for s in range(slime_num):
    if len(slime) >= 2:
        slime.append((a := slime.pop()) + (b := slime.pop()))
        score += a * b
print(score)