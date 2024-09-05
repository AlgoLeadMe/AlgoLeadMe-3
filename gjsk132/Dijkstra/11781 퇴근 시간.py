from heapq import *
input = open(0).readline

nodes, links, jam_start, jam_end = map(int,input().split())

jam_start *= 2
jam_end *= 2

board = [[] for _ in range(nodes+1)]
dist = [float('inf')]*(nodes+1)

for _ in range(links):
    s_node, e_node, w, s_to_e, e_to_s = map(int,input().split())

    heappush(board[s_node], (e_node, 2*w, s_to_e))
    heappush(board[e_node], (s_node, 2*w, e_to_s))

dist[1] = 0

dq = [(0, 1)]

while dq:
    now_t, now_node = heappop(dq)
    
    for next_node, w, isjam in board[now_node]:
        if isjam and jam_start < now_t + w and jam_end > now_t:
            
            traffic_jam_start = max(now_t, jam_start)

            if 2*(now_t + w - traffic_jam_start) < (jam_end - traffic_jam_start):
                w += (now_t + w - traffic_jam_start)
            else:
                w += (jam_end - traffic_jam_start)//2
        
        if dist[next_node] <= now_t + w:
            continue
        
        dist[next_node] = now_t + w

        heappush(dq, (now_t+w, next_node))

result = max(dist[1:])
print(result/2 if result%2 else result//2)