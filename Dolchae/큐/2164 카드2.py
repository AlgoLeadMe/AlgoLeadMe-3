from collections import deque

card = int(input())
card_list = deque(i+1 for i in range(card))


while len(card_list)>1:
    card_list.popleft()
    rest = card_list.popleft()
    card_list.append(rest)

print(card_list[0])