import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

n, m = map(int, input().split())
arr = [input() for _ in range(n)]
visited = [[0b00 for c in range(m)] for r in range(n)] # 00, 01, 10, 11
dq = deque()
dq.append((0, 0, 0, 1))
visited[0][0] = 0b11

def bfs():
    if n == m == 1: return 1
    while dq:
        x, y, w, d = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m: continue
            if arr[nx][ny] == '0':
                if w == 0 and visited[nx][ny] & 0b01 == 0:
                    if nx == n - 1 and ny == m - 1: return d + 1
                    visited[nx][ny] |= 0b01
                    dq.append((nx, ny, 0, d + 1))
                if w == 1 and visited[nx][ny] & 0b10 == 0:
                    if nx == n - 1 and ny == m - 1: return d + 1
                    visited[nx][ny] |= 0b10
                    dq.append((nx, ny, 1, d + 1))
            elif arr[nx][ny] == '1' and w == 0:
                visited[nx][ny] |= 0b10
                dq.append((nx, ny, 1, d + 1))
    return -1

print(bfs())