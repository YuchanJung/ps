# 첫 풀이
def isPrime(n):
    if n == 1: 
        return False
    for i in range(2, n):
        if i * i > n: break
        if n % i == 0:
            return False
    return True

def solution(n, k):
    import re
    answer = 0
    m = ''
    while n > 0:
        m += str(n % k)
        n //= k
    m = m[::-1]
    l = [int(k) for k in re.split('0', m) if k]
    for value in l:
        if isPrime(value):
            answer += 1
    return answer

# 더 나은 풀이
def conv(n, k):
    m = ''
    while n > 0:
        m += str(n % k)
        n //= k
    return  m[::-1]

def isPrime(n):
    if n <= 1: return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def solution(n, k):
    answer = 0
    m = conv(n, k)
    l = [int(k) for k in m.split('0') if k]
    for value in l:
        if isPrime(value):
            answer += 1
    return answer