'''
'25. 09. 20

(같은 전화번호가 중복으로 있지는 않는다.)
1. 다른 번호의 접두어에 있으면 안 된다.
2. sort를 하면 동일한 부분들이 나오게 된다.

그렇게 했을 때 뒤에 있는 것들로만 비교하면 된다.
'''
def solution(phone_book):
    answer = True
    
    hash_table = set()
    for phone_number in phone_book:
        hash_table.add(phone_number)
    
    for idx, phone_number in enumerate(phone_book):
        tmp = ''
        for word in phone_number:
            tmp += word
            if tmp in hash_table and len(tmp) != len(phone_number):
                answer = False
    return answer