import sys
input = sys.stdin.readline
sys.setrecursionlimit(2501)
def dfs(x,y):
    global board,visited
    visited[x][y]=1
    for dx,dy in (0,1),(0,-1),(1,0),(-1,0):
        nx,ny=x+dx,y+dy
        if nx<0 or nx>=n or ny<0 or ny>=m:continue
        if visited[nx][ny]==1 or board[nx][ny]==0:continue
        dfs(nx,ny)
for _ in[0]*int(input()):
    m,n,k=map(int,input().split())
    board=[[0]*m for _ in[0]*n]
    visited=[board[i][::] for i in range(n)]
    for _ in[0]*k:
        x,y=map(int,input().split())
        board[y][x]=1
    cnt=0
    for i in range(n):
        for j in range(m):
            if visited[i][j]==0 and board[i][j]:
                dfs(i,j)
                cnt+=1
    print(cnt)