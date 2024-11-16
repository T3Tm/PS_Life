def solution(survey, choices):
    answer = ''
    trans = {'RT' : 'RT', 'TR': 'RT',
             'FC' : 'CF', 'CF' : 'CF',
            'MJ' : 'JM' , "JM" : 'JM',
            'AN' : 'AN', 'NA' : "AN"}
    
    score = {'RT': {'R' : 0, 'T' : 0},
            'CF' : {'C' : 0, 'F' : 0},
            'JM' : {'J' : 0, 'M' : 0},
            'AN' : {'A' : 0, 'N' : 0}}
    for div, num in zip(survey, choices):
        if num == 4:continue#점수 없음
        nex = trans[div]
        if nex != div:#점수 뒤바꾸기
            num = 8 - num
        div = nex
        if num < 4:
            score[div][div[0]] =  score[div][div[0]] + 4 - num
        else :
            score[div][div[1]] =  score[div][div[1]] + num - 4
    
    for key, value in score.items():
        front = key[0]
        back = key[1]
        if value[front] > value[back]:
            answer += front
        elif value[front] < value[back]:
            answer += back
        elif front > back:
            answer += back
        else:
            answer += front
    return answer