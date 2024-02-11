input = open(0).readline

def coin_kind():
    cnt = int(input())
    coins = tuple(map(int,input().split()))
    target = int(input())
    
    money = [0]*(target+1)
    
    for coin in coins:
        for pos in range(1, target+1):
            if coin == pos:
                money[pos] += 1
                continue
            
            money[pos] += money[pos-coin] if pos > coin else 0
            
    return money[-1]

for i in range(int(input())):
    print(coin_kind())