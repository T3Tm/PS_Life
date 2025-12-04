'''
누가 앉든 
'''
def solution(weights):
    answer = 0
    
    weight_2 = {}
    weight_3 = {}
    weight_4 = {}
    for w in weights:
        weight_4[w * 4] = weight_4.get(w * 4, 0) + 1
    
    for w in weights:
        answer += weight_4.get(w * 3, 0)
        weight_3[w * 3] = weight_3.get(w * 3, 0) + 1
    
    print(weight_3)
    for w in weights:
        answer += weight_2.get(w * 2, 0)#같은 곳에 있는지 확인
        answer += weight_3.get(w * 2, 0)
        answer += weight_4.get(w * 2, 0)
        weight_2[w * 2] = weight_2.get(w * 2, 0) + 1
    
    
    return answer