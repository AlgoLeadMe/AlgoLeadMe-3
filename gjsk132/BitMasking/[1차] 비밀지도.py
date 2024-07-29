def solution(n, arr1, arr2):
    answer = [bin(elem1|elem2)[2:] for elem1, elem2 in zip(arr1, arr2) ]
    
    for i in range(n):
        answer[i] = answer[i].replace("1","#").replace("0"," ")
        
        if (long := len(answer[i])) < n:
            answer[i] = " "*(n-long) + answer[i]
            
    return answer