from sys import stdin

money = []; setList = []; singList = []
N, M = map(int, stdin.readline().split())
num = N // 6

for n in range(M):
    SET, SIN = map(int, stdin.readline().split())
    setList.append(SET); singList.append(SIN)
    if N % 6 != 0:
        money.append(SET * (num+1))
    else:
        money.append(SET * num)  
    money.append(SIN * N)
    money.append((SET * num) + SIN * (N-(num * 6)))

money.append((min(setList) * (num)) + min(singList) * (N-(num*6)))

print(min(money))