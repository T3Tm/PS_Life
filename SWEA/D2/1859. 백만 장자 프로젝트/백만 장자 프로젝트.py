t = int(input())
for _ in range(t):
	input()
	lis = [*map(int ,input().split())]

	answer = 0
	now_max = lis[-1]
	for i in range(len(lis)-2, -1,-1):
		if now_max <= lis[i]: now_max = lis[i]
		answer += now_max - lis[i]
	print(f'#{_+1} {answer}')