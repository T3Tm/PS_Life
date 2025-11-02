'''
'25. 11. 2(일)

1. 모든 유저는 [유저 아이디]로 구분한다.
2. Enter 들어왔습니다., Leave 나갔습니다. Change 이름 변경

1. split으로 first, second, third를 나누기

2. 마지막으로 변경된 이름을 기준으로 들어가야 한다.
'''
def solution(record):
    answer = []
    names = {}#이름을 기록해 놓기
    for line in record:
        first, second, *third = line.split()
        if third:
            names[second] = third[0]#이름을 기록해놓기
        
    for line in record:
        f, s, *t = line.split()
        name = names[s]
        last = ''
        if f == 'Enter':
            last = '들어왔습니다.'
        elif f == 'Leave':
            last = '나갔습니다.'
        sentence = f'{name}님이 {last}'
        
        if last:
            answer.append(sentence)
    return answer