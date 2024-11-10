from collections import deque
import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
mapping = {
    '#': 2,
    '*': 1,
    '.': 0,
    '@': -1,
}

t = int(input())
for _ in range(t):
    dq = deque()
    w, h = map(int, input().split())
    mat = [[mapping[c] for c in input().strip()] for _ in range(h)]
    dist = [[0] * w for _ in range(h)]
    res = 1e9
    for i in range(h):
        for j in range(w):
            if mat[i][j] == -1:
                dq.append((i, j, 0))
                dist[i][j] = 1
                mat[i][j] = 0
            if mat[i][j] == 1:
                dq.appendleft((i, j, 1))
    while dq:
        x, y, n = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= h or ny >= w:
                if n == 0: res = min(res, dist[x][y])
                continue
            if mat[nx][ny] > 0: continue
            if n == 1: # 불
                mat[nx][ny] = 1
                dq.append((nx, ny, 1))
            if n == 0 and dist[nx][ny] == 0:
                dist[nx][ny] = dist[x][y] + 1
                dq.append((nx, ny, 0))
    
    if res == 1e9: print('IMPOSSIBLE')
    else: print(res)