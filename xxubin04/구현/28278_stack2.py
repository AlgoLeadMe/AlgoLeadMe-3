import sys

n = int(sys.stdin.readline())
stack = []

for i in range(n):
    num = sys.stdin.readline().split()

    if num[0] == "1":
        stack.append(num[-1])

    elif num[0] == "2":
        if len(stack) != 0:
            print(stack.pop(-1))
        else:
            print(-1)

    elif num[0] == "3":
        print(len(stack))

    elif num[0] == "4":
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    elif num[0] == "5":
        if len(stack) != 0:
            print(stack[-1])
        else:
            print(-1)
    else:
        break