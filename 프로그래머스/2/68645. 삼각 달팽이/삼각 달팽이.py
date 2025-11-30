'''
'25. 11. 30.(일)

1. n이 주어진다.
2. n개의 삼각형을 반시계 방향으로 값을 채우기
'''
def solution(n):
    answer = [[0] * (n + 1)for _ in range(n + 1)]
    i = j = 0
    number = 1
    
    dx = [1, 0, -1]
    dy = [0, 1, -1]
    direc = 0
    while 1:
        answer[i][j] = number
        ni, nj = i + dx[direc], j + dy[direc]
        #경게면 체크를 최대 3번
        count = 0
        while (not (ni >= 0 and nj >= 0 and ni < n and nj < n) or answer[ni][nj])and count < 3:
            direc = (direc + 1) % 3
            ni, nj = i + dx[direc], j + dy[direc]
            #없으면 해당 부분으로 값을 넣으면 돼서
            count += 1
        if count == 3:break
        i, j = ni, nj
        number += 1
    
    ret = []
    for i in range(n):
        for j in range(i + 1):
            ret.append(answer[i][j])
    return ret