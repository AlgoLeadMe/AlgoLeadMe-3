input = open(0).readline

eq_sub = list(input().split('-'))

result = sum(list(map(int,eq_sub[0].split('+'))))

for i in eq_sub[1:]:
    result -= sum(list(map(int,i.split('+'))))

print(result)