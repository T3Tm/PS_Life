'''
'25. 08. 24

1. 금액 지불 => 10일동안 회원 자격
2. 회원 == 한 가지 제품 할인, 할인 제품은 하루에 한 개씩만
3. 회원 등록 시 원하는 제품을 모두 할인 받을 수 있는 총 날짜 수를 구하시오.


슬라이딩 윈도우 기법을 이용하면 되겠다
want의 길이가 10개 이므로 O(len(discount))하면서 want를 확인하면 됨.
'''
#현재 넣은 src와 cmp를 비교했을 때 원하는 갯수를 충족하는지 리턴
def is_possible(src, cmp) -> bool:
    for a, b in zip(src, cmp):
        if a > b:return False
    return True

def solution(want, number, discount):
    answer = 0
    
    sliding_window = [0] * len(want)#number의 갯수를 만족시킬 때
    sliding_window_len = 10
        
    idx_ = {want[i] : i for i in range(len(want))}#각 원하는 상품의 인덱스 저장
    
    
    for idx in range(sliding_window_len):
        ret_idx = idx_.get(discount[idx], -1)
        if ret_idx != -1:
            sliding_window[ret_idx] += 1
    
    #만족하는지 한번 확인
    answer += is_possible(number, sliding_window)
    
    front = 0
    for idx in range(sliding_window_len, len(discount)):
        ret_idx = idx_.get(discount[idx], -1)
        front_idx = idx_.get(discount[front], -1)
        
        if front_idx != -1:
            sliding_window[front_idx] -= 1
        if ret_idx != -1:
            sliding_window[ret_idx] += 1#새로운 것을 하나 추가할 때 이전 것을 삭제할 수 있어야 한다.
        ret_value = is_possible(number, sliding_window)
        answer += ret_value
        front += 1
    return answer