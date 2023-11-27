from collections import deque
input = open(0).readline

t = int(input())

for i in range(t):
    doc_num, ans_pos = map(int,input().split())
    queue = deque(map(int,input().split()))
    count = 0
    while True:
        best = max(queue)
        front = queue.popleft()
        ans_pos -= 1

        if best == front:
            count += 1
            if ans_pos<0:
                print(count)
                break
        else:
            queue.append(front)
            if ans_pos < 0:
                ans_pos = len(queue)-1
