'''
'25. 7. 30
1. 네 개의 좌표가 주어졌을 때 두 직선이 평행이 되는 경우가 있는지 확인
2. 경우의 수는 4C2 이다.
3. 평행이라는 것은 중학교 수업으로 생각하면 기울기가 같고 y절편이 다른 것을 말한다.
3번 사항이 필요없음 단순히 기울기가 같기만 하면 됨.
'''
from itertools import combinations
def solution(dots):
    answer = 0
    
    #x, y, index
    make_list = [[dots[i][0], dots[i][1], i]for i in range(len(dots))]
    
    #combinations를 갖고 2개를 조합을 가져오기
    for comb in combinations(make_list, 2):
        remain_dots = []
        for i in range(4):
            if i in (comb[0][2], comb[1][2]):continue
            remain_dots.append(make_list[i])
        dot1, dot2 = comb
        dot3, dot4 = remain_dots
        #기울기 = y증가량 / x증가량 << 나누기는 부동소수점 에러가 생길 수 있으므로
        # X1기울기 == X2기울기
        # y1 증가량 * x2증가량 == x1증가량 * y2증가량
        if (dot2[1] - dot1[1]) * (dot4[0] - dot3[0]) == (dot2[0] - dot1[0]) * (dot4[1] - dot3[1]): answer = 1
        
    return answer