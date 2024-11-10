def perm(s):
    if (s == m):
        print(' '.join(str(x) for x in arr))
        return
    for i in range(0, n):
        if (visited[i]): continue
        arr[s] = an[i]
        visited[i] = 1
        perm(s + 1)
        visited[i] = 0

n, m = map(int, input().split())
an = sorted(list(map(int, input().split())))
visited = [0] * n
arr = [0] * m
perm(0)