'''
'25. 10. 13.(월)

1. N행 4열 
2. 같은 열을 연속해서 밟을 수 없다.
3. 최고점을 얻어내야 한다.

DP이다.
'''
import sys
sys.setrecursionlimit(120000)
dp = [[-1] * 5 for _ in range(100002)]
board = []
def down(row: int, col: int, boundary: int) -> int:
    global dp, board
    if row == boundary:
        return 0
    if dp[row][col]!=-1:
        return dp[row][col]
    dp[row][col] = 0
    #4개의 열 중 col과 다른 곳으로만 가야 함.
    for target in range(4):
        if col == target:continue
        dp[row][col] = max(dp[row][col], down(row + 1, target, boundary) + board[row][col])
    
    return dp[row][col]

def solution(land):
    global board
    answer = 0
    for row in land:
        board.append(row[::])
    # print(board)
    for i in range(4):
        answer = max(answer, down(0, i, len(land)))
    return answer