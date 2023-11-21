from sys import stdin

score = 0; stack = []

N = int(stdin.readline())
for n in range(N):
    aList = list(map(int, stdin.readline().split()))
    if aList[0] == 1:
        if aList[2] == 1:
            score += aList[1]
            aList.pop()
        else:
            aList[2] -= 1
            stack.append(aList)
    else:
        if not stack:
            pass
        else:
            if stack[-1][2] == 1:
                score += stack[-1][1]
                stack.pop(-1)
            else:
                stack[-1][2] -= 1
print(score)