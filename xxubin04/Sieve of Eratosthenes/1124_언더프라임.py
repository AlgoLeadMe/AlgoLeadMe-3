input = open(0).readline

a, b = map(int, input().split())
primeCheck = [0, 0] + [1] * (b-1)
primes = []
for i in range(2, b+1):
    if primeCheck[i] == 0:
        continue

    for j in range(i*2, b+1, i):
        primeCheck[j] = 0
    primes.append(i)

ans = 0
for p in range(a, b+1):
    cnt = 0
    for k in primes:
        if p == 1:
            break

        while p % k == 0:
            p /= k
            cnt += 1
    if cnt in primes:
        ans += 1

print(ans)