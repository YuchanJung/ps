import sys
from collections import deque
input = sys.stdin.readline

adj = [[] for _ in range(32001)]
degree = [0 for _ in range(32001)]
n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    degree[b] += 1

d = deque()
for i in range(1, n + 1):
    if degree[i] == 0:
        d.append(i)

while d:
    now = d.popleft()
    print(now, end=' ')
    for next in adj[now]:
        degree[next] -= 1
        if degree[next] == 0:
            d.append(next)