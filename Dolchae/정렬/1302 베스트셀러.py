import sys

input = sys.stdin.readline

n = int(input())
books = {}

for i in range(n):
    now = input()
    if now in books.keys():
        books[now] += 1
    else:
        books[now] = 1

max_value = max(books.values())
max_keys = [key for key, value in books.items() if value == max_value]
max_keys.sort()
print(max_keys[0])