# 첫 풀이
def solution(msg):
    answer = []
    d = {chr(k): k - 64 for k in range(65, 91)}
    s = msg[0]
    msg = msg[1:]
    while msg:
        if d.get(s + msg[0]):
            s += msg[0]
        else:
            answer.append(d[s])
            d[s + msg[0]] = len(d) + 1
            s = msg[0]
        msg = msg[1:]
    answer.append(d[s])
    return answer