n = int(input())
stack = []
ans = []
cur = 1
k=1
for _ in range(n):
    input_num = int(input())
    while cur <= input_num:
        stack.append(cur)
        ans.append("+")
        cur += 1

    if stack[-1] == input_num:
        stack.pop()
        ans.append("-")
    else:
        k = 0
if k==1:
    for i in ans:
        print(i)
else:
    print("NO")