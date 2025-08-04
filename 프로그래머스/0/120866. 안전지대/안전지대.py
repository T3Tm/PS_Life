'''
'25. 08. 04
1. 지뢰와 인접한 위, 아래, 좌, 우, 대각선 칸을 위험지역으로 분류


1. 지뢰가 있는 곳을 확인하면 위 아래 좌 우 대각선을 처리하고
2. 위험지역 갯수만 세준다.
3. 전체 갯수에서 빼준다.
'''
#위, 오위, 오, 오아, 아, 왼아, 왼, 왼위
dx = [-1,-1,0,1,1,1,0,-1]
dy = [0,1,1,1,0,-1,-1,-1]
def processing(board: list) -> int:
    result = [[0] * len(board) for _ in range(len(board))]
    
    for row in range(len(board)):
        for col in range(len(board)):
            if not board[row][col]:continue
            #지뢰지역이므로 위, 아래, 좌, 우, 대각선 위험지역으로 처리
            #현재 지뢰지역
            result[row][col] = 1
            for i in range(8):
                nx = row + dx[i]
                ny = col + dy[i]
                if nx < 0 or nx >= len(board) or ny < 0 or ny >= len(board):continue
                #나머지 위험지역
                result[nx][ny] = 1
    
    #전체 1의 갯수 세주기
    ret = 0
    for row in result:
        ret += row.count(1)
    return ret
def solution(board):
    #보드를 넣으면 위험지역 갯수 넘겨주기.
    data = processing(board)
    return len(board)**2 - data