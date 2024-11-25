from bisect import bisect_left
def solution(citations):
    answer = 0
    
    citations.sort()
    print(citations)
    size = len(citations)
    
    for h in range(max(citations) + 1):
        idx = bisect_left(citations, h)
        
        better_h_count = size - idx
        small_h_count = idx + 1 - (citations[idx] != h) 
        if better_h_count >= h and small_h_count <= h:
            answer = max(answer, h)
    return answer