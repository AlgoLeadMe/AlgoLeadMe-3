from heapq import heappush, heappop, heapify
def solution(scoville, K):
    answer = 0
    heapify(scoville)
    while True:
        spicy = 0
        if scoville[0] >= K:
            return answer
            break
        elif scoville[0] < K and len(scoville) >= 2:
            spicy += heappop(scoville) + heappop(scoville) * 2
            heappush(scoville, spicy)
            answer += 1
        else:
            return -1