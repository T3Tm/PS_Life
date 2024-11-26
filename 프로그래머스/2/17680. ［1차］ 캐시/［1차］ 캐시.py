
def solution(cacheSize, cities):
    if cacheSize == 0: return len(cities) * 5
    dic = {}
    cnt = 0
    for i in range(len(cities)):
        t=cities[i].upper()
        if t in dic:
            dic[t] = i
            cnt += 1
        else:
            if len(dic) + 1 <= cacheSize:
                dic[t] = i
                cnt += 5
            else:
                item = sorted(dic.items(), key=lambda x: -x[1])
                del dic[item[-1][0]]
                dic[t] = i
                cnt += 5
    return cnt