t = int(input())
for _ in range(t):
	out = input()
	dic = {}

	for num in map(int ,input().split()):
		dic[num] = dic.get(num, 0) + 1

	answer = 0
	cnt = 0
	for key, value in dic.items():
		if cnt < value:
			answer = key
			cnt = value
		elif cnt == value and answer < key:
			answer = key
	print(f'#{out} {answer}')