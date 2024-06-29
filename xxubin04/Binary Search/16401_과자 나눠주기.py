input = open(0).readline

nephew, cookie = map(int, input().split())
cookie_length = sorted(list(map(int, input().split())))

start = 1
end = cookie_length[-1]

while start <= end:
    count = 0
    mid = (start + end) // 2
    for c in cookie_length:
        count += c // mid
    if count >= nephew:
        start = mid + 1
    else:
        end = mid-1

print(end)
