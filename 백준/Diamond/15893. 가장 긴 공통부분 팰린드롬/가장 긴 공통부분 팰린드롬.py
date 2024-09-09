from heapq import *
import sys
input = sys.stdin.readline

n = int(input())
words = [
    '#' + '#'.join(input().strip()) + '#'
    for _ in range(n)
]
words.sort(key = lambda x: len(x)) #nlogn 

smallest_word = words[0]
l = len(smallest_word)
A = [0] * l
r=q=-1

candidate = []
memo = set()
for i in range(l):#2만?
    if r>=i:
        ii = 2 * q - i
        A[i] = min(r-i, A[ii])  
    while i - A[i] - 1>=0 and i + A[i] + 1 < l and smallest_word[i-A[i]-1] == smallest_word[i+A[i] + 1]:
        A[i]+=1
    if i + A[i] > r:
        r,q = i + A[i], i
    candi = smallest_word[i-A[i]:i+A[i]+1]
    if candi in memo:continue
    memo.add(candi)
    heappush(candidate, [-(2*A[i]+1),candi])#제일 긴 문자열, i
def isAll(wo):
    for word in words:
        if wo not in word:
            return 0
    return 1
while candidate:
    len_, l = heappop(candidate)
    if isAll(l):
        print((-len_)//2)
        exit(0)
    if (-len_) < 2:continue
    heappush(candidate, [-((-len_) - 2), l[1:-1]])
print(0)