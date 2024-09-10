#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int visited[2][102][102];
int board[102][102];

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    int n,m,t;cin >> n >> m >>t;
    memset(visited, 0x3f, sizeof visited);

    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> board[i][j];

    queue<tuple<bool,int,int>> q;
    visited[0][0][0] = 0;
    q.push({0,0,0});

    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    while(!q.empty()){
        auto [sword,x,y] = q.front();q.pop();

        for(int i=0;i<4;i++){
            int nx = x+ dx[i];
            int ny = y+ dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m)continue;
            if(board[nx][ny] == 1 && !sword)continue;

            bool now_sword = max(sword, board[nx][ny] == 2);
            if(visited[now_sword][nx][ny] != INF)continue;

            visited[now_sword][nx][ny] = visited[sword][x][y] + 1;
            q.push({now_sword,nx,ny});
        }
    }
    int dst = min(visited[0][n-1][m-1], visited[1][n-1][m-1]);
    if(dst == INF || dst > t)cout << "Fail";
    else cout << dst;
    
    return 0;
}