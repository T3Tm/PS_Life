'''
'25. 10. 18.(토)

1. fees[1] + ceil(max(전체 시간 - fees[0], 0)/10) * fees[3] 
으로 계산하면 됨.

2. 차량 번호가 작은 자동차부터 리턴해야 된다.

'''
import math
def interpret_time(time: str) -> int:
    hour, minutes = map(int, time.split(':'))
    return hour * 60 + minutes

def get_gap_time(last_time: str, now_time: str) -> int:
    return interpret_time(now_time) - interpret_time(last_time)

def solution(fees, records):
    answer = []
    #fees = [기본시간, 기본요금, 단위당 시간, 금액]
    #1438
    #461
    # records = [
    #     "시간V차량번호V입출"
    # ]
    #차량 번호 : [입출, 시간, 마지막으로 들어온 시간]
    save = {}
    
    for record in records:
        time, number, in_out = record.split()
        save[number] = save.get(number, ["IN", 0, time])
        if in_out == 'IN':
            save[number][0] = 'IN'
            save[number][2] = time
            
        #나가는 것이라면
        else:
            save[number][0] = "OUT"
            gap = get_gap_time(save[number][2], time)
            save[number][1] += gap
            save[number][2] = time
            
    time_to_fee = {}
    #아직 안 나간 차들이 있다면 나간 것 처리해주기
    #1. fees[1] + ceil(max(전체 시간 - fees[0], 0)/10) * fees[3]
    for key in save.keys():
        if save[key][0] == 'IN':
            gap = get_gap_time(save[key][2], '23:59')
            save[key][1] += gap
        #이제 금액 계산하기
        time_to_fee[key] = fees[1] + math.ceil(max(save[key][1] - fees[0], 0) / fees[2]) * fees[3]
    
    for key, value in sorted(time_to_fee.items(), key = lambda x: x[0]):
        answer.append(value)
    return answer