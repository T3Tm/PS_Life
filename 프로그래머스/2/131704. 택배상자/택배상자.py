'''
'25. 10. 14.(화)

1. 보조 컨테이너 벨트는 stack이다.

로직
1. 1,2,3,4,5 순서대로 1<= x <= len(order)를 보낸다.
2. 현재 번호가 아닐 시 stack에 넣는다.
3. 몇 개가 담기는지 확인
'''
def solution(order):
    answer = 0
    s = []
    idx = 0
    for i in range(1, len(order) + 1):
        while s and s[-1] == order[idx]:
            idx += 1
            s.pop()
            answer += 1
        if order[idx] == i:
            answer += 1
            idx += 1
        else:
            s.append(i)
    while s and s[-1] == order[idx]:
        idx += 1
        s.pop()
        answer += 1
        
    return answer