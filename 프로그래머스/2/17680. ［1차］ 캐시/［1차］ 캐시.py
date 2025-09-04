'''
'25. 09. 04

1. LRU 알고리즘.
2. hit일 때는 1, miss 5


5, 10, 15, 20, 25, 30, 35, 40, 45, 50

5, 10, 15, 16, 17, 18, 19, 20, 21

5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
'''
def solution(cacheSize, cities):
    lru = {}
    
    answer = 0
    for idx, value in enumerate(cities):
        value = value.lower()
        if value in lru:#cacheHit
            answer += 1
        else:#cacheMiss
            answer += 5
            #가장 오래된 idx 삭제
        lru[value] = idx
        
        if len(lru) > cacheSize:
            target_key, target_value = '', 0x3f3f3f3f
            for key, data in lru.items():
                if data < target_value:
                    target_value = data
                    target_key = key
            del lru[target_key]
    return answer