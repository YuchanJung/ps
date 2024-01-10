# 첫 풀이
def solution(N, stages):
    answer = []
    stages.sort() # [1, 2, 2, 2, 3, 3, 4, 6]
    fail_rate = {}
    for s in range(1, N + 1):
        f = stages.count(s)
        if f == 0:
            fail_rate[s] = 0
        else:
            fail_rate[s] = f / (len(stages) - stages.index(s))
    fail_rate = sorted(fail_rate.items(), key=lambda x: x[1], reverse=True)
    for f in fail_rate:
        answer.append(f[0])
    return answer

# 더 나은 풀이
def solution(N, stages):
    denominator = len(stages)
    fail_rate = {}
    for s in range(1, N + 1):
        if denominator != 0:
            c = stages.count(s)
            f = c / denominator
            fail_rate[s] = f
            denominator -= c
        else:
            fail_rate[s] = 0
    return sorted(fail_rate, key=lambda x: fail_rate[x], reverse=True)