def sort(nList):
    for i in range(len(nList)):
        nList[i] = str(nList[i])
    
    nList.sort(reverse = True)
    
    for j in range(len(nList)-1):
        if nList[j][0] == nList[j+1][0]:
            a = nList[j] * 3; b = nList[j+1] * 3
            if a[:3] < b[:3]:
                temp = nList[j+1]
                nList[j+1] = nList[j]
                nList[j] = temp
    
    return nList

def solution(numbers):
    sort(numbers)

    return "".join(numbers)