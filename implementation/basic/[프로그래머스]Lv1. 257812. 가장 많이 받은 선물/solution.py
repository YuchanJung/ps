# 첫 풀이
def solution(friends, gifts):
    n = len(friends)
    table = [[0] * (n + 1) for _ in range(n + 1)]
    
    for g in gifts:
        a, b = g.split(' ')
        ai = friends.index(a)
        bi = friends.index(b)
        table[ai][bi] += 1
        table[ai][n] += 1 # 행 총합
        table[n][bi] += 1 # 열 총합
               
    gift_score = [table[x][n] - table[n][x] for x in range(n)]
    
    gift_count = [0] * n
    for i in range(n):
        for j in range(n):
            if i == j: continue
            if table[i][j] > table[j][i]:
                gift_count[i] += 1
            elif table[i][j] == table[j][i]:
                if gift_score[i] > gift_score[j]:
                    gift_count[i] += 1
    
    return max(gift_count)