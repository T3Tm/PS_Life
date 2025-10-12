'''
'25. 10. 12.(일)

모든 음식의 스코빌 지수가 k이상이 되기 위해서는 몇 번 섞어야 하는지 최소 횟수를 리턴하여라

1. 새로운 스코빌 = 가장 맵지 않은 음식의 스코빌 지수 + 두 번째로 맵지 않은 스코빌 * 2
2. 모든 스코빌이 k이상이지 않으면 -1
'''
from heapq import*
def solution(scoville, K):
    answer = 0
    heapify(scoville)
    while len(scoville) > 1 and scoville[0] < K:
        top = heappop(scoville)
        second_top = heappop(scoville)
        total = top + second_top * 2
        heappush(scoville, total)
        answer += 1
    if scoville and scoville[0] < K:
        answer = -1
    return answer