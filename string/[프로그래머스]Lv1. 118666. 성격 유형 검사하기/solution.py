# A = A[::-1] # 문자열 역순 출력

def solution(survey, choices):
    answer = ''
    type = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    l = len(survey)
    for i in range(l):
        if choices[i] < 4:
            type[survey[i][0]] += 4 - choices[i]
        elif choices[i] > 4:
            type[survey[i][1]] += choices[i] - 4
        else:
            pass
        
    
    if type['R'] >= type['T']: answer += 'R'
    else: answer += 'T'
    
    if type['C'] >= type['F']: answer += 'C'
    else: answer += 'F'
    
    if type['J'] >= type['M']: answer += 'J'
    else: answer += 'M'
    
    if type['A'] >= type['N']: answer += 'A'
    else: answer += 'N'
    
    return answer


'''
def solution(survey, choices):

    my_dict = {"RT":0,"CF":0,"JM":0,"AN":0}
    for A,B in zip(survey,choices):
        if A not in my_dict.keys():
            A = A[::-1]
            my_dict[A] -= B-4
        else:
            my_dict[A] += B-4

    result = ""
    for name in my_dict.keys():
        if my_dict[name] > 0:
            result += name[1]
        elif my_dict[name] < 0:
            result += name[0]
        else:
            result += sorted(name)[0]

    return result
'''