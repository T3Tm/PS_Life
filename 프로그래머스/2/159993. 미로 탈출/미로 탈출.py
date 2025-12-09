'''
'25. 12. 9.(화)

1. bfs 돌리는데 방문배열을 3차원으로 잡고 돌린다.
2. visited[x][y][z] (y, z) 좌표에 x를 하고 도달했는지 판별
x는 레버를 당겼는지 아닌지 판별
'''
from collections import deque
#target 찾으면 좌표 보내기
def find(maps: list, target: str) -> tuple:
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == target:
                return i, j
    return -1, -1
def solution(maps: list) -> int:
    answer = -1
    
    q = deque()
    x, y = find(maps, 'S')#시작 좌표 알아내기
    q.append((x, y, 0))#(x, y) 좌표, 레버를 당겼는지
    
    ROW = len(maps)
    COL = len(maps[0])
    MOVE = (0, 1), (0, -1), (1, 0), (-1, 0)
    visited = [[[-1]*COL for _ in range(ROW)]for _ in range(2)]
    
    visited[0][x][y] = 0
    
    ex, ey = find(maps, 'E')#출구 좌표 알아내기
    while q:
        x, y, isOn = q.popleft()
        if x == ex and y == ey and isOn:
            answer = visited[isOn][x][y]
            break
        for dx, dy in MOVE:
            nx, ny = x + dx, y + dy
            nxtOn = isOn#이전 상황을 그대로 가져간다.
            if nx < 0 or nx >= ROW or ny < 0 or ny >= COL:continue
            if maps[nx][ny] == 'L':nxtOn = 1#당겼음.
            
            if visited[nxtOn][nx][ny] != -1 or maps[nx][ny] == 'X':continue
            visited[nxtOn][nx][ny] = visited[isOn][x][y] + 1
            q.append((nx, ny, nxtOn))
    return answer