import sys
input = sys.stdin.readline

n = int(input())
car = [input().strip() for _ in range(n * 2)]
car_in, car_out = car[:n], car[n:]

cnt = 0
isOut = [False] * n
for car in car_out:
    c = car_in.index(car)

    overtake = False
    for i in range(c):
        if not isOut[i]:
            overtake = True
    if overtake:
        cnt += 1

    isOut[c] = True
print(cnt)