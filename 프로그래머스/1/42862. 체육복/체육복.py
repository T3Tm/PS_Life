def solution(n, lost, reserve):
    arr=[1]*n
    for i in lost:arr[i-1]-=1
    for i in reserve:arr[i-1]+=1
    
    lost.sort()#잃은 사람 기준
    for idx in lost:
        idx_2=idx-1
        if arr[idx_2] == 1:
            continue
        if idx_2 == 0:
            if arr[idx_2+1] == 2:
                arr[idx_2+1]=1
                arr[idx_2]-=1
        elif 1<=idx_2<=(n-2):
            if arr[idx_2-1] == 2:
                arr[idx_2-1]=1
                arr[idx_2]-=1
            elif arr[idx_2+1] == 2:
                arr[idx_2+1]=1
                arr[idx_2]-=1
        elif idx_2 ==(n-1):
            if arr[idx_2-1] == 2:
                arr[idx_2-1]=1
                arr[idx_2]-=1      
    return n-arr.count(0)