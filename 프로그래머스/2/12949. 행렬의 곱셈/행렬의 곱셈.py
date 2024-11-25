def solution(arr1, arr2):
    answer = []
    n = len(arr1)
    m = len(arr2[0])
    
    repeat = len(arr1[0])
    
    for i in range(n):
        tmp = []
        for j in range(m):
            num = 0
            
            for col in range(repeat):
                
                num += arr1[i][col] * arr2[col][j]
            
            tmp.append(num)
        answer.append(tmp)
    return answer