'''
'25. 11. 2(일)

1. 2 * 2 형태의 똑같은 모양이 4개가 있다면 점수를 얻는다.



1. (0, 0) -> (m - 1, n - 1) 여기까지 for문
2. 좌측 상단부터 오른쪽, 아래, 오른쪽 아래를 체크해봐야 된다.
3. 삭제 한꺼번에 기록
'''
def find(row: int, col: int, board: list) -> bool:
    return board[row][col] == board[row + 1][col] == board[row][col + 1] == board[row + 1][col + 1]


def down_block(board: list) -> list:
    ret = [[''] * len(board[0])for _ in range(len(board))]
    #맨 아래 블럭부터 당겨주기
    
    for col in range(len(board[0])):
        #맨 아래 블럭부터
        insert_idx = len(board) - 1
        
        for row in range(insert_idx, -1, -1):
            if board[row][col]:
                ret[insert_idx][col], board[row][col] = board[row][col], ''
                insert_idx -= 1
    return ret
def solution(m, n, board):
    answer = 0
    
    for row in range(m):
        board[row] = [*board[row]]
        
    #print(board)
    while 1:
        removes = []
        for i in range(m-1):
            for j in range(n-1):
                if board[i][j] and find(i, j, board):
                    removes.append((i, j))
                    removes.append((i, j + 1))
                    removes.append((i + 1, j))
                    removes.append((i + 1, j + 1))
        #print(1)            
        if removes:
            while removes:
                x, y = removes.pop()
                if board[x][y]:
                    answer += 1
                board[x][y] = ''
            board = down_block(board)
        else:
            break
        
    return answer