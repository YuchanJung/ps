from collections import deque

f, s, g, u, d = map(int, input().split())
dist = [0] * (f + 1)
dq = deque()
dist[s] = 1
dq.append(s)
while dq:
    now = dq.popleft()
    for i in [u, -d]:
        next = now + i
        if next <= 0 or next > f or dist[next]: continue
        dist[next] = dist[now] + 1
        dq.append(next)

if dist[g]: print(dist[g] - 1)
else: print('use the stairs')