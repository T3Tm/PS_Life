def solution(sequence, k):
    answer = [0, len(sequence) + 1]
    left = right = 0
    now = 0
    while right <= len(sequence):
        if now <= k:
            if right == len(sequence):break
            now += sequence[right]
            right += 1
        else:
            now -= sequence[left]
            left += 1
        if now == k:
            if answer[1] - answer[0] + 1 > (right-1) - left + 1:
                answer = [left, right - 1]
    
    return answer