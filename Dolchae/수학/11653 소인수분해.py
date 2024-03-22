n = int(input())

for i in range(2, n+1):
    while True:
        if not n%i == 0:
            break
        print(i)
        n /= i