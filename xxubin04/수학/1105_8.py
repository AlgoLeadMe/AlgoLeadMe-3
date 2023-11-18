from sys import stdin

L, R = stdin.readline().split()
List_L = list(L); List_R = list(R)
cnt = 0

if len(List_L) != len(List_R):
    print(0)
else:
    for j in range(len(List_R)):
        if List_L[j] == List_R[j]:
            if List_L[j] == '8':
                cnt += 1
        else:
            break
    print(cnt)