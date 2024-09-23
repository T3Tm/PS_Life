import sys
input = sys.stdin.readline

n=int(input())
arr=[int(input())for _ in range(n)]
sorted_pair=[]
for i in range(n):
    sorted_pair.append((arr[i],i))
sorted_pair.sort()
result=0
for i in range(n):
    if sorted_pair[i][1] > i:#원래 위치가 아니네
        result=max(result,sorted_pair[i][1]-i)
print(result+1)