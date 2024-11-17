from collections import deque
def solution(elements):
    comb = set()
    #부분 수열의 합으로 만들 수 있는 가짓 수
    #연속 부분 수열 합 << 슬라이딩 윈도우
    
    for size in range(1, len(elements) + 1):#크기
        #전처리
        data = deque()
        hap = 0
        for i in range(size):
            data.append(elements[i])
            hap += elements[i]
        
        comb.add(hap)
        
        for idx in range(size, len(elements)+size-1):
            pre = data.popleft()
            hap -= pre
            
            nex = elements[idx%len(elements)]
            data.append(nex)
            hap += nex
            
            comb.add(hap)
    return len(comb)