from math import floor

def solution(str1, str2):
    answer = 0
    list1, list2 = [], []
    for a in range(len(str1)-1):
        if (slice_a := str1[a:a+2]).isalpha():
            list1.append(str1[a:a+2].upper())
    for b in range(len(str2)-1):
        if (slice_b := str2[b:b+2]).isalpha():
            list2.append(str2[b:b+2].upper())

    total = len(list1) + len(list2)
    duplication = 0

    for i in list1:
        if i in list2:
            list2.remove(i)
            duplication += 1

    if len(list2) == 0 or total == duplication:
        return 65536

    answer = floor(duplication / (total - duplication) * 65536)

    return answer