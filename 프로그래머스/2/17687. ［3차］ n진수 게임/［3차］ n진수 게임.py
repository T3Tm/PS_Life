'''
'25. 10. 6.(월)

1. 원래 수를 기억하고 있어야 한다.(10진수로)
2. n진수로 변환한다.logn
3. n진수 기준으로 m씩 더할 이유가 없음
1000 * 100 해봤자 10^5 이기 때문에 1씩 더하면서 값을 봐도 됨.

'''
#숫자를 넣으면 n진법으로 만들어서 리턴한다.
result = []
def trans_n(n: int, remain: int) -> None:
    global result
    if remain < n:
        if remain > 9:
            remain = chr(remain + 55)
        result.append(remain)
    #trans_n 부르기
    else:
        alpha = remain % n
        if remain % n > 9:
            alpha = chr(remain % n + 55)
        result.append(alpha)
        trans_n(n, remain // n)
        
def solution(n, t, m, p):
    global result
    answer = ''
    #일단 
    repeat = p - 1#p번째가 되면 answer에 넣는다.
    now = 0#현재 숫자
    #넣어야 되는 숫자
    
    #예를 들어서 1010 이라면
    #2라면 4 
    while t:
        result = []
        trans_n(n, now)
        #result로 나오는 숫자에서 p번째 것을 체크.
        #바로 넣을 수 있음
        while repeat < len(result) and t:
            answer += f'{result[-(repeat + 1)]}'
            repeat += m
            t-= 1
        repeat -= len(result)
        now += 1
    return answer