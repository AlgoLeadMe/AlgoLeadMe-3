import sys

input = sys.stdin.readline

hurt = int(input().strip())
hurt_max = int(input().strip())

if hurt == 1:
  ans = hurt_max*8
elif 2<=hurt<=4:
  if hurt_max%2 == 0:
    ans = (hurt_max//2)*8 + (hurt-1)
  else:
    ans = (hurt_max//2)*8 + (9-hurt)
elif hurt == 5:
  ans = 4 + 8*hurt_max

print(ans)
