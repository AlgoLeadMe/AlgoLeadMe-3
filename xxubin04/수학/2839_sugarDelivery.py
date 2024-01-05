input = open(0).readline

kilo = int(input())
num = 0; ans = False

remain = kilo % 5
num += kilo // 5
if remain % 3 == 0:
    num += remain // 3
    print(num); ans = True
else:
    num = 0
    for i in range(kilo // 5, -1, -1):
        if (kilo - 5 * i) % 3 == 0:
            num = i + ((kilo - 5 * i) // 3); ans = True
            print(num)
            break
        else:
            pass

if ans == True:
    pass
else:
    print(-1)