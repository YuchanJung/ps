from collections import deque
import sys
input = sys.stdin.readline

t = int(input())
g = []
dq = deque()
for _ in range(t):
    n = int(input())
    g = []
    v = [0] * (n + 2)
    for i in range(n + 2):
        x, y = map(int, input().split())
        g.append((x, y, i))
    v[0] = 1
    dq.append(g[0])
    while dq:
        x, y, idx = dq.popleft()
        for i in range(1, n + 2):
            if v[i] or abs(x - g[i][0]) + abs(y - g[i][1]) > 1000:
                continue
            v[i] = 1
            dq.append(g[i])
    if v[n + 1]: print('happy')
    else: print('sad')