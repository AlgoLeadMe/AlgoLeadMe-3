n = int(input())
big_list = []

big_list = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    rank = 1
    for j in range(n):
        if big_list[i][0] < big_list[j][0] and big_list[i][1] < big_list[j][1]:
            rank += 1
    print(rank,end=" ")