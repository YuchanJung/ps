# 첫 풀이
def solution(dR):
    answer = []
    bonus = {'S': 1, 'D': 2, 'T': 3}
    for i in range(3):
        value = int(dR[0])
        dR = dR[1:]
        if dR[0] == '0': # 10
            value = 10
            dR = dR[1:]

        value **= bonus[dR[0]]
        dR = dR[1:]
        answer.append(value)

        if not dR: break

        if dR[0] == '*':
            answer[-1] *= 2
            if len(answer) > 1: answer[-2] *= 2
            if len(dR) > 1: dR = dR[1:]
        elif dR[0] == '#':
            answer[-1] *= -1
            if len(dR) > 1: dR = dR[1:]

    return sum(answer)
    
# 더 나은 풀이
def solution(dartResult):
    answer = []
    dartResult = dartResult.replace('10', 'x')
    bonus = {'S': 1, 'D': 2, 'T': 3}
    for d in dartResult:
        if d in bonus:
            answer[-1] **= bonus[d]
        elif d == '*':
            answer[-1] *= 2
            if len(answer) > 1: answer[-2] *= 2
        elif d == '#':
            answer[-1] *= -1
        else:
            v = 10
            if d != 'x': v = int(d)
            answer.append(v)
    return sum(answer)