import sys
input = sys.stdin.readline

n = int(input())
car = [input().strip() for _ in range(n * 2)]
car_in, car_out = car[:n], car[n:]

cnt, idx = 0, 0
for car in car_out:
    head = car_in[idx]
    if car != head:
        cnt += 1
        car_in.remove(car)
    else:
        idx += 1
print(cnt)