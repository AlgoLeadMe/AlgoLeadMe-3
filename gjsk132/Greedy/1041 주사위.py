input = open(0).readline

size = int(input())

dice_nums = list(map(int,input().split()))

def find_dice_sum():

    dice_sets = [sorted([dice_nums[2-i], dice_nums[3+i]])for i in range(3)]
    dice_sets = sorted(dice_sets, key=lambda x : x[1], reverse = True)
    dice_sets = sorted(dice_sets, key=lambda x : x[0])

    vertex = 4
    corner = (size-1)*8
    surface = pow(size, 2)*5 - corner - vertex 

    return dice_sets[0][0]*surface + dice_sets[1][0]*corner + dice_sets[2][0]*vertex

if size == 1:
    print(sum(dice_nums)-max(dice_nums))

else:
    print(find_dice_sum())