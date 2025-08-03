'''
'25. 08. 03
1. 1부터 6까지 적힌 주사위 4개 
2. 모두 같다면 1111 * p << len(set()) == 1
3. 3개가 같으면 (10 * p + q)^2  << len(set()) == 2
4. 2개씩 같으면 (p + q) * abs(p - q) << len(set()) == 2
5. 2개만 같으면 p, q, r (q * r) << len(set()) == 3
6. 4개가 모두 다르다면 min(a,b,c,d) << len(set()) == 4
'''
def solution(a, b, c, d):
    list_ = {}
    for tmp in [a,b,c,d]:
        list_[tmp] = list_.get(tmp, 0) + 1
        
    len_ = len(set([a,b,c,d]))
    answer = 0
    if len_ == 1: answer = 1111 * a
    elif len_ == 4: answer = min(a,b,c,d)
    elif len_ == 3:
        t = []
        for tmp in [a,b,c,d]:
            if list_[tmp] == 2:continue
            t.append(tmp)
        answer = t[0] * t[1]
    elif len_ == 2:
        if list_[a] == 2:
            l = [*list_.keys()]
            answer = (l[0] + l[1]) * abs(l[0] - l[1])
        else:
            t=q=0
            for p in [a,b,c,d]:
                if list_.get(p, 0) == 3:
                    t = p
                else:
                    q = p
            answer = (10 * t + q)**2
    return answer