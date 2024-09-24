#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;cin >> n;
    vector<vector<char>>board(n,vector<char>(n));
    for(auto &row:board)for(auto &v:row)cin >> v;
    
    //1. X 좌표 찾기
    //2. T 좌표 찾기
    //3. 빈 좌석 찾기
    //4. 빈 좌석으로부터 3개 뽑기
    //5. T 좌표로부터 상하좌우 뻗어나가기
    auto finding = [&](const char v) -> vector<pair<int,int>>{
        vector<pair<int,int>>ret;
        for(int i{};i<n;i++){
            for(int j{};j<n;j++){
                if(board[i][j] == v)ret.push_back({i,j});
            }
        }
        return ret;
    };
    vector<pair<int,int>> x_loc = finding('X');
    vector<pair<int,int>> t_loc = finding('T');
    vector<pair<int,int>> s_loc = finding('S');

    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    bool visited[8][8];
    /* 현재 board에서 T를 기준으로 뻗어나가기 */
    auto simulation = [&]()-> int{
        memset(visited, 0, sizeof visited);
        queue<tuple<int,int,int>>q;// x, y, dir
        
        for(auto &[x, y]:t_loc){
            visited[x][y] = 1;
            for(int i{};i<4;i++)q.push({x,y,i});
        }

        while(!q.empty()){
            auto [x, y, dir] = q.front();q.pop();

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny>=n)continue;
            if(board[nx][ny] == 'O')continue;
            visited[nx][ny] = 1;
            q.push({nx,ny, dir});
        }
        
        int cnt{};
        for(auto &[x,y]:s_loc){
            cnt += visited[x][y];
        }
        return cnt;
    };

    bool flag{};
    /* 3개의 빈 좌석 뽑기 */
    auto pick = [&](auto self, int depth, int pre) -> void{
        if(depth == 3){
            bool ret = simulation() == 0;  
            flag = max(flag, ret);
            return;
        }
        for(int i = pre; i<x_loc.size(); i++){
            auto &[x,y] = x_loc[i];
            char tmp = 'O';
            swap(tmp, board[x][y]);
            self(self, depth + 1, i+1);
            swap(tmp, board[x][y]);
        }
    };
    pick(pick, 0, 0);
    if(flag)cout << "YES";
    else cout << "NO";
    return 0;
}