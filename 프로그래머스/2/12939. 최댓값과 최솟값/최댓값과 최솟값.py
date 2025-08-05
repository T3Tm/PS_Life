'''
'25. 08. 05
1. string 속에서 최소와 최대를 리턴할 수 있도록
2. keyPoint 음수가 들어올 수 있음. 그리고 수의 길이가 지정돼있지 않는다.

단순히 split하면 됨.
'''
def solution(s):
    #1. 빈칸을 기준으로 쪼개준다.
    #2. 정수로 바꾼뒤 정렬
    data = sorted(map(int, s.split()))
    return f"{data[0]} {data[-1]}"