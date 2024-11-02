import sys
input = sys.stdin.readline

def rotate():
    global s, e
    s = (s - 1 + n * 2) % (n * 2)
    e = (e - 1 + n * 2) % (n * 2)
    if r[e]: r[e] = 0

def move():
    c = e
    for i in range(n - 1):
        nc = (c - 1 + n * 2) % (n * 2)
        if r[nc] and r[c] == 0 and h[c] >= 1:
            h[c] -= 1
            r[nc], r[c] = r[c], r[nc]
            if c == e: r[c] = 0 # 내리기
        c = nc

def load():
    if h[s] > 0:
        r[s] = 1
        h[s] -= 1

n, k = map(int, input().split())
h = list(map(int, input().split()))
r = [0] * n * 2
s = 0
e = n - 1
cnt = 1
while True:
    rotate()
    move()
    load()
    if h.count(0) >= k:
        print(cnt)
        break
    cnt += 1
