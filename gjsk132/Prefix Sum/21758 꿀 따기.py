input = open(0).readline

place = int(input())
honey = list(map(int,input().split()))
total = sum(honey)

def side_beehive():
    honey_sum = [i for i in honey]

    for p in range(1, place):
        honey_sum[p] += honey_sum[p-1]
    
    return (total*2 - min([honey[i]+honey_sum[i] for i in range(1,place-1)]) - honey[0])

beehive = total - honey[-1] - honey[0] + max(honey)

beehive = max(beehive, side_beehive())
honey.reverse()
beehive = max(beehive, side_beehive())

print(beehive)