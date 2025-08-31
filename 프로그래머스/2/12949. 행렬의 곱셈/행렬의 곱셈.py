'''
'25. 08. 31

1. arr1, arr2의 곱을 반환하는 함수를 완성하여라.

arr1 3, 2
arr2 2, 2

rst 3, 2

rst[i][j] := sum(arr1[i][:] * arr2[:][j])이다.
'''
def solution(arr1, arr2):
    new_row = len(arr1)
    new_col = len(arr2[0])
    answer = [[0]*new_col for _ in range(new_row)]
    
    #10^4
    for i in range(new_row):
        for j in range(new_col):
            v = 0
            for col in range(len(arr1[0])):
                    v += arr1[i][col] * arr2[col][j]
            answer[i][j] = v
    return answer