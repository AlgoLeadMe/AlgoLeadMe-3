from sys import stdin

dic = {'H':1, 'C':12, 'O':16}
chemList = list(stdin.readline().rstrip())

div = []; box = []
for j in chemList:
    total = 0
    if j == '(':
        div.append(j)
    elif j in dic:
        div.append(dic[j])
    elif j == ')':
        while True:
            n = div.pop()
            if n == '(':
                break
            total += n
        if total != 0:
            div.append(total)
    else:
        num = div.pop(-1) * int(j)
        div.append(num)

print(sum(div))