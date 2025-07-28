'''
'25. 7. 29

1. aya, ye, woo, ma 발음만 할 수 있음
2. 조카가 발음할 수 있는 단어의 개수 return

|S| <= 100
|xi| <= 15
최대 한 번씩만 등장
'''
def solution(babbling):
    answer = 0
    for word in babbling:
        replace_word = word.replace('aya',' ').replace('ye',' ').replace('woo',' ').replace('ma',' ')
        if replace_word.replace(' ',''):continue
        answer += 1
    return answer