case = int(input())
for i in range(case):
    total = 0; multi = 1; dic = {}
    num = int(input())
    for j in range(num):
        cloth, kind = input().split()
        if kind in dic.keys():
            dic[kind] += 1
        else:
            dic[kind] = 1
    for k in dic.keys():
        multi *= (dic[k] + 1)
    total = multi - 1
    print(total)