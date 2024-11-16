def solution(myString):
    return [*map(lambda x:len(x),myString.split('x'))]