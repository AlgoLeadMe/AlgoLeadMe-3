n = input()
nlist = [0]*10
count = 0

for i in range(len(n)):
    num = int(n[i])
    if (num==6 or num==9):
        count += 1
        if count%2==1:
            nlist[6] += 1
    else:
        nlist[num] += 1

print(max(nlist))