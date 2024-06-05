from itertools import combinations
input = open(0).readline

while (numComb := list(map(int, input().split()))) != [0]:
    for i in combinations(numComb[1:], 6):
        print(" " .join(str(j) for j in list(i)))
    print()