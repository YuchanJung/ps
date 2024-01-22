def solution(s):
    answer = []
    s = s[2:-2]
    tuple_list = []
    temp = list(map(str, s.split('},{')))
    for t in temp:
        tuple_list.append(list(map(int, t.split(','))))
        
    tuple_list.sort(key=lambda x:len(x)) # sort(key=len)
    
    for items in tuple_list:
        for i in items:
            if i not in answer:
                answer.append(i)
    return answer