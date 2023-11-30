from collections import deque
input = open(0).readline
student = []; numList = []

N = int(input())
for n in range(N):
    numList.append(list(input().split()))
    student.append(numList[n][0])

num = 0
student = deque(student)
while len(student) > 1:
    for i in range(N):
        if numList[i][0] == student[0]:
            num = int(numList[i][1])
            break
        else:
            continue

    if num >= (len(student)-1):
        order = num % (len(student)-1)
        if order == 0:
            student.pop(); student.popleft()
        else:
            student.remove(student[order]); student.popleft()
            student.rotate((order-1)*(-1))
    else:
        order = num
        student.remove(student[order]); student.popleft()
        student.rotate((order - 1) * (-1))

print(student[0])