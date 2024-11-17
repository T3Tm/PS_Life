def solution(k, tangerine):
    answer = 0
    #k개를 골라서 상자 하나에 담아 판매한다 .
    # 귤의 크기가 일정하지 않다.
    # k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return
    # k개 고르기
    save = {}
    for data in tangerine:
        save[data] = save.get(data, 0) + 1
    
    save_list = sorted(save.items(),key=lambda x: -x[1])
    #큰 것부터
    for data, value in save_list:
        if k <= 0:break
        k -= value
        answer += 1
    return answer