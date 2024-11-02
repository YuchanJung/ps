mod = 1000000007
def mul(a, b):
    c = [[0] * 8 for _ in range(8)]
    for i in range(8):
        for j in range(8):
            for k in range(8):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod
    return c

def pow(a, n):
    r = [[0] * 8 for _ in range(8)]
    for i in range(8): r[i][i] = 1
    while n > 0:
        if n % 2: r = mul(r, a)
        n //= 2
        a = mul(a, a)
    return r

mat = [
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 1, 0],
    [0, 0, 0, 1, 1, 0, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1],
    [0, 0, 0, 0, 0, 1, 1, 0]
]
n = int(input())
res = pow(mat, n)
print(res[0][0])