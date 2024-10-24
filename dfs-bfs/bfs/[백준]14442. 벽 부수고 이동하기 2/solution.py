from collections import deque
import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

n, m, k = map(int, input().split())
arr = [input() for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]
dq = deque()

def bfs():
    if n == m == 1: return 1
    dq.append((0, 0, 0, 1))
    visited[0][0] = (1 << k + 1) - 1;
    while dq:
        x, y, w, d = dq.popleft()
        if x == n - 1 and y == m - 1: return d
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m: continue
            if arr[nx][ny] == '1':
                if w < k and visited[nx][ny] & (1 << w + 1) == 0:
                    visited[nx][ny] |= 1 << w + 1
                    dq.append((nx, ny, w + 1, d + 1))
            else:
                if visited[nx][ny] & (1 << w) == 0:
                    visited[nx][ny] |= 1 << w
                    dq.append((nx, ny, w, d + 1))
    return -1

print(bfs())