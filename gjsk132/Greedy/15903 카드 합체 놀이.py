import heapq as hp

input = open(0).readline

card_cnt, merge_cnt = map(int, input().split())

card_num = list(map(int,input().split()))

hp.heapify(card_num)

for i in range(merge_cnt):
    
    a, b = hp.heappop(card_num), hp.heappop(card_num)
    hp.heappush(card_num, a+b)
    hp.heappush(card_num, a+b)

print(sum(card_num))