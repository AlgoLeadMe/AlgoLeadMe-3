from sys import stdin

N, M = map(int, stdin.readline().split())
dic1 = {}; dic2 = {}

for i in range(1, N+1):
    n = stdin.readline().strip()
    dic1[i] = n
    dic2[n] = str(i)

for j in range(M):
    m = stdin.readline().strip()
    if m.isdigit() == True:
        print(dic1[int(m)])
    else:
        print(dic2[m])