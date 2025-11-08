import sys
input = sys.stdin.readline

MOD = 10**9 + 7

n = int(input())

data = [0] + [*map(int, input().split())]
size = 0b1
while n:
    size <<= 1
    n >>= 1
tree = [0] * (size << 1)
add_lazy = [0] * (size << 1)
mul_lazy = [1] * (size << 1)
n = len(data) - 1

def init(l = 1, r = n, node = 1):
    if l == r:
        tree[node] = data[l]
        return
    mid = l + r >> 1
    init(l, mid, node << 1)
    init(mid + 1, r, node << 1 | 1)
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]) % MOD

def propagate(l, r, node):
    if add_lazy[node] or mul_lazy[node]^1:
        tree[node] = ((tree[node] * mul_lazy[node]) % MOD + ((r - l + 1) * add_lazy[node]) % MOD) % MOD

        if l != r:
            add_lazy[node << 1] = ((add_lazy[node << 1] * mul_lazy[node]) % MOD + add_lazy[node]) % MOD
            add_lazy[node << 1 | 1] = ((add_lazy[node << 1 | 1] * mul_lazy[node]) % MOD + add_lazy[node]) % MOD

            mul_lazy[node << 1] = (mul_lazy[node << 1] * mul_lazy[node]) % MOD
            mul_lazy[node << 1 | 1] = (mul_lazy[node << 1 | 1] * mul_lazy[node]) % MOD
        add_lazy[node] = 0
        mul_lazy[node] = 1

def range_update(cmd, l, r, diff, node = 1, left = 1, right = n):
    propagate(left, right, node)
    if r < left or right < l: return
    if l <= left <= right <= r:
        if cmd == 1:
            add_lazy[node] = diff
            mul_lazy[node] = 1
        elif cmd == 2:
            add_lazy[node] = 0
            mul_lazy[node] = diff
        else:
            add_lazy[node] = diff
            mul_lazy[node] = 0
        propagate(left, right, node)
        return
    mid = left + right >> 1
    range_update(cmd, l, r, diff, node << 1, left, mid)
    range_update(cmd, l, r, diff, node << 1 | 1, mid + 1, right)
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]) % MOD

def query(l, r, node = 1, left = 1, right = n):
    propagate(left, right, node)
    if r < left or right < l: return 0
    if l <= left <= right <= r:
        return tree[node]
    mid = left + right >> 1
    return (query(l, r, node << 1, left, mid) + query(l, r, node << 1 | 1, mid + 1, right)) % MOD

init()

for _ in range(int(input())):
    cmd, *data = map(int, input().split())
    if cmd == 4:
        print(query(*data))
    else:
        range_update(cmd, *data)