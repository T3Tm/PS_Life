'''
'25. 08. 15

1. k개를 골라서 상자 하나에 담아 판매한다.
2. 귤을 크기별로 분류 -> 서로 다른 종류의 수를 최소화한다.

정리하면 len(tangerine)Ck 서로 다른 종류가 최소
즉, 중복이 되게 해서 갯수를 줄여라가 포인트가 될 것이다.

그러면 각 번호와 갯수를 구해서 내림차순으로 나열하고 k개를 고르면 되겠다.
'''
def solution(k, tangerine):
    answer = 0
    new_dict = {}
    for num in tangerine:
        new_dict[num] = new_dict.get(num, 0) + 1
    #(key, value)
    new_list = sorted(new_dict.items(), key=lambda x:(-x[1]))
    
    for i in range(len(new_list)):
        answer += 1
        if k - new_list[i][1] <= 0:break
        k -= new_list[i][1]
    return answer