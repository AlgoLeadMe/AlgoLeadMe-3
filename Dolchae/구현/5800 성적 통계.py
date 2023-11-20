x = int(input())

for i in range(x):
    score = list(map(int, input().split()))
    score = score[1:]
    score.sort(reverse=True)
    max_score = max(score)
    min_score = min(score)
    largest_gap = 0
    for j in range(len(score)-1):
        if largest_gap < score[j] - score[j+1]:
            largest_gap = score[j] - score[j+1]

    print(f"Class {i+1}")
    print(f"Max {max_score}, Min {min_score}, Largest gap {largest_gap}")
