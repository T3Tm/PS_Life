def solution(myString, pat):
    return +(pat in ''.join([*map(lambda x:'B' if x == 'A' else 'A', myString)]))
    