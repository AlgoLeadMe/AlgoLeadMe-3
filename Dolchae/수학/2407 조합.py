import sys

input = sys.stdin.readline

n,m = map(int,input().split())

def factorial(num):
    result = 1
    for i in range(1,num+1):
        result *= i
    return result

print(factorial(n)//(factorial(n-m)*factorial(m)))