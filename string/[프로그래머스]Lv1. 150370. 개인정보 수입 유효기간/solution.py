def to_days(date):
    year, month, day = map(int, date.split('.'))
    return year * 12 * 28 + month * 28 + day

def solution(today, terms, privacies):
    answer = []
    t = {} # {v[0]: int(v[2:]) * 28 for v in terms}
    for term in terms:
        key, value = term.split(' ')
        t[key] = int(value)
        
    for i, privacy in enumerate(privacies):
        date, term = privacy.split(' ')
        if to_days(date) + t[term] * 28 - 1 < to_days(today):
            answer.append(i + 1)
    return answer

'''
처음 풀이
def compare(today, year, month, day):
    today_year, today_month, today_day = map(int, today.split('.'))
    if today_year < year:
        return False
    elif today_year == year:
        if today_month < month:
            return False
        elif today_month == month:
            if today_day <= day:
                return False
            else:
                return True
        else:
            return True
    else:
        return True

def solution(today, terms, privacies):
    answer = []
    t = {}
    for _t in terms:
        key, value = _t.split(' ')
        t[key] = int(value)

    i = 1
    for p in privacies:
        date, term = p.split(' ')
        year, month, day = map(int, date.split('.'))
        # print(year, month, day, term)
        # print('----')

        month += t[term]
        while month > 12:
            year += 1
            month -= 12
        day -= 1
        if day == 0:
            if month > 1:
                month -= 1
                day = 28
            else:
                year -= 1
                month = 12
                day = 28
        # print(year, month, day)

        if compare(today, year, month, day):
            answer.append(i)
        i += 1

    return answer
'''