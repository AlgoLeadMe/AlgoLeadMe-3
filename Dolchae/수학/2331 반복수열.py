input_ = open(0).readline()
first, multiple = map(int, input_.split())
list = []

def repeated(n):
    num=0
    for i in [int(digit) for digit in str(n)]:
        i = int(i)
        num += i ** multiple
    if num in list:
        print(list.index(num))
        exit(0)
    list.append(num)
    repeated(num)

list.append(first)
repeated(first)