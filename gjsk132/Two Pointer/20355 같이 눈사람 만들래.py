input = open(0).readline

n = int(input())

snow = sorted(list(map(int,input().split())))

min_gap_height = float("inf")

target = 0

def two_pointer(block1, block2):
    start, end = 0, n-1

    target = snow[s1] + snow[s2]

    min_gap = target

    while not start == end:
        if start == block1 or start == block2:
            start += 1
            continue
        
        if end == block1 or end == block2:
            end -= 1
            continue
        
        height = snow[start] + snow[end]

        min_gap = min(min_gap, abs(target-height))

        if height > target:
            end -= 1
        else:
            start += 1
    return min_gap


answer = snow[0] + snow[n-1]

for s1 in range(n-1):

    if not answer:
        break

    for s2 in range(s1+1, n):
        answer = min(answer, two_pointer(s1, s2))

        if not answer:
            break

print(answer)
