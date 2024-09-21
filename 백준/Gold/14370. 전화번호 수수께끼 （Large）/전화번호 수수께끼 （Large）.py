import sys

input = sys.stdin.readline
for case in range(1, int(input()) + 1):
    word = input().strip()
    res = ""
    alpha = {}
    number = []
    for w in word:
        alpha[w.lower()] = alpha.get(w.lower(), 0) + 1
    if alpha.get('x', 0) != 0:  #six
        value = alpha['x']
        alpha['x'] = 0
        alpha['s'] -= value
        alpha['i'] -= value
        for _ in range(value):
            number.append(6)
    if alpha.get('z', 0) != 0:  #zero
        value = alpha['z']
        alpha['e'] -= value
        alpha['r'] -= value
        alpha['o'] -= value
        for _ in range(value):
            number.append(0)
    if alpha.get('u', 0) != 0:  #four
        value = alpha['u']
        alpha['f'] -= value
        alpha['o'] -= value
        alpha['r'] -= value
        for _ in range(value):
            number.append(4)
    if alpha.get('w', 0) != 0:  #two
        value = alpha['w']
        alpha['t'] -= value
        alpha['o'] -= value
        for _ in range(value):
            number.append(2)
    if alpha.get('g', 0) != 0:
        value = alpha['g']
        alpha['e'] -= value
        alpha['i'] -= value
        alpha['h'] -= value
        alpha['t'] -= value
        for _ in range(value):
            number.append(8)
    if alpha.get('s', 0) != 0:  #seven
        value = alpha['s']
        alpha['s'] = 0
        alpha['e'] -= value * 2
        alpha['v'] -= value
        alpha['n'] -= value
        for _ in range(value):
            number.append(7)
    if alpha.get('f', 0) != 0:  #five
        value = alpha['f']
        alpha['i'] -= value
        alpha['v'] -= value
        alpha['e'] -= value
        for _ in range(value):
            number.append(5)
    if alpha.get('o', 0) != 0:  #one
        value = alpha['o']
        alpha['o'] = 0
        alpha['n'] -= value
        alpha['e'] -= value
        for _ in range(value):
            number.append(1)

    if alpha.get('r', 0) != 0:
        value = alpha['r']
        alpha['t'] -= value
        alpha['h'] -= value
        alpha['e'] -= value * 2
        for _ in range(value):
            number.append(3)

    if alpha.get('e', 0) != 0:
        value = alpha['e']
        alpha['e'] = 0
        alpha['n'] -= value * 2
        alpha['i'] -= value
        for _ in range(value):
            number.append(9)

    number.sort()
    for i in number:
        res += f'{i}'
    print(f'Case #{case}: {res}')
