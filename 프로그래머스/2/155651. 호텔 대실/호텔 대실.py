'''
'25. 12. 7.(일)

1. 한 번 사용한 객실은 퇴실 10분간 청소 후 다음 손님

1. 시작시간을 기준으로 오름차순 정렬
2. 우선순위 큐에 넣고 빨리 퇴실하는 시간 기준으로 우큐에서 빼면 된다.
3. 현재 우큐에 들어있는 갯수만큼 방의 호실을 갖고 있으면 됨.
'''
from heapq import*
def times(t: str, plus: int) -> int:
    h, m = map(int, t.split(':'))
    if m + plus >= 60:
        m = m + plus - 60
        h += 1
    else:
        m += plus
    return h * 100 + m

def timess(t: int, plus: int) -> int:
    h, m = t // 100, t % 100
    if m + plus >= 60:
        m = m + plus - 60
        h += 1
    else:
        m += plus
    return h * 100 + m

def solution(book_time):
    answer = 0
    pq = []
        
    book_time.sort(key = lambda x:
             (times(x[0], 0), times(x[1], 0))
    )
    
    for st, et in book_time:
        while pq and timess(pq[0], 10) <= times(st, 0):
            heappop(pq)
        heappush(pq, times(et, 0))
        answer = max(answer, len(pq))
    return answer