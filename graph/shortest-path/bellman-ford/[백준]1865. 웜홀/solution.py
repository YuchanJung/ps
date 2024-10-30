'''
완벽한 벨만 포드 문제는 아니다.
https://www.acmicpc.net/board/view/72995 글을 참고하자
'''
import sys
input = sys.stdin.readline

def bellman_ford():
    # dist[1] = 0
    for i in range(n):
        for j in range(1, n + 1):
            for d, c in adj[j]:
                if dist[d] > dist[j] + c:
                    dist[d] = dist[j] + c
                    if i == n - 1: return False 
    return True


tc = int(input())
for _ in range(tc):
    n, m, w = map(int, input().split())
    dist = [2e9] * (n + 1) # 값 상관없음 (무한대 필요 x)
    adj = [[] for _ in range(n + 1)]
    for i in range(m + w):
        s, e, t = map(int, input().split())
        if (i < m):
            adj[s].append((e, t))
            adj[e].append((s, t))
        else:
            adj[s].append((e, -t))
    if bellman_ford(): print('NO')
    else: print('YES')