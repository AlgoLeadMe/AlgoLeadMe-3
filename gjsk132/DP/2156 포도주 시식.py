input = open(0).readline

wine = int(input())
amount = [int(input()) for i in range(wine)]
total = sum(amount)

for i in range(3,wine):
    amount[i] += min(amount[i-1], amount[i-2], amount[i-3])
    
print(total if wine <= 2 else total-min(amount[-3:]))