import sys
input = sys.stdin.readline

signup_num, students_num = map(int,input().split())
signup = {}

for i in range(students_num):
  now = input().strip()
  signup[now] = i

sorted_dict = sorted(signup.items(), key=lambda x: x[1])

if signup_num > len(sorted_dict):
  signup_num = len(sorted_dict)

for i in range(signup_num):
  print(sorted_dict[i][0])