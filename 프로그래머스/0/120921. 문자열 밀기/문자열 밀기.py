def solution(A, B):
    A=A+A
    if B not in A:return -1
    #hellohello
    #atatatat
    for i in range(len(A)-len(B),0, -1):
        if A[i:i + len(B)] == B:
            return len(B) - i 