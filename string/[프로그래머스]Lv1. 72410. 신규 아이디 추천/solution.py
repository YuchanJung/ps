# 첫 풀이
def solution(new_id):
    key = "~!@#$%^&*()=+[{]}:?,<>/"
    value = " " * len(key)
    table = str.maketrans(key, value)
    
    # 1단계
    ans = new_id.lower()
    
    # 2단계
    ans = ans.translate(table) 
    ans = ans.replace(' ', '')
    
    # 3단계
    l = len(ans)
    for i in range(l, 0, -1):
        ans = ans.replace('.' * i, '.')
    
    # 4단계
    if ans.startswith('.'):
        ans = ans[1:]
    if ans.endswith('.'):
        ans = ans[:-1]
        
    # 5단계
    if len(ans) == 0:
        ans += 'a'
    
    # 6단계
    if len(ans) >= 16: 
        ans = ans[:15]
        if ans.endswith('.'):
            ans = ans[:-1]
    
    # 7단계
    if len(ans) <= 2: 
        while len(ans) < 3:
            ans += ans[-1]
        
    return ans


# 깔끔한 풀이
def solution(new_id):
    answer = ''
    # 1
    new_id = new_id.lower()
    # 2
    for c in new_id:
        if c.isalpha() or c.isdigit() or c in ['-', '_', '.']:
            answer += c
    # 3
    while '..' in answer:
        answer = answer.replace('..', '.')
    # 4
    if answer[0] == '.':
        answer = answer[1:] if len(answer) > 1 else '.'
    if answer[-1] == '.':
        answer = answer[:-1]
    # 5
    if answer == '':
        answer = 'a'
    # 6
    if len(answer) > 15:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]
    # 7
    while len(answer) < 3:
        answer += answer[-1]
    return answer