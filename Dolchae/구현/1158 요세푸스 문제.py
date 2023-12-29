input_ = open(0).readline
num, order = map(int,input_().split())
list = [i+1 for i in range(num)]
ans_list = []
count = 0
while True:
    if len(list)==0:
        break
    count = (count+order-1)%len(list)
    ans_list.append(list.pop(count))

print(f"<{', '.join(map(str,ans_list))}>")
