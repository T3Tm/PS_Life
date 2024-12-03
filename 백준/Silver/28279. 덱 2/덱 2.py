from collections import deque
import sys
input = sys.stdin.readline
q = deque()

for _ in range(int(input())):
	cmd, *num = input().split()
	if cmd == '1':
		q.appendleft(num[0])
	elif cmd == '2':
		q.append(num[0])
	elif cmd == '3':
		if q:
			print(q.popleft())
		else:
			print(-1)
	elif cmd == '4':
		if q:
			print(q.pop())
		else:
			print(-1)
	elif cmd == '5':
		print(len(q))
	elif cmd == '6':
		print(+(len(q)==0))
	elif cmd == '7':
		if q:
			print(q[0])
		else:
			print(-1)
	else:
		if q:
			print(q[-1])
		else:
			print(-1)