'''
'25. 08. 06

1. x의 모든 0을 제거
2. x의 길이를 c라고 하면, c를 2진법으로 바꾸기

|S| 
ex) 1로만 이뤄진 '1' * 150,000라고 한다면
2. 2진법으로 교체하는 것은 log2 시복
한 번 할 때마다 확확 줄기 때문에 구현으로 풀면 됨.
'''
def solution(s):
    #변환 횟수, 제거된 0 갯수
    answer = [0, 0]
    info = [len(s), s.count('0'), s.count('1')]
    while not (info[0] == 1 and info[2] == 1):
        #0의 갯수를 더해주기
        answer[1] += info[1]
        #2진법으로 나타내기
        s = bin(info[2])[2:]
        info = [len(s), s.count('0'), s.count('1')]
        #변환 횟수 한 번 더해주기
        answer[0] += 1
    return answer