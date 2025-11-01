'''
'25. 11. 1.(토)

1. 파일 이름 순
2. 정규표현식을 이용하면 쉽게 풀릴 것 같다.

head, number, tail로 자르는데.

head는 숫자가 아닌 최소 한글자 문자
처음부터 

number 한글자에서 최대 다섯 글자의 연속된 숫자

tail은 그 나머지 부분.

'''
import re
def solution(files):
    answer = []
    pattern = re.compile('\d{1,5}')
    for idx, word in enumerate(files):
        p = pattern.search(word)
        s, e = p.span()
        answer.append([word[:s], word[s:e], word[e:], idx])
    answer.sort(key=lambda x: (x[0].lower(), int(x[1]), x[3]))
    for idx, word in enumerate(answer):
        answer[idx] = word[0] + word[1] + word[2]
    return answer