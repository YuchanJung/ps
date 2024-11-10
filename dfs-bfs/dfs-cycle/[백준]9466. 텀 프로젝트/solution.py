import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def dfs(now):
    global no, res
    next = arr[now]
    if v[next] == 0:
        no += 1
        v[next] = no
        dfs(next)
    elif f[next] == 0:
        res += (v[now] - v[next] + 1)
    f[now] = 1
    

t = int(input())
for _ in range(t):
    n = int(input())
    no = 0
    res = 0
    arr = [0] + list(map(int, input().split()))
    v = [0] * (n + 1)
    f = [0] * (n + 1)
    for i in range(1, n + 1):
        if not v[i]:
            no += 1
            v[i] = no
            dfs(i)
    print(n - res)