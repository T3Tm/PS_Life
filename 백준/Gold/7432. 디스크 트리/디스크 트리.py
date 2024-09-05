import sys
input = sys.stdin.readline

n = int(input())

trie = {}

def insert(lis):
    cur = trie
    for word in lis:
        if cur.get(word, 1) == 1:
            cur[word] = {}
        cur = cur[word]
    cur['is______1'] = 1

def prints(cur, depth):
    for next in sorted(cur.keys()):
        if next == 'is______1':continue
        print(f"{' '*depth}{next}")
        prints(cur[next],depth+1) 

for _ in range(n):
    lis = input().split("\\")
    lis[-1] = lis[-1].strip()
    insert(lis)


prints(trie, 0)