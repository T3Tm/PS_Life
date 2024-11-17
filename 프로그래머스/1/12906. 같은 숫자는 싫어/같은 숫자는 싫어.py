# def solution(arr):
#     pre_fix = ''
#     arr.append('A')
#     count=0
#     new_arr = []
#     for i in map(str,arr):
#         if i != pre_fix:
#             if count != 0:
#                 new_arr.append(int(pre_fix))
#                 count=1
#             pre_fix = i
#         count+=1
#     return new_arr


def solution(arr):
    #연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 한다
    s = []
    for num in arr:
        while s and s[-1] == num:s.pop()
        s.append(num)
    return s