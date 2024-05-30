from math import ceil

def solution(fees, records):
    answer = []
    cars = {}  # {차량 번호: [출입시간]}
    times = {}  # {차량 번호: 주차시간 총합}
    basic_time, basic_fee, unit_time, unit_fee = fees

    for r in records:
        time, car_num, go_type = r.split()
        if not car_num in cars:
            cars[car_num] = []
        cars[car_num].append(time)

    for num, time_record in cars.items():
        if len(time_record) % 2 == 1:
            time_record.append('23:59')
        total_time = 0
        for i in range(0, len(time_record), 2):
            in_time, out_time = time_record[i], time_record[i+1]
            in_h, in_m = map(int, in_time.split(':'))
            out_h, out_m = map(int, out_time.split(':'))
            total_time += (60 * (out_h - 1 - in_h) + (out_m + 60 - in_m))
        times[num] = total_time

    for a in sorted(times.keys()):
        total_time = times[a]
        if total_time <= basic_time:
            answer.append(basic_fee)
        else:
            answer.append(basic_fee + ceil((total_time - basic_time) / unit_time) * unit_fee)

    return answer
