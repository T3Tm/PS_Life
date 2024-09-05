import sys
input = sys.stdin.readline
month = [0,31,28,31,30,31,30,31,31,30,31,30,31]
month_prefix = [0,31,59,90,120,151,181,212,243,273,304,334,365]

def transfer(m, d):
    return month_prefix[m-1]+ d
n = int(input())

lis=[]
last=transfer(3,0)
end=transfer(11,30)
for i in range(n):
    sm,sd,em,ed=map(int,input().split())
    s,e=max(transfer(sm,sd), last + 1),min(transfer(em,ed-1), end)
    lis.append((s,e))
lis.sort(key= lambda x:(x[0], -x[1]))

lis.append((367,367))

cnt=0
savex, savey = -1,-2
for i in range(n+1):
    if lis[i][0]-1>last:
        cnt+=1
        if savex - 1 > last:
            cnt = 0
            break
        last=savey
        savex,savey = -1,-2
    if last>=end:
        break
    if savey < lis[i][1]:
        savex, savey = lis[i]
        
if last<end:cnt=0
print(cnt)