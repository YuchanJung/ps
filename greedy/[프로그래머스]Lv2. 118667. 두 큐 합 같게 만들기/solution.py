from collections import deque

# greedy
def solution(queue1, queue2):
    d1 = deque(queue1)
    d2 = deque(queue2)
    
    s1 = sum(d1)
    s2 = sum(d2)
    target = s1 + s2
    if target % 2 != 0: return -1
    else: target //= 2
    
    n = len(d1)
    ans = 0
    while s1 != target:
        if ans > 4 * n: # 4n 이면 원점. 2n으로 하면 반례 생김 why??
            return -1
        
        if s1 > s2:
            x = d1.popleft()
            s1 -= x
            d2.append(x)
            s2 += x
        else:
            x = d2.popleft()
            s2 -= x
            d1.append(x)
            s1 += x
        ans += 1
            
    return ans