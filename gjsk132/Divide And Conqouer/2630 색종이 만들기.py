input = open(0).readline

size = int(input())
color = [list(map(int,input().split())) for _ in range(size)]

color_type = [0, 0]

def divide_and_conquer(px, py, side):
    color_area = sum([sum(row[px:px+side]) for row in color[py:py+side]])
    
    if color_area == 0:
        color_type[0] += 1
        return
    
    if color_area == side**2:
        color_type[1] += 1
        return
    
    next_side = side//2
    divide_and_conquer(px, py, next_side)
    divide_and_conquer(px+next_side, py, next_side)
    divide_and_conquer(px, py+next_side, next_side)
    divide_and_conquer(px+next_side, py+next_side, next_side)
    
divide_and_conquer(0,0,size)

print(color_type[0])
print(color_type[1])