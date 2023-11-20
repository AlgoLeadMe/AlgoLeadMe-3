# open(0).readline == sys.stdin.readline
input = open(0).readline

switch = int(input())
status = list(map(int, input().split()))
people = int(input())

for i in range(people):
    gender, num = map(int, input().split())
    
    if gender == 1:
        for j in range(num, switch+1, num):
            if j == 0 : continue
            if status[j-1] : status[j-1] = 0
            else : status[j-1] = 1
        
    elif gender == 2:
        for j in range(min(num,switch-num+1)):
            if status[num+j-1] and status[num-j-1]:
                status[num+j-1] = 0
                status[num-j-1] = 0
            elif not status[num+j-1] and not status[num-j-1]:
                    status[num+j-1] = 1
                    status[num-j-1] = 1
            else:
                break
    
cnt = 0
for i in status[0:]:
    cnt += 1
    if cnt != 20:
        print(i, end=' ')    
    else:
        print(i)
        cnt = 0