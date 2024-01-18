input = open(0).readline

col, row = map(int, input().split())
array = []

for _ in range(col):
    array.append(list(map(int, input().split())))

for c in range(col):
    for r in range(row):
        if c == 0 and r == 0:
            continue
        elif c == 0 and r > 0:
            if array[c][r] == 1:
                array[c][r] = array[c][r-1] + 1
            else:
                array[c][r] = array[c][r-1]
        elif c > 0 and r == 0:
            if array[c][r] == 1:
                array[c][r] = array[c-1][r] + 1
            else:
                array[c][r] = array[c-1][r]
        else:
            if array[c][r] == 1:
                array[c][r] += max(array[c][r-1], array[c-1][r])
            else:
                array[c][r] = max(array[c][r-1], array[c-1][r])

print(array[col-1][row-1])