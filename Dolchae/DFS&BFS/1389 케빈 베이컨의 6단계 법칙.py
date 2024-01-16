from collections import deque

input = open(0).readline

user_num, relation_num = map(int,input().split())
relations = [[] for _ in range(user_num+1)]
bacon_list = []


def bacon(i):
    visited = [0] * (user_num+1)
    queue = deque()
    queue.append(i)
    visited[i] = 1
    while queue:
        v = queue.popleft()
        for k in relations[v]:
            if not visited[k]:
                visited[k] = visited[v]+1
                queue.append(k)
    return sum(visited)

for _ in range(relation_num):
    a,b = map(int,input().split())
    relations[a].append(b)
    relations[b].append(a)


for i in range(1,user_num+1):
    bacon_list.append(bacon(i))

print(bacon_list.index(min(bacon_list))+1)
