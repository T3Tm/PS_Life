'''
'25. 09. 13.(토)

1. 튜플의 순서는 바뀌어도 상관없다.

순서
1. ,을 기준으로 자른다.
2. {}이 들어간 튜플을 set(), 길이 순으로 리스트를 만든다.
3. 정렬을 할 때 길이 순으로 정렬한다.
4. 그리고 출력
'''
def solution(s):
    split_s = s[1:-1].split(',')

    tmp = []#같은 튜플 집합
    
    num_list = []#리스트 만들기
    #print(split_s)
    for splits in split_s:
        #하나의 숫자들이 나오게 된다.
        num = int(splits.lstrip('{').rstrip('}'))
        tmp.append(num)
        
        #여기서 끝
        if splits[-1] == '}':
            num_list.append([tmp, len(tmp)])
            tmp = []
    
    num_list.sort(key=lambda x: x[1])
    
    pre_num = set()#이미 나온 숫자
    answer = [0] * num_list[-1][1]
    idx = 0
    
    for lis, length in num_list:
        minus = set(lis) - pre_num
        
        input_num = [*minus][0]
        answer[idx] = input_num
        idx += 1
        pre_num.add(input_num)
    
    
    return answer