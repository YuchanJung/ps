# 첫 풀이
def solution(participant, completion):
    answer = ''
    d = {}
    for p in participant:
        if d.get(p):
            d[p] += 1
        else:
            d[p] = 1
    
    for c in completion:
        d[c] -= 1
        if d[c] == 0:
            del d[c]
    
    return list(d.keys())[0]

# hash() 이용한 풀이
def solution(participant, completion):
    answer = ''
    temp = 0
    dic = {}
    for part in participant:
        dic[hash(part)] = part
        temp += int(hash(part))
    for com in completion:
        temp -= hash(com)
    answer = dic[temp]

    return answer

# collections Counter 객체 풀이
import collections

def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]