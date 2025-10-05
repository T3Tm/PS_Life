'''
'25. 10. 5.(일)
1. 정수가 있고, 배열의 각 언소들에 대해 자신보다 뒤에 있는 숫자 중
자신봐 크면서 가장 가까이 있는 수를 뒷 큰수
2. 뒤에 있는 수인데, 가장가까운 수

stack을 이용해서 만들기

1. 첫 번째 수를 넣기
2. stack의 top이 현재 보고 있는 숫자보다 작다면 배열에 넣어준다.
'''
def solution(numbers):
    answer = [-1] * len(numbers)
    s = [[numbers[0], 0]]#stack
    
    for i in range(1, len(numbers)):
        value = numbers[i]
        #value
        while s and s[-1][0] < value:
            v, idx = s.pop()
            answer[idx] = value
        
        s.append((value, i))
    return answer