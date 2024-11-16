def solution(babbling):
    answer = 0
    #연속해서 같은 발음하는 것
    for text in babbling:
        t = text.replace('aya', 'A').replace('ye', 'B').replace('woo', 'C').replace('ma', 'D')
        #연속 x, 소문자 있으면 안됨.
        flag = 0
        for i in range(1, len(t)):
            
            if t[i-1] >= 'a' or t[i] >= 'a':
                flag = 1
                break
            if t[i-1] == t[i]:
                flag = 1
                break
        if flag:continue
        if len(t) == 1 and t[0] >= 'a':continue
        answer+=1
    return answer