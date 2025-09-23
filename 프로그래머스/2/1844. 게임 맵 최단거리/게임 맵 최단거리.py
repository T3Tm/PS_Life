'''
'25. 09. 23.(화)

bfs를 이용하여 움직이면 제일 빠르게 최단거리로 나갈 수 있다.

1. 0은 벽이 있는 자리, 1은 없는 자리이다.
2. 탈출할 수 있으면 answer, 아니면 -1을 리턴한다.
'''
from collections import deque
def bfs(n: int, m: int, board: list) -> int:
    #초기 위치 설정
    queue = deque([[0, 0]])
    
    #방문 배열
    visited = [[-1] * m for _ in range(n)]
    MOVE = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    
    #처음 위치 0
    visited[0][0] = 1
    while queue:
        x, y = queue.popleft()
        #탈출하였음
        if x == n - 1 and y == m - 1:
            return visited[x][y]
        for dx, dy in MOVE:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:continue
            if visited[nx][ny]!= -1 or board[nx][ny] == 0:continue
            visited[nx][ny] = visited[x][y] + 1
            queue.append([nx, ny])
    #마지막에 탈출하지 못 하였을 때
    return -1
def solution(maps):
    return bfs(len(maps), len(maps[0]), maps)