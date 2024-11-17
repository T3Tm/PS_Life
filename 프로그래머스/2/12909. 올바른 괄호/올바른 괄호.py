# def solution(s):
#     a=[]
#     for i in s:
#         if i=='(':a.append(i)
#         else:
#             if len(a):
#                 if a.pop()!='(':
#                     return False
#             else:return False
#     if len(a):return False
#     return True

def solution(s):
    Stack = []
    jjak = {'(' : ')', ')' : '('}
    for pal in s:
        if pal == '(':Stack.append(pal)
        else:
            if not Stack:return False
            if jjak[Stack[-1]] != pal:return False
            Stack.pop()
    if Stack:return False
    return True