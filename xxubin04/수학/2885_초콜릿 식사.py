input = open(0).readline

square = int(input())
size = 1
while size < square:
    size *= 2

i = size
cnt = 0

if square == size:
    print(size, 0)
else:
    while square != 0:
        if square >= i:
            square -= i
            i //= 2
            cnt += 1
        else:
            i //= 2
            cnt += 1
    print(size, cnt-1)