input = open(0).readline

meet = sorted([list(map(int,input().split())) for i in range(int(input()))])

meet.sort(key=lambda a: a[1])

time, cnt = 0, 0

for start, end in meet:
    if start >= time:
        time = end
        cnt += 1

print(cnt)