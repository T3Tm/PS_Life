'''
'25. 08. 10
1. 노란색과 갈색으로 이뤄진 카펫이 있을 때 해당 카펫의 가로 세로 길이를 구하여라
2. 가로의 길이는 세로와 같거나 세로보다 길다

세로 <= 가로

세로 : x
가로 : y

x * y = brown * yellow가 나와야 한다.

brown * yellow <= 10^10
테두리 한 줄만 갈색으로 돼있다.

xxxxxxxx
xxxxxxxx
xxxxxxxx
xxxxxxxx
xxxxxxxx
xxxxxxxx

brown을 기준으로 가로의 갯수를 지정하면 세로는 정해질 수 밖에 없다.
그럼 갯수가 나오게 된다.

brown_x = 1 .. x
brown_y = 
(전체 - (가로 * 2))
xxxxx
x   x
x   x
xxxxx
'''
def solution(brown, yellow):
    answer = []

    for brown_x in range(1, brown + 1):
        if (brown - (brown_x * 2)) % 2:continue
        brown_y = (brown - (brown_x * 2)) // 2 + 2
        
        yellow_x = brown_x - 2
        yellow_y = brown_y - 2
        if yellow_x <= 0 or yellow_y <= 0:continue
        if yellow_x * yellow_y == yellow and yellow_x>=yellow_y:
            answer = [brown_x, brown_y]
            break
    return answer