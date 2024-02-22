import sys

input = sys.stdin.readline

n, m = map(int, input().split())

money = []
for _ in range(n):
    money.append(int(input()))

start = max(money)
end = sum(money)

ans = 0
while start <= end:
    mid = (start + end) // 2

    total = 0
    cnt = 0
    for x in money:
        if total + x <= mid:
            total += x
        else:
            cnt += 1
            total = 0
            total += x
    if total:
        cnt += 1

    if cnt > m:
        start = mid + 1
    else:
        end = mid - 1
        ans = mid

print(ans)