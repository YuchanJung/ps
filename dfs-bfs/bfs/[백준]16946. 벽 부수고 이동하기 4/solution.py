from collections import deque
import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

n, m = map(int, input().split())
mat = [[int(x) for x in input() if x.isdigit()] for _ in range(n)]
visited = [[0] * m for _ in range(n)]
dq = deque()

def bfs(sx, sy):
    s = set()
    k = 1
    visited[i][j] = 1
    dq.append((sx, sy))
    while dq:
        x, y = dq.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if nx < 0 or ny < 0 or nx >= n or ny >= m or visited[nx][ny]: continue
            if mat[nx][ny] == 0:
                k += 1
                visited[nx][ny] = 1
                dq.append((nx, ny))
            else:
                s.add((nx, ny))

    for x, y in s:
        mat[x][y] += k

for i in range(n):
    for j in range(m):
        if mat[i][j] == 0 and visited[i][j] == 0:
            bfs(i, j)

for i in range(n):
    for j in range(m):
        print(mat[i][j] % 10, end='')
    print()