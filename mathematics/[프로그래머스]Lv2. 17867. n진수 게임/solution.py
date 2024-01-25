def conv(n, k):
    s = ''
    while k > 0:
        if k % n >= 10:
            s += str(chr(k % n + 55))
        else:
            s += str(k % n)
        k //= n
    return s[::-1]

def solution(n, t, m, p):
    answer = ''
    l = '0'
    maxlen = t * m
    k = 1
    while len(l) < maxlen:
        l += conv(n, k)
        k += 1
    start = p - 1
    while t > 0:
        answer += l[start]
        start += m
        t -= 1
    return answer