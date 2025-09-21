'''
'25. 09. 21.(일)

1. 2조각으로만 나눠야 한다.
2. 결국에는 종류에만 관점을 둔다.
3. dict을 이용해서 갯수로 len == len을 하면 될 것 같다.


'''
def solution(topping):
    answer = 0
    front = {}
    back = {}
    for value in topping:
        back[value] = back.get(value, 0) + 1
        
    #하나씩 빼서 절반씩 한 것처럼 보이게 하기
    for value in topping:
        front[value] = front.get(value, 0) + 1
        
        back[value] -= 1#갯수 하나씩 줄이기
        if back[value] == 0:
            del back[value]#key 값 없애기
        
        #현재 갖고 있는 종류가 같으므로 괜찮음
        if len(front) == len(back):
            answer += 1
    return answer