input = open(0).readline

cannel = []

target = int(input())

limit = target*2 + 100

upDown = target - 100 if target > 100 else 100 - target

cnt = 0

if (brokenCnt := int(input())):
    broken = list(map(str,input().split()))

    for i in range(limit):
        cannel.append(False if any(b in str(i) for b in broken) else True)

    while cnt < upDown:
        
        if (cannel[target-cnt] if target>=cnt else False):
            cnt += len(str(target-cnt))
            break
        
        if (cannel[target+cnt] if target+cnt < limit else False):
            cnt += len(str(target+cnt))
            break
        
        cnt += 1
else:
    cnt += len(str(target))
            
print(min(cnt, upDown))