import sys
input = sys.stdin.readline

n = int(input().strip())
serial = []

for _ in range(n):
    serial.append(input().strip())

def get_number_sum(s):
    number_sum = 0
    for char in s:
        if char.isdigit():
            number_sum += int(char)
    return number_sum

for i in range(n-1):
    for j in range(i+1, n):
        if len(serial[i]) > len(serial[j]):
            serial[j], serial[i] = serial[i], serial[j]
        elif len(serial[i]) == len(serial[j]):
            i_total = get_number_sum(serial[i])
            j_total = get_number_sum(serial[j])
            if i_total > j_total:
                serial[j], serial[i] = serial[i], serial[j]
            elif i_total == j_total:
                if serial[i] > serial[j]:
                    serial[j], serial[i] = serial[i], serial[j]

for i in serial:
    print(i)

