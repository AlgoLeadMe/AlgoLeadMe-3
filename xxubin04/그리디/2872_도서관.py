input = open(0).readline

num = int(input())
books = list(int(input()) for _ in range(num))

cnt = 0
std = num
for i in reversed(books):
    if i != std:
        cnt += 1
    else:
        std -= 1
print(cnt)