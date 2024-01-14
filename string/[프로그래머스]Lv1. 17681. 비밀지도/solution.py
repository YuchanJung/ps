# 첫 풀이
def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        row = ''
        temp = str(bin(arr1[i] | arr2[i]))[2:]
        if len(temp) < n:
            temp = ' ' * (n - len(temp)) + temp
        for x in temp:
            row += '#' if x == '1' else ' '
        answer.append(row)
    return answer


# 더 나은 풀이
def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        row = str(bin(arr1[i] | arr2[i]))[2:]
        
        if len(row) < n: # row = row.rjust(n, '0') 으로 압축 가능
            row = ' ' * (n - len(row)) + row
        
        row = row.replace('1', '#')
        row = row.replace('0', ' ')
        answer.append(row)
    return answer