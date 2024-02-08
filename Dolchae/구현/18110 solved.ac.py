import sys
input = sys.stdin.readline

def my_round(val):
  if val - int(val) >= 0.5:
    return int(val)+1
  else:
    return int(val)

n = int(input())
if n:
  level = []
  for _ in range(n):
    level.append(int(input()))

  level.sort()
  nn = my_round(n*0.15)

  if nn > 0:
    print(my_round(sum(level[nn:-nn])/len(level[nn:-nn])))
  else:
    print(my_round(sum(level)/len(level)))
else:
  print(0)
