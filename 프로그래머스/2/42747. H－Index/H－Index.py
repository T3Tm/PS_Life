'''
'25. 08. 31

1. H-index 는 n편 중 h번 이상 인용된 논문이 h편 이상이고, 나머지 논문은 h번 이하 인용되었다면, h의 최댓값이 h-index이다.

0, 1, 3, 5, 6
정렬한 뒤 해당 숫자와 값을 통해서 몇 편인지 알 수 있다.

0 0 0 0 0
'''
from bisect import bisect_left as bl
def solution(citations):
    answer = -1
    citations.sort()#최소와 최대
    
    size = len(citations)
    for i in range(10001):
        idx = bl(citations, i)
        
        if i <= size - idx and idx <= i:
            answer = max(i, answer)
    return answer