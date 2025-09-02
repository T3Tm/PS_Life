'''
'25. 09. 02

1. 각 배포마다 몇 개의 기능이 배포되는지를 반환하여라.

7, 3, 9

이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

5, 10, 1, 1, 20, 1

단순 구현문제인가 싶은데.?
1. 맥시멈 데이를 구하고
2. 현재 구하는 것이 앞에서 구한 맥시멈 데이에 포함이 된다면 추가적으로 배포가 가능하다.
3. 아니라면 끊고 배포를 진행하면 된다.
'''
from math import ceil
def solution(progresses, speeds):
    answer = []
    maximum_progress = ceil((100 - progresses[0])/speeds[0])
    count = 0
    for pro, spe in zip(progresses, speeds):
        progress = ceil((100 - pro)/spe)
        if maximum_progress < progress:#끊고 넘어가야 함.
            answer.append(count)
            maximum_progress = progress
            count = 1
        else: count += 1
    
    answer.append(count)
    return answer