import sys

input=sys.stdin.readline
n = int(input())
num_list = []

for _ in range(n):
    i = int(input())
    num_list.append(i)
num_list.sort()

print(round(sum(num_list)/n)) #산술평균
print(num_list[n//2]) #중앙값

dic = {}
for i in num_list:
    if i in dic.keys():
        dic[i] += 1
    else:
        dic[i] = 1

max_num = max(dic.values())
max_list = []
for i in dic:
    if max_num == dic[i]:
        max_list.append(i)
#최빈값
if len(max_list)>1:
    print(max_list[1])
else:
    print(max_list[0])

print(num_list[-1] - num_list[0])