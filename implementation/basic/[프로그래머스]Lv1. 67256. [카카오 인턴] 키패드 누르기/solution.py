def solution(numbers, hand):
    answer = ''
    left_coord = (3, 0)
    right_coord = (3, 2)
    for n in numbers:
        if n != 0:
            c = ((n - 1) // 3, (n - 1) % 3)
        else:
            c = (3, 1)
        
        if n in [1, 4, 7]:
            answer += 'L'
        elif n in [3, 6, 9]:
            answer += 'R'
        else: # 2 5 8 0
            left_distance = abs(left_coord[0] - c[0]) + abs(left_coord[1] - c[1])
            right_distance = abs(right_coord[0] - c[0]) + abs(right_coord[1] - c[1])
            if left_distance > right_distance:
                answer += 'R'
            elif left_distance < right_distance:
                answer += 'L'
            else:
                if hand == 'left':
                    answer += 'L'
                else:
                    answer += 'R'
        
        if answer[-1] == 'L':
            left_coord = c
        else:
            right_coord = c
    return answer