import sys
input = sys.stdin.readline
'''

'''
def solution() -> None:
    T = int(input())
    dp = [[0] * 1121 for _ in range(15)]

    #dp[n][k]
    #n수를 서로 다른 소수 k개를 이용하여 만드는 가짓수
    #dp[2][1] => 1개
    MAX = 1121
    eratos = [False] * MAX
    for i in range(2, int(MAX**.5) + 1):
        if eratos[i]:continue
        for j in range(i*i, MAX, i):
            eratos[j] = True
    
    #소수 뽑아내기
    primes = [i for i in range(2, MAX) if not eratos[i]]
    
    #기저조건

    #  k - 1
    #  n - prime
    dp[0][0] = 1

    for prime in primes:
        for k in range(14, 0, -1):
            for n in range(MAX - 1, prime - 1, -1):
                dp[k][n] += dp[k-1][n - prime]

    '''
        2 3

    '''


    for _ in range(T):
        n, k = map(int, input().split())
        print(dp[k][n])
if __name__ == '__main__':
    solution()