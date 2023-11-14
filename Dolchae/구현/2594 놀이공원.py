n = int(input())
ans = 0
times = []
end_max = 600

for i in range(n):
    n1, n2 = map(int,input().split())
    n1 = (n1 // 100) * 60 + n1 % 100 - 10
    n2 = (n2 // 100) * 60 + n2 % 100 + 10
    times.append([n1,n2])
times.sort()

for start,end in times:
    if ans < start - end_max:
        ans = start - end_max
    if end_max < end:
        end_max = end

if 1320 - end_max > ans:
    ans = 1320 - end_max
    
print(ans)

