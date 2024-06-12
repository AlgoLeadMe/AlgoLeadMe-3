input = open(0).readline

order, wok_cnt = map(int,input().split())
one_wok = list(map(int,input().split()))
second_wok = []

for i in range(wok_cnt):
    for j in range(i+1, wok_cnt):
        second_wok.append(one_wok[i]+one_wok[j])

cook_cnt = set(one_wok + second_wok)

memo = [float('inf')]*(order+1)
memo[0] = 0

for i in range(order):
    for c in cook_cnt:
        if i+c > order:
            continue
        memo[i+c] = min(memo[i+c], memo[i]+1)

print(-1 if memo[-1]==float('inf') else memo[-1])