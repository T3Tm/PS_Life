'''
'25. 11. 27.(목)

1. 일차선 다리에 트럭 여러 대가 지나가려고 함. (정해진 순으로 건너려 합니다)
2. 트럭이 최대 bridge_length 만큼 올라갈 수 있으며, weight까지는 버틸 수 있다.

단순 구현 문제..
'''
from collections import deque
def solution(bridge_length, weight, truck_weights):
    answer = 0
    now_weight = 0
    dq = deque()
    
    i = 0
    for idx, now_truck in enumerate(truck_weights):
        #같이 태울 수 없음.
        
        #현재 now_truck을 태울 때까지 얼만큼 전진하여 빼줘야 되는지 확인
        while dq and ((now_weight + now_truck > weight) or (bridge_length <= (answer - dq[0][1]))):
            pre_weight, ans = dq.popleft()#무게, 이전에 투입된 시간
            now_weight -= pre_weight
            out_time = bridge_length - (answer - ans)
            
            #print(out_time)
            
            answer += max(out_time - 1, 0)#젤 앞에 있는 아이가 앞으로 빠져나갈 시간

        answer += 1
        dq.append([now_truck, answer])#1번째 칸에 올려졌음.
        now_weight += now_truck
        i += 1
        print(answer, dq)
        
    if dq:
        answer += bridge_length - (answer - dq[-1][1])
    return answer