'''
'25. 09. 20

(같은 전화번호가 중복으로 있지는 않는다.)
1. 다른 번호의 접두어에 있으면 안 된다.
2. sort를 하면 동일한 부분들이 나오게 된다.

그렇게 했을 때 뒤에 있는 것들로만 비교하면 된다.
'''
def solution(phone_book):
    answer = True
    
    phone_book.sort(key = lambda x: (x, len(x)))
    
    #print(phone_book)
    #해시로 만든다?
    
    #접두어로 있다..
    #118
    #1194
    #11946
    #119478 이런 케이스가 있을 수도 있다.
    #11821787823 << 이런케이스를 빠르게 구할 수있으려면
    
    
    for idx, phone_number in enumerate(phone_book):
        for next_idx in range(idx + 1, len(phone_book)):
            if phone_number not in phone_book[next_idx]:break
            #첫 글자가 다르면 더이상 볼 필요가 없음
            A_idx = B_idx = 0
            while A_idx < len(phone_number) and B_idx < len(phone_book[next_idx]) and \
                phone_number[A_idx] == phone_book[next_idx][B_idx]:
                A_idx += 1
                B_idx += 1
            
            if A_idx == len(phone_number):
                answer = False
        
    return answer