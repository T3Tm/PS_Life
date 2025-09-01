def solution(clothes):
    category = {}
    for name, cate in clothes:
        if cate in category:
            category[cate].append(name)
        else:
            category[cate] = [name]
    
    answer = 1
    for key in category.keys():
        answer*=len(category[key]) + 1
    return answer - 1