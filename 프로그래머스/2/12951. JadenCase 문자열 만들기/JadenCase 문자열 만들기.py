'''
'25. 08. 06

1. 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열을 JadenCase라고 한다.
1 <= |s| <= 200

1. 첫 문자일때만 대문자이면 되는 것이고.
2. split을 활용하여 나눠준다.
3. upper()를 이용해서 대문자 만들기
'''
def solution(s):
    answer = ''
    tmp = ''
    for word in s:
        if word == ' ':
            answer += f'{tmp.capitalize()} '
            tmp = ''
        else:
            tmp += word
    answer += f'{tmp.capitalize()}'
    return answer