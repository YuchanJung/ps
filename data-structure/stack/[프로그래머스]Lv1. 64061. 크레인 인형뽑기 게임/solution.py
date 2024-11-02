def solution(board, moves):
    answer = 0
    size = len(board)
    stack = []    
    for m in moves:
        for j in range(size):
            target = board[j][m - 1]
            if target > 0:
                if stack and stack[-1] == target:
                    stack.pop()
                    answer += 2
                else:
                    stack.append(target)
                board[j][m - 1] = 0
                break
        
    return answer