# 첫 풀이
def solution(lottos, win_nums):
    match_cnt = 0
    for l in lottos:
        if l in win_nums:
            match_cnt+= 1
    min_score = 6 if match_cnt <= 1 else 7 - match_cnt
    zero_count = lottos.count(0)
    max_score = 1 if zero_count == 6 else min_score - zero_count
    return [max_score, min_score]

# 더 나은 풀이
def solution(lottos, win_nums):
    rank = [6, 6, 5, 4, 3, 2, 1]
    cnt = 0
    for l in lottos:
        if l in win_nums:
            cnt += 1
    zero_cnt = lottos.count(0)
    return rank[cnt + zero_cnt], rank[cnt]