from collections import deque
n, k = map(int, input().split())

deq = deque()
for idx in range(n):deq.append(idx+1)


answer = '<'
count = 0
while deq:
    count += 1
    front = deq.popleft()
    if count != k:
        deq.append(front)
        continue
    count = 0
    answer += f'{front}, '
answer = answer[:-2] + '>'
print(answer)