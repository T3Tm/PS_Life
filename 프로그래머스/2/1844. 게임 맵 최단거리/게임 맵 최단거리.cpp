#include <bits/stdc++.h>
using namespace std;
int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    int visited[102][102];memset(visited, -1, sizeof visited);
    visited[0][0] = 1;
    int n = maps.size(), m = maps[0].size();
    
    while(!q.empty()){
        auto[x,y] = q.front(); q.pop();
        for(int i{};i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(visited[nx][ny]!=-1 || !maps[nx][ny])continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx,ny});
        }
    }
    return visited[n-1][m-1];
}