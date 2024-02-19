input = open(0).readline

tree_num, length = map(int, input().split())
trees = sorted(list(map(int, input().split())))

def binary_search(target, trees):
    start = 0
    end = trees[-1]

    while start <= end:
        mid = (start + end) // 2
        cutted_trees = 0

        for i in trees:
            if (i - mid) >= 0:
                cutted_trees += (i - mid)

        if cutted_trees == target:
            return mid
        elif cutted_trees > target:
            start = mid + 1
        else:
            end = mid - 1

    if cutted_trees >= target:
        ans = mid
    else:
        ans = mid - 1

    return ans


print(binary_search(length, trees))