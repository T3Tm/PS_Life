'''
'25. 09. 08.(월)

1. 일정 피로도를 사용해서 탐험을 진행할 수 있음.
2. 하루에 한 번씩 탐험 진행
3. 현재 피로도, 최소 필요 피로도, 소모 피로도에 관해서 최대 던전 수를 구하여라.

1 <= k <= 5000

1 <= 던전의 개수 <= 8
8!으로 모든 경우의 수를 돌린다.
'''
from itertools import permutations as per
def solution(k, dungeons):
    answer = 0
    for comb in per(dungeons):
        #comb 순서대로 돌았을 때 얼만큼 돌 수 있는지 확인
        inner_k = k
        count = 0
        for at_least, spend in comb:
            if inner_k < at_least:continue
            inner_k -= spend
            count += 1
        
        answer = max(answer, count)
    
    return answer