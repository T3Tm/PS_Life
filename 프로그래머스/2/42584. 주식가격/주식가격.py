# def solution(prices):
#     s,r=[],[0]*len(prices)
#     for idx,i in enumerate(prices):
#         if (s and s[-1][1]<= i) or len(s)==0:s.append([idx,i])
#         else:
#             while s and s[-1][1]>i:
#                 a=s.pop()
#                 r[a[0]]=idx-a[0]
#             s.append([idx,i])
#     while s:
#         a=s.pop()
#         r[a[0]]=idx-a[0]
#     return r
def solution(prices):
    #가격이 떨어지지 않은 기간은 몇 초?
    s = [] #idx, value
    returns = [0]*len(prices)
    for idx, value in enumerate(prices):
        while s and s[-1][1] > value:
            index, values = s.pop()
            returns[index] = idx - index
        s.append((idx,value))
    
    while s:
        index, values = s.pop()
        returns[index] = len(prices) - index - 1
    return returns