import sys
input = sys.stdin.readline
n = int(input())

data = []
for _ in range(n):
    name, korean, english, math = input().split()
    korean, english, math = map(int, [korean, english, math])
    data.append((name,korean, english, math))

data.sort(key = lambda x: (-x[1], x[2], -x[3], x[0]))
for name, korean, english, math in data:
    print(name)