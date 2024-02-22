input = open(0).readline

days, tteok_num = map(int, input().split())

for i in range(1, tteok_num):
    for j in range(i, tteok_num):
        a = i; b = j
        for k in range(2, days):
            temp = a + b
            a = b
            b = temp

        if temp == tteok_num:
            print(f"{i}\n{j}")
            exit()