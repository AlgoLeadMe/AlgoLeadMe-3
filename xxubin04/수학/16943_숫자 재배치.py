from itertools import permutations

input = open(0).readline

A, B = input().split()
num_A = list(A)
perm_A = list(permutations(num_A, len(A)))

ans = -1
check = False
for i in perm_A:
    i_list = []
    for j in i:
        i_list.append(j)
    if i_list[0] == '0':
        continue

    if int(''.join(i_list)) < int(B):
        ans = max(ans, int(''.join(i_list)))

print(ans)