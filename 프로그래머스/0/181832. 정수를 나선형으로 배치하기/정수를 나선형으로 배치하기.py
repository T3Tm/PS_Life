'''
'25. 7. 29

1. N > 0
2. 나선형으로 배치해보시오

1. insert_number 변수 생성
2. x값, y값 생성
3. 순서대로 넣어주기
'''
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
answer = [] #n * n 행렬 만들기
def is_boundary(x: int, y: int, direction: int, n: int)->bool:
    x += dx[direction]
    y += dy[direction]
    
    if 0 <= x < n and 0 <= y < n:
        if answer[x][y]: return True
        return False
    return True

def change(direciton: int) -> int:
    return (direciton + 1) % 4
    
#여기서 전역변수 처리해줘야함.
def solution(n):
    global answer
    answer = [[0] * n for _ in range(n)]
    x = y = 0
    insert_number = 1
    direction = 1 #방향 
    
    '''
    동 : 1
    남 : 2
    서 : 3
    북 : 0
    
    '''
    while (0 <= x < n and 0 <= y < n) and answer[x][y] == 0:#0이 아니면 이미 숫자가 삽입된 경우
        answer[x][y] = insert_number #일단 숫자 기입

        if is_boundary(x, y, direction, n):#경계면이 넘어갔다면
            direction = change(direction)#방향만 바꾸고

        #한 번씩 앞으로 전진
        x += dx[direction]
        y += dy[direction]
        insert_number += 1 #다 넣고 나서 번호 증가
    
    return answer