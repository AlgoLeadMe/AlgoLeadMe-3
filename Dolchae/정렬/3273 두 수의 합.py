input_ = open(0).readline
num = int(input_())
nlist = list(map(int, input_().split()))
x = int(input_())
nlist.sort()

ans = 0
left = 0
right = num-1

while left < right:
    if nlist[left] + nlist[right] == x:
        ans += 1
        left += 1
    elif nlist[left] + nlist[right] < x:
        left += 1
    else:
        right -= 1
print(ans)