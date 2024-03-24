from collections import defaultdict

input = open(0).readline

def backtracking(cnt):
    if cnt == word_len:
        print("".join(combi))
        return    
    
    for a in alpha:
        if alpha_cnt[a] == 0:
            continue
        
        alpha_cnt[a] -= 1
        combi.append(a)
        backtracking(cnt+1)
        combi.pop()
        alpha_cnt[a] += 1

for i in range(int(input())):
    word = input().strip()
    alpha_cnt = {x : word.count(x) for x in set(list(word))}
    alpha = sorted(alpha_cnt)
    combi = []
    word_len = len(word)
    
    backtracking(0)