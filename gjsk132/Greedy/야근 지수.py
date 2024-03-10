from heapq import *

def solution(n, works):
    
    if n >= sum(works):
        return 0
    
    works = [-w for w in works]
    
    heapify(works)
    
    while n:
        if (w := heappop(works)) == 0:
            continue
        heappush(works, w+1)
        n -= 1
    
    return sum([w**2 for w in works])