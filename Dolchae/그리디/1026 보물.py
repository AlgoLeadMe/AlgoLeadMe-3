n = int(input())
s = 0
a = list(map(int,input().split()))
b = list(map(int,input().split()))

a.sort()
b.sort()
b.reverse()

for i in range(n):
    s += a[i]*b[i]
print(s)