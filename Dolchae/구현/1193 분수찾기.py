x = int(input())

num = 0
i=0
while x > i:
    x -= i
    i += 1

if i%2==0:
    a = x
    b = i-x+1

elif i%2==1:
    a = i-x+1
    b = x

print(f'{a}/{b}')
