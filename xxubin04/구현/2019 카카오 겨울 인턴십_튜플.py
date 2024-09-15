def solution(s):
    answer = []
    a, i = 2, 1
    nums = []
    for i in range(2, len(s)-1):
        if s[i] == '}':
            nums.append(s[a:i].split(","))
            a = i + 3
            i += 2
    for n in sorted(nums, key=lambda x: len(x)):
        for m in n:
            if not int(m) in answer:
                answer.append(int(m))
    return answer