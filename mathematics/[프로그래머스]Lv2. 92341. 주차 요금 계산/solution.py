# 더 나은 풀이 : 딕셔너리 한 개로 해결 가능
import math

def solution(fees, records):
    parking = {}
    for r in records:
        time, car_id, io = r.split(' ')
        car_id = int(car_id)
        h, m = map(int, time.split(':'))
        time = h * 60 + m
        if not parking.get(car_id):
            parking[car_id] = (-time, io)
        elif io == 'IN':
            parking[car_id]  = (parking[car_id][0] - time, io)
        elif io == 'OUT':
            parking[car_id] = (parking[car_id][0] + time, io)
    
    for car_id, p in parking.items():
        v = p[0]
        if p[1] == 'IN':
            v += 23 * 60 + 59
        if v < fees[0]:
            v = fees[1]
        else:
            v = fees[1] + math.ceil((v - fees[0]) / fees[2]) * fees[3]
        parking[car_id] = v

    parking = dict(sorted(parking.items()))
    
    return list(parking.values())

# 첫 풀이
import math

def solution(fees, records):
    parking = {}
    duration = {}
    for r in records:
        time, car_id, io = r.split(' ')
        car_id = int(car_id)
        h, m = map(int, time.split(':'))
        if io == 'IN':
            parking[car_id] = h * 60 + m
        else: # OUT
            t = h * 60 + m - parking[car_id]
            if duration.get(car_id):
                duration[car_id] += t
            else:
                duration[car_id] = t
            del parking[car_id]

    if parking:
        for p in parking:
            t = 23 * 60 + 59 - parking[p]
            if duration.get(p):
                duration[p] += t
            else:
                duration[p] = t

    answer = []
    for key, value in duration.items():
        if value < fees[0]:
            fee = fees[1]
        else:
            fee = fees[1] + math.ceil((value - fees[0]) / fees[2]) * fees[3]
        duration[key] = fee
    duration = dict(sorted(duration.items()))

    return list(duration.values())

