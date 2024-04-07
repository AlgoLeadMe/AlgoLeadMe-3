input = open(0).readline

from collections import deque

def bellmanford(n)
    node_info[n] = 0
    for idx in range(1, node+1)
        for start in range(1, node+1)
            for (end, weight) in line_info[start]
                if node_info[end]  node_info[start]+ weight
                    node_info[end] = node_info[start] + weight
                    if idx == node
                        return True
    return False

for i in range(int(input()))
    node, undirected_line, directed_line = map(int,input().split())

    line_info = [[] for _ in range(node+1)]

    for i in range(undirected_line)
        node1, node2, weight = map(int,input().split())
        line_info[node1].append((node2, weight))
        line_info[node2].append((node1, weight))

    for i in range(directed_line)
        start, end, weight = map(int,input().split())
        line_info[start].append((end, -weight))    

    limit = 10001
    node_info = [limit for _ in range(node+1)]

    print(YES if bellmanford(1) else NO)