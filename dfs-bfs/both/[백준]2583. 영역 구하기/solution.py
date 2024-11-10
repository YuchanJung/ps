from collections import deque
import sys
input = sys.stdin.readline

def bfs(r, c):
    cnt = 1
    v[r][c] = 1
    dq.append((r, c))
    while dq:
        x, y = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= m or ny >= n or v[nx][ny]: continue
            if arr[nx][ny] == 0:
                v[nx][ny] = v[x][y] + 1
                dq.append((nx, ny))
                cnt += 1
    return cnt

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
m, n, k = map(int, input().split())
arr = [[0] * n for _ in range(m)]
v = [[0] * n for _ in range(m)]
res = []
dq = deque()
for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y2, y1, -1):
        for j in range(x1, x2):
            arr[m - i][j] = 1
for i in range(m):
    for j in range(n):
        if not (arr[i][j] or v[i][j]):
            cnt = bfs(i, j)
            res.append(cnt)
res.sort()
print(len(res))
for r in res: print(r, end=' ')