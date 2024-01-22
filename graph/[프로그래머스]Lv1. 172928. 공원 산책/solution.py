def solution(park, routes):
    answer = []
    op_dict = {'E': (0, 1), 'W': (0, -1), 'S' : (1, 0), 'N' : (-1, 0)}
    row = len(park) - 1
    column = len(park[0]) - 1
    
    for i, r in enumerate(park):
        if 'S' in r:
            x, y = i, r.find('S')
    
    for r in routes:
        tx, ty = x, y
        op, n = r.split(' ')
        dx, dy = op_dict[op]
        for i in range(int(n)):
            nx = tx + dx
            ny = ty + dy
            if nx < 0 or ny < 0 or nx > row or ny > column:
                break
            if park[nx][ny] == 'X':
                break
            tx = nx
            ty = ny
        else:
            x, y = tx, ty
    
    return x, y