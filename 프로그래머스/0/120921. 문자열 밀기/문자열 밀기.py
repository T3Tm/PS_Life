def solution(A, B):
    B=B+B
    if A not in B:return -1
    return B.index(A)