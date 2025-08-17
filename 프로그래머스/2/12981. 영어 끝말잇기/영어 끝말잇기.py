'''
'25. 08. 17

1. 1부터 n까지 번호가 붙어있는 N명의 사람이 영어 끝말잇기를 하고 있다.
2. 끝말잇기처럼 앞서 말한 단어를 다시 말할 수 없다.

1. N명이서 하기 때문에 N명이 지나면 새로운 라운드가 진행된다.
2. 앞서 말한 것은 dict or set으로 관리하고
3. 라운드는 현재 라운드로 관리하면 된다.
'''
def solution(n, words):
    answer = [0, 0]

    now_round = 1
    pre_words = set()#단어 나온 것들
    last_word = words[0][0]#마지막 사용한 단어
    while 1:
        is_out = 0
        who = -1
        i = 0
        while i != n and (now_round - 1) * n + i != len(words):
            if words[(now_round - 1) * n + i] in pre_words or last_word != words[(now_round - 1) * n + i][0]:
                is_out = 1
                who = i + 1
                break
            pre_words.add(words[(now_round - 1) * n + i])
            #print(words[(now_round - 1) * n + i])
            last_word = words[(now_round - 1) * n + i][-1]
            i += 1
        if (now_round - 1) * n + i == len(words):break
        if is_out:
            answer = [who, now_round]
            break
        now_round += 1
            
        
    return answer