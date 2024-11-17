import sys
from collections import deque
input = sys.stdin.readline

word = input().strip()
q = deque(word[0])
for w in word[1:]:
    if q[0] >= w:
        q.appendleft(w)
    else:
        q.append(w)
print(''.join(q))