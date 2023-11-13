from sys import stdin

# aList = [[0] for _ in range(7)]
stack = [[] for _ in range(7)]
num = 0

a, b = map(int, stdin.readline().split())

for i in range(a):
    line, pret = map(int, stdin.readline().split())
    # stack.append([line, pret])
    if not stack[line]:
        stack[line].append(pret)
        num += 1
    else:
        for j in range(len(stack[line])):
            if stack[line][-1] > pret:    # 이미 큰 프렛 존재
                stack[line].pop(-1)
                num += 1
                if not stack[line]:
                    stack[line].append(pret)
                    num += 1
            elif stack[line][-1] == pret: # 같은 프렛 존재
                continue
            else:                         # 작은 프렛 존재
                stack[line].append(pret)
                num += 1
print(num)
