def solution(record):
    answer = []
    temp = []
    info = {}
    for r in record:
        r = r.split(' ')
        if r[0] == 'Enter':
            temp.append([r[1], '님이 들어왔습니다.'])
            info[r[1]] = r[2]
        elif r[0] == 'Leave':
            temp.append([r[1], '님이 나갔습니다.'])
        else:
            info[r[1]] = r[2]
    
    for t in temp:
        answer.append(info[t[0]] + t[1])
        
    return answer