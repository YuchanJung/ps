mod = 1000000007
def mul(a, b):
    r = len(a)
    m = len(b)
    c = len(b[0])
    res = [[0] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(m):
                res[i][j] += a[i][k] * b[k][j]
                res[i][j] %= mod
    return res

def square(a, n):
    res = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2: res = mul(res, a)
        n //= 2
        a = mul(a, a)
    return res

n = int(input())
k = mul(square([[1, 1], [1, 0]], n), [[1], [0]])
print(k[1][0])
