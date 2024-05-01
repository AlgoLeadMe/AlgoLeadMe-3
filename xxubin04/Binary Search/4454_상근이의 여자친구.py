input = open(0).readline

def max_velocity(a, b, c, d, m, t):
    start = 0;
    end = 1000000
    MAX = 0

    for i in range(500):
        mid = (start + end) / 2
        distance = (a * mid ** 3 + b * mid ** 2 + c * mid + d) * m
        if distance <= t:
            MAX = max(MAX, mid)
            start = mid
        else:
            end = mid

    return MAX


while True:
    try:
        a, b, c, d, m, t = map(float, input().split())
        result = max_velocity(a, b, c, d, m, t)
        print("%.2f" % (int(result * 100) / 100))
    except:
        break