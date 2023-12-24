import math as m

input = open(0).readline
n1_high, n1_low = map(int,input().split())
n2_high, n2_low = map(int,input().split())

ans_low = m.lcm(n1_low,n2_low)
ans_high = (ans_low//n1_low)*n1_high + (ans_low//n2_low)*n2_high

gcd = m.gcd(ans_low,ans_high)
ans_low //= gcd
ans_high //= gcd

print(ans_high,ans_low)
