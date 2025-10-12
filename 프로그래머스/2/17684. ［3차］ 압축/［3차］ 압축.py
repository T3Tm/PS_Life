'''
'25. 10. 12.(일)

1. 길이가 1인 모든 단어를 포함한 사전을 초기화한다.
    == 알파벳으로 dict 초기화
2. 가장 긴 문자열 찾는다?
3. 색인 번호를 출력, w 제거
4. 입력에서 처리되지 않은 글자가 있으면 w+c등록한다.

1. dict를 알파벳으로 초기화
2. 모든 문자열을 for문으로 돌면서
3. dict에 있으면서 최대 문자열을 찾는다.
4. 그 번호 출력한다. 해당 단어 제거
'''
def solution(msg):
    answer = []
    lzw = {}
    for i in range(26):
        lzw[chr(i + 65)] = i + 1
    update_number = 27
    #문자 하나하나 돌기
    idx = 0
    while idx < len(msg):
        word = ''
        
        catch_word = ''
        next_idx = 0
        for alpha in range(idx, len(msg)):
            word += msg[alpha]
            if word in lzw:
                catch_word = word
                next_idx = alpha + 1
                idx = next_idx
        if catch_word != '':
            answer.append(lzw[catch_word])
            
        if next_idx != len(msg):
            lzw[catch_word + msg[next_idx]] = update_number
            update_number += 1
    return answer