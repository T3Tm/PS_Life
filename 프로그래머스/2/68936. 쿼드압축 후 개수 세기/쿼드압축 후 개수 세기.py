'''
'25. 11. 13.(목)

1. 0과 1로 이뤄진 2^n * 2^n 배열이 있다.

1. S 내부에 있는 모든 수가 같은 값이라면, 한 값으로 압축한다.
2. S를 정확히 4개의 균일한 정사각형 영역으로 쪼갠다.

최종적으로 [0의 개수, 1의 개수] 리턴

분할정복으로 문제를 풀이하면 될 듯 싶다.
시작 x, y
끝 x, y를 리턴한다.
'''
#
def quad_compression(sx: int, sy: int, ex: int, ey: int, board: list) -> list:
    ret = [0, 0]
    for row in range(sx, ex):
        for col in range(sy, ey):
            ret[board[row][col]] += 1
    
    #둘 중 하나가 0이라면 바로 리턴
    if ret[0] == 0 or ret[1] == 0:
        return [+(ret[0] > 0), +(ret[1] > 0)]
    
    alpha = (ex - sx) >> 1
    ret1 = quad_compression(sx, sy, sx + alpha, sy + alpha, board)
    ret2 = quad_compression(sx, sy + alpha, sx + alpha, ey, board)
    ret3 = quad_compression(sx + alpha, sy, ex, sy + alpha, board)
    ret4 = quad_compression(sx + alpha, sy + alpha, ex, ey, board)
    
    
    for i in range(2):
        ret[i] = ret1[i] + ret2[i] + ret3[i] + ret4[i]
    
    return ret
def solution(arr):
    answer = quad_compression(0, 0, len(arr), len(arr), arr)
    return answer