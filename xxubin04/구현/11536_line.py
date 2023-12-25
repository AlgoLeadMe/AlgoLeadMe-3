num = int(input())
arrName = []

for i in range(num):
    name = input()
    arrName.append(name)

if arrName == sorted(arrName):
    print("INCREASING")
elif arrName == sorted(arrName, reverse=True):
    print("DECREASING")
else:
    print("NEITHER")