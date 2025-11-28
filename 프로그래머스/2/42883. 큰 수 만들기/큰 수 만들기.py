'''
'25. 11. 28.(금)

1. 큰 수 만들기

어떤 숫자에서 k개를 제거했을 때 얻을 수 있는 가장 큰 수를 구한다.

일단 당연한 것은 k개를 지웠을 때 나오는 숫자들의 길이가 모두 동일하다는 것이다.
=> 9라는 숫자, 즉 큰 수가 앞으로 올 수 있도록 적당히 앞에 숫자들을 제거해야 될 것이다.

1. 작은 숫자가 큰 수 앞에 있을 이유가 없음.
2. 앞에서부터 지나가면서 자신보다 뒤에 큰 수가 있다면 내 수는 가감히 삭제한다.
3. 결과를 확인한다.

예제 2번
2 : (4)
3 : (2, 5)
4 : (6)

1. for문을 돌린다.
2. 현재 바라보고 있는 index 기준 index + k 안에 나보다 큰 수가 있다면 나는 있을 이유가 없음.

이게 정배인데?
'''
from collections import deque
from heapq import*
def solution(number, k):
    answer = ''
    pq = []
    for i in range(min(k+1, len(number))):
        heappush(pq, (-int(number[i]), i))
        
    for idx, num in enumerate(number):
        while pq and pq[0][1] < idx:
            heappop(pq)
        #print(pq, f'현재 : {answer} 넣어야 되는 숫자 : {num} 삭제해야되는 숫자 : {k}')
        heappush(pq, (-int(number[min(idx + k, len(number) - 1)]), min(idx + k, len(number) - 1)))
        if k == 0 or (pq and int(num) >= -pq[0][0]):
            answer += num
        else:
            k-=1
    if k:
        answer = answer[:-k]
    return answer