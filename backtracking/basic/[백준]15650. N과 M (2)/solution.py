def comb(s, k):
    if (s == m):
        print(' '.join(str(x) for x in arr))
        return
    
    for i in range(k, n + 1):
        arr[s] = i
        comb(s + 1, i + 1)


n, m = map(int, input().split())
arr = [0] * m
comb(0, 1)