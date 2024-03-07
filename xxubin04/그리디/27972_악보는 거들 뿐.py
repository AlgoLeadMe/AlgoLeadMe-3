input = open(0).readline

ans = 1
n = int(input())
std_up, std_down, max_ans = 0, 0, 0
notes = list(map(int, input().split()))

for i in range(n - 1):
    if notes[i] > notes[i + 1] and std_up != 0:
        std_up += 1
    elif notes[i] > notes[i + 1] and std_up == 0:
        max_ans = max(std_down, max_ans)
        std_down = 0
        std_up = 1
    elif notes[i] < notes[i + 1] and std_down != 0:
        std_down += 1
    elif notes[i] < notes[i + 1] and std_down == 0:
        max_ans = max(std_up, max_ans)
        std_up = 0
        std_down = 1

max_ans = max(std_up, max_ans)
max_ans = max(std_down, max_ans)

print(max_ans + 1)