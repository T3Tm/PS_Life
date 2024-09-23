#include <bits/stdc++.h>

using namespace std;
char board[52][52];
int n,m;
int dp[52][52];//몇 개
bool visited[52][52];
int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
int dfs(int x,int y){
    if (board[x][y]=='H')return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=1;
    for(int i{};i<4;i++){
        int nx = x + dx[i]*(board[x][y]-'0');
        int ny = y + dy[i]*(board[x][y] - '0');

        if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
        if(visited[nx][ny]){//무한 츠쿵요미
            dp[nx][ny] = 2502;//50이 최대인데 52이면 한무로 갈 수 있다는 것
            dp[x][y] = 2502;
            return dp[x][y];//더 볼 필요가 없음
        }
        visited[nx][ny] = 1;
        dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1);
        visited[nx][ny] = 0;
    }
    return dp[x][y];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;memset(dp, -1, sizeof dp);
    for(int i{};i<n;i++){
        for(int j{};j<m;j++)cin >> board[i][j];
    }
    int result{};
    visited[0][0]=1;
    result=dfs(0,0);
    if(result > 2500)cout << -1;
    else cout << result;
    return 0;
}