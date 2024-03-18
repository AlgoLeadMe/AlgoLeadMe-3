input = open(0).readline

pool_cnt, plank_len = map(int,input().split())

can_go = 0

pools = [tuple(map(int,input().split())) for _ in range(pool_cnt)]

pools = sorted(pools, key=lambda x: x)

plank_cnt = 0

for s, e in pools:
    tmp = 0
    
    can_go = max(can_go, s)
    e -= can_go
    tmp += e//plank_len
    
    if e%plank_len:
        tmp += 1
    
    can_go += tmp*plank_len
    plank_cnt += tmp
        
print(plank_cnt)