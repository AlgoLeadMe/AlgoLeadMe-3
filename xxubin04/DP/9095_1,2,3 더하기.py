input = open(0).readline

def dp(value):
    if value == 1:
        return(1)
    elif value == 2:
        return(2)
    elif value == 3:
        return(4)
    else:
        return dp(value-3)+dp(value-2)+dp(value-1)

for i in range(n := int(input())):
    print(dp(int(input())))