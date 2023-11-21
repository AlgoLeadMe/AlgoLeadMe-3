input = open(0).readline

n = int(input())
nlist = list(map(int,input().split()))
nlist.sort()

cnt = int(input())
targets = list(map(int,input().split()))

def find_num(left, right, target):
    
    mid = (left + right)//2
    
    if (left > right):
        print("0")
        return
        
    if target > nlist[mid]:
        find_num(mid+1, right, target)
    elif target < nlist[mid]:
        find_num(left, mid-1, target)
    else:
        print("1")
        return

for target in targets:
    find_num(0,len(nlist)-1, target)
