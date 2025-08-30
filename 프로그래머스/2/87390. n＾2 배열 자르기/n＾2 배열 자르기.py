'''
'25. 08. 30

1. n, left, right가 주어진다.
2. n^2배열을 만든다.
3. 해당 left, right까지 수를 자른다.

제한이 n <= 10^7

right - left < 10^5

단순히 n^2을 만들고 left, right를 내는 문제가 아님.
table[i][j] => max(i, j)값으로 채우는데

일차항으로 바꾸게 되면 어떻게 될까
[row][col], [row, col + 1], [row, col + 2], [row, col + 3]
[row + 1][col], ...

left가 어디부터 right로 가는지만 알면 될것 같은데?

left가 만약 7이면
n이 4이기 때문에 한 행에 4개의 열이 있으므로 

원래 행과 열을 체크할 수 있다.
거기부터 하나씩 체크하여 right까지 가면 된다.

left -> right까지는 10^5이므로 한 개씩 커지면서 넣어도 됨.
'''
def solution(n, left, right):
    answer = []
    row, col = left // n + 1, left % n + 1
    alpha = 0
    while left + alpha <= right:
        answer.append(max(row, col))
        col += 1
        if col > n:
            col = 1
            row += 1
        alpha += 1
    return answer