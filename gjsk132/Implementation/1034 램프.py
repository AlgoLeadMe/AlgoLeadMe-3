from collections import defaultdict

input = open(0).readline

n, m = map(int,input().split())

answer = 0

table = defaultdict(int)

for _ in range(n):
    row = input().rstrip()
    table[row] += 1
    
turn_on_off_cnt = int(input())

table = list(table.items())
table.sort(key=lambda x: -x[1])

for row, cnt in table:
    need_switch_on = m - sum(list(map(int,row)))
    
    if turn_on_off_cnt < need_switch_on:
        continue
    
    if (turn_on_off_cnt - need_switch_on)%2==1:
        continue
    
    answer = cnt
    break

print(answer)