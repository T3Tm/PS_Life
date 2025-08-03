'''
`25. 08. 03

1. 3개의 선분이 평행하게 놓여 있음 
2. 2개 이상의 선분이 겹치는 부분의 길이를 리턴

'''
def solution(lines):
    lines.sort()
    #  (x1, x2), (x3, x4), (x5, x6)
    #  x1 <= x3 <= x5 이것은 자명한 사실
    END = 202
    x_location = {}
    x_loc = set()
    for x, y in lines:
        x_location[x] = x_location.get(x, 0) + 1
        x_location[y] = x_location.get(y, 0) - 1
        x_loc.add(x)
        x_loc.add(y)
    x_loc = sorted(x_loc)
    for i in range(1, len(x_loc)):
        a, b = x_loc[i-1], x_loc[i]
        x_location[b] += x_location[a]
    
    pre_x_point = 200
    answer = 0
    for i in range(len(x_loc)):
        x_point = x_loc[i]
        if x_location[x_point] >= 2:
            pre_x_point = min(pre_x_point, x_point)
        else:
            answer += max(x_point - pre_x_point, 0)
            pre_x_point = 200
    #-100, -99, -98, -97, -96, -95
    #    , -99, -98, -97
    #           -98, -97, -96, -95
    #-99,-98,-97,-96,-95
    return answer