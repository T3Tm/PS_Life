'''
'25. 10. 16.(목)

1. 스파크 -> 라이트닝 볼트 -> 썬더

1. skill에 맞게끔 있는지 들어갔는지만 확인하면 된다.
'''
def solution(skill, skill_trees):
    answer = 0
    
    #무조건 
    order = {}
    for idx, value in enumerate(skill):
        order[value] = idx
    
    for trees in skill_trees:
        last_idx = 0
        for value in trees:
            if value in order:
                now_idx = order[value]
                if now_idx == last_idx:
                    last_idx += 1
                else:
                    break
        else:
            answer += 1        
    return answer