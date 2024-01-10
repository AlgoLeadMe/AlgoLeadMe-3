import sys
countSwitch = int(sys.stdin.readline())
switches = list(sys.stdin.readline().split())
students = int(sys.stdin.readline())
for _ in range(students):
    studentState = (list(map(int, sys.stdin.readline().split())))
    now = studentState[1]
    if studentState[0] == 1:
        for i in range(now-1, countSwitch, now):
            if switches[i] == '1':
                switches[i] = '0'
            else:
                switches[i] = '1'
    else:
        i = 0
        while(now-i-1 >= 0 and now+i-1 < countSwitch):
            if switches[now-i-1] == switches[now+i-1]:
                if switches[now-i-1] == '1':
                    switches[now-i-1] = '0'
                    switches[now+i-1] = '0'
                else:
                    switches[now-i-1] = '1'
                    switches[now+i-1] = '1'
                i += 1
            else:
                break
count = 0
for switch in switches:
    if(count % 20 == 0 and count != 0):
        print()
    print(int(switch), end=" ")
    count += 1