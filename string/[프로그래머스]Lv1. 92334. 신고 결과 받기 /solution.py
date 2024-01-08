# 첫 풀이 (시간 더 빠름)
def solution(id_list, report, k):
    answer = []
    report_list = {name: [] for name in id_list}
    report_count = {name: 0 for name in id_list}

    for r in report:
        key, value = r.split(' ')
        if value not in report_list[key]:
            report_list[key].append(value)
            report_count[value] += 1

    for name_list in report_list.values():
        cnt = 0
        for n in name_list:
            if report_count[n] >= k:
                cnt += 1
        answer.append(cnt)
    return answer

# set을 사용한 풀이
# set 연산 자체에서 시간이 더 걸리는 것 같음
def solution(id_list, report, k):
    answer = [0] * len(id_list)    
    reports = {x : 0 for x in id_list}
    
    s = set(report)
    for r in s:
        reports[r.split()[1]] += 1

    for r in s:
        if reports[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] += 1

    return answer