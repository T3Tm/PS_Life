'''
'26. 1. 16.(금)

1. 어떤 섬으로 놀러 갈지 정하지 못 함.
2. 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정함.


1. 각 섬에서 dfs를 돌린 후 몇이 쌓여있는지 알아낸다.
'''
import sys
sys.setrecursionlimit(10005)

MOVE = (0, 1), (0, -1), (1, 0), (-1, 0)
visited = []
def dfs(x: int, y: int) -> int:
    global board
    if x < 0 or x >= len(visited) or y < 0 or y >= len(visited[0]):return 0
    if visited[x][y] or board[x][y] == 'X':return 0
    visited[x][y] = True
    
    ret = int(board[x][y])
    for dx, dy in MOVE:
        nx, ny = x + dx, y + dy
        ret += dfs(nx, ny)
    return ret
    
def solution(maps):
    global board
    for i in range(len(maps)):
        visited.append([False] * len(maps[i]))
    board = maps#맵 알려주기
    answer = []
    
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if visited[i][j] or board[i][j] == 'X':continue
            answer.append(dfs(i, j))
    
    answer.sort()
    if not answer:
        answer = [-1]
    return answer