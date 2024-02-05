input = open(0).readline

while (num := int(input())) != 0:
    if num in [1, 2]:
        print(1)
    else:
        primes = [0, 0] + [1] * (num*2)
        for i in range(2, int((num*2)**0.7)):
            if primes[i] == 1:
                for j in range(2*i, num*2+2, i):
                    primes[j] = 0
        print(sum(primes[num+1:num*2+1]))