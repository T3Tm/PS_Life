'''
'25. 12. 22.(월)
1. 1번 정점에서 각 정점으로 간다.
2. N개의 정점에서 K 시간 이하로 걸리는 마을에서만 주문을 받는다.

다익스트라를 이용하여 풀이 진행.
'''
from heapq import*
def solution(N: int, road: list, K: int):
    answer = 0
    
    pq = []
    
    graph = {i : []for i in range(1, N + 1)}
    for (a, b, c) in road:
        graph[a].append((b, c))
    
        graph[b].append((a, c))
    
    INF = 0x3f3f3f3f
    dp = [INF] * (N + 1)
    dp[1] = 0
    
    heappush(pq, (0, 1))
    while pq:
        dst, cur = heappop(pq)
        if dp[cur] < dst:continue
        
        for nxt, cost in graph[cur]:
            nxt_cost = dst + cost
            if dp[nxt] <= nxt_cost:continue
            dp[nxt] = nxt_cost
            heappush(pq, (nxt_cost, nxt))
              
    for i in range(1, N + 1):
        answer += dp[i] <= K
    return answer