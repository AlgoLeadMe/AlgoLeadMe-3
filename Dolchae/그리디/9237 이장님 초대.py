input = open(0).readline

tree_num = int(input())
tree_list = list(map(int, input().split()))
tree_list.sort(reverse=True)
ans = 0

for i in range(tree_num):
    if ans < tree_list[i]+i+1:
        ans = tree_list[i]+i+1

print(ans+1)