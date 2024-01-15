input = open(0).readline
import heapq as hp

N, M, K = map(int, input().split())

beer = []
HP = []; hp.heapify(HP)

for _ in range(K):
    l, a = map(int, input().split())
    beer.append((l, a))

beer.sort(key = lambda x: x[-1])
like = 0
ans = False

for i in beer:
    if len(HP) < N:
        hp.heappush(HP, i)
        like += i[0]
        if len(HP) == N:
            if like >= M:
                alcohol = i[1]
                ans = True
            else:
                b = hp.heappop(HP)
                like -= b[0]

print(alcohol if ans else -1)
