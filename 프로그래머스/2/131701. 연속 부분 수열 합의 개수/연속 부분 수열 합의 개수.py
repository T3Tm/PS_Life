'''
'25. 8. 24

1. 연속 부분 수열의 합
2. 길이가 최대가 1000이기 때문에

스위핑 기법을 이용하면 쉽게 구할 수 있을 것이다.
'''
def solution(elements):
    len_ = len(elements)
    elements = elements + elements

    save_number = set()#이전 숫자들 기억
    
    for length in range(1, len_ + 1):
        front, back = 0, 0
        sum_ = 0
        for p in range(length):
            sum_ += elements[back]
            back += 1

        save_number.add(sum_)#현재 값도 저장
        while front < len_:
            sum_ = sum_ - elements[front] + elements[back]
            front += 1
            back += 1
            save_number.add(sum_)
    return len(save_number)