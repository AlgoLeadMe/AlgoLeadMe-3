input = open(0).readline

for _ in range(int(input())):
    times = list(input().split())
    degree_list = {}

    for idx, t in enumerate(times):
        hh, mm = map(int, t.split(':'))
        h_degree = (hh % 12) * 30 + mm / 2
        m_degree = mm * 6
        degree = abs(h_degree - m_degree)
        if degree > 180:
            degree = 360 - degree
        degree_list[idx] = degree
    sorted_times = sorted(times, key=lambda x: (degree_list[times.index(x)], x))
    print(sorted_times[2])
