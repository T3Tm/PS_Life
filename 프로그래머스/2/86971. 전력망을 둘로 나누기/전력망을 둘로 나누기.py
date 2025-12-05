'''
'25. 12. 5.(금)
1(9)
3(8)
2(1) 4(6)
  5(1) 6(1) 7(3)
      8 9
      
1. 1번을 루트로 한 트리라고 정의하자.
2. 리프노드부터 갯수를 세놓고
3. 한 간선을 잘랐을 때 몇 개로 나뉘는지 확인
'''
def dfs(x: int, graph: dict, tree: list, visited: list) -> int:
    if visited[x]:return 0
    visited[x] = 1
    ret = 1
    for nxt in graph[x]:
        ret += dfs(nxt, graph, tree, visited)
    tree[x] = ret#해당 노드의 자식 개수
    
    return ret
def solution(n, wires):
    answer = n + 1
    
    tree = [0] * (n + 1)
    
    ROOT = 1
    graph = {i : []for i in range(1, n + 1)}
    
    for a, b in wires:
        graph[a].append(b)
        graph[b].append(a)
    visited = [0] * (n + 1)
    dfs(1, graph, tree, visited)
    
    for a, b in wires:
        answer = min(abs(tree[1] - min(tree[a], tree[b]) * 2), answer)
    return answer