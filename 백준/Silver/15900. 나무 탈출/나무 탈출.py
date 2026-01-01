import sys
input = sys.stdin.readline
'''

'''
from collections import deque
def solution() -> None:
    n = int(input())
    graph = {i: []for i in range(1, n+1)}

    for _ in range(n-1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    #리프노드까지 거리 구하기
    q = deque([1])
    visited = [-1] * (n + 1)
    visited[1] = 0

    total = 0
    while q:
        x = q.popleft()
        now_q = len(q)
        for nxt in graph[x]:
            if visited[nxt] != -1:continue
            visited[nxt] = visited[x] + 1
            q.append(nxt)

        #리프노드 구했음.
        if now_q == len(q):
            total += visited[x]
    
    print(['No','Yes'][total&1])
    
    

if __name__ == '__main__':
    solution()