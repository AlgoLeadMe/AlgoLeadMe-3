from sys import stdin

test = int(stdin.readline())
for _ in range(test):
    A_num, B_num = map(int, stdin.readline().split())
    A = list(map(int, stdin.readline().split()))
    B = list(map(int, stdin.readline().split()))
    A.sort()
    B.sort()
    pair = 0
    B_index = 0

    for a in A:
        while B_index < B_num and B[B_index] < a:
            B_index += 1
        pair += B_index

    print(pair)