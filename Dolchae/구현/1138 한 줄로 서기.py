input_ = open(0).readline
num = int(input_())
line_list = list(map(int,input_().split()))
line_list.reverse()
ans_list = []

for i in range(num):
    ans_list.insert(len(ans_list)-line_list[i],num-i)

ans_list.reverse()
for i in ans_list:
    print(i,end=" ")
