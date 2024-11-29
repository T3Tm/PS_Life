def solution(queue1, queue2):
    INF = 0x3f3f3f3f
    answer = INF
    
    total = sum(queue1) + sum(queue2)
    half = total >> 1 
    q1_q2 = queue1 + queue2
    
    now = 0
    left = right = 0
    while right <= len(q1_q2):
        if now < half:
            if right == len(q1_q2):break
            now += q1_q2[right]
            right += 1
        elif now == half:break
        else:
            now -= q1_q2[left]
            left += 1
    if now == half:
        right -= 1#이래야 인덱스가 맞음
        if right + 1 < len(queue1):#하나 안에서 가능
            answer = right + 1 + len(queue2) + left
        elif right + 1 == len(queue1):#한 개로 해결가능
            answer = left
        else:
            answer = left + right - len(queue2) + 1
    q2_q1 = queue2 + queue1
    now = 0
    left = right = 0
    while right <= len(q2_q1):
        if now < half:
            if right == len(q2_q1):break
            now += q2_q1[right]
            right += 1
        elif now == half:break
        else:
            now -= q2_q1[left]
            left += 1
    
    if now == half:
        right -= 1#이래야 인덱스가 맞음
        if right + 1 < len(queue2):#하나 안에서 가능
            answer = min(answer,right + 1 + len(queue1) + left)
        elif right + 1 == len(queue2):#한 개로 해결가능
            answer = left
        else:
            answer = min(answer, left + right - len(queue2) + 1)
    return [answer,-1][answer == INF]