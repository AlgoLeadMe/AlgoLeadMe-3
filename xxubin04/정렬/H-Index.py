def solution(citations):
    answer = ""
    citations.sort(reverse=True)
    for i in range(len(citations)):
        if citations[i] >= i + 1:
            answer = i + 1
        else:
            break
    return answer if answer != "" else 0