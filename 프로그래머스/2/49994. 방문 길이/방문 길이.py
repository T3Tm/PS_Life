'''
'25. 09. 25.(목)

1. U 위, D 아, R 오, L 왼

2. 처음 가본 길이를 구하시오.

0, 3 -> 0, 4으로 가는 것과
0, 4 -> 0, 3으로 가는 길은 동일하다.

'''


def solution(dirs):
    board = [[0] * 11 for _ in range(11)]
    visited = [[[[0] * 11 for _ in range(11)]for _ in range(11)]for _ in range(11)]
    
    MOVE = {"U" : (-1, 0), "D" : (1, 0), "R" : (0, 1), "L" : (0, -1)}
    answer = 0
    
    x, y = 5, 5#초기 위치
    for direc in dirs:
        dx, dy = MOVE[direc]
        nx, ny = x + dx, y + dy
        if nx < 0 or nx > 10 or ny < 0 or ny > 10:continue
        if not visited[nx][ny][x][y]:
            visited[nx][ny][x][y] = visited[x][y][nx][ny] = 1
            answer += 1
        x, y = nx, ny
    return answer