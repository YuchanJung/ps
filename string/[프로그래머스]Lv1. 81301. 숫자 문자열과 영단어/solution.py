'''
num_dic = {"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}

def solution(s):
    answer = s
    for key, value in num_dic.items():
        answer = answer.replace(key, value)
    return int(answer)
'''

def solution(s):
    answer = 0
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    l = len(s)
    i = 0
    while i < l:
        if s[i] in numbers:
            add_num = int(s[i])
            i += 1
        elif s[i] == 'z':
            add_num = 0
            i += 4
        elif s[i] == 'o':
            add_num = 1
            i += 3
        elif s[i] == 't':
            if s[i + 1] == 'w':
                add_num = 2
                i += 3
            else:
                add_num = 3
                i += 5
        elif s[i] == 'f':
            if s[i + 1] == 'o':
                add_num = 4
            else:
                add_num = 5
            i += 4
        elif s[i] == 's':
            if s[i + 1] == 'i':
                add_num = 6
                i += 3
            else:
                add_num = 7
                i += 5
        elif s[i] == 'e':
            add_num = 8
            i += 5
        elif s[i] == 'n':
            add_num = 9
            i += 4
        answer = answer * 10 + add_num

    return answer