'''
'25. 09. 26.(금)

1. J(A, B)를 알아내어라.
2. 2글자씩 끊어서 다중집합을 만드시오.
3. 대소문자는 같은 것이다..?
'''
def solution(str1, str2):
    answer = 0
    
    str1_list = []
    str2_list = []
    
    for i in range(len(str1) - 1):
        if str1[i : i + 2].isalpha():
            str1_list.append(str1[i : i + 2].lower())
    
    for i in range(len(str2) - 1):
        if str2[i : i + 2].isalpha():
            str2_list.append(str2[i : i + 2].lower())
    
    str1_list.sort()
    str2_list.sort()
    
    B_check = [0] * len(str2_list)
    
    up = down = 0
    for i in range(len(str1_list)):
        for j in range(len(str2_list)):
            if B_check[j]:continue
            if str1_list[i] == str2_list[j]:
                B_check[j] = 1
                up += 1#교집합
                break
        else:
            down += 1
    #교집합 갯수 추가하기
    down += B_check.count(0) + up
    # print(up)
    # print(down)
    if down == 0:answer = 65536
    else:
        answer = int(up / down * 65536)
    # if len(str1_set | str2_set) == 0:answer = 65536
    # else:
    #     answer = int(len(str1_set & str2_set) / len(str1_set | str2_set) * 65536)
    return answer