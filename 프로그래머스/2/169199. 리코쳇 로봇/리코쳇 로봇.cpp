#include <bits/stdc++.h>

using namespace std;

/*
    격자무늬에서 목표지점까지 도달하여라
    1. 한 번 움직일 때 벽 or 장애물까지만 도달할 수 있음.
    2. 방문배열을 한 번 씩만 도달할 수 있음.
    
    1. 초기 위치를 찾는다.
    2. 목표 위치를 찾는다.
    3. bfs를 돌린다.
    4. 결론 위치를 리턴한다.
*/

pair<int, int> findLocation(char target, vector<string>& board){
    pair<int, int> loc{-1, -1};
    for(int i{}; i < board.size(); i++){
        for(int j{}; j < board[i].size(); j++){
            if (board[i][j] == target){
                loc = {i, j};
            }
        }
    }
    return loc;
}

bool isBoundary(int x, int y, vector<string>& board){
    return x >= 0 && x < board.size() && y >=0 && y < board[0].size();
}


int visited[102][102];
int solution(vector<string> board) {
    int answer = 0;
    auto [sx, sy] = findLocation('R', board);
    auto [ex, ey] = findLocation('G', board);
    // cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
    
    queue<pair<int, int>>q;
    q.push({sx, sy});//초기 위치 보내기
    memset(visited, -1, sizeof visited);
    visited[sx][sy] = 0;
    
    int dx[]{0, 1, 0, -1};//동남서북
    int dy[]{1, 0, -1, 0};
    //반대면  0, 2
    //i + 2  1, 3
    
    
    //int repeat{};
    while(!q.empty()){
        auto[x, y] = q.front();q.pop();
        //repeat++;
        if(x == ex && y == ey){break;}
        
        //방향 정하기
        for(int i{};i < 4; i++){  
            //벽을 만나거나, 장애물을 만나기 전까지 이동하기
            int nx = x;
            int ny = y;
            //cout << "위치" << nx << ' ' << ny << '\n';        
            while(isBoundary(nx, ny, board) && board[nx][ny] != 'D'){//벽 장애물             
                nx = nx + dx[i];
                ny = ny + dy[i];
                //cout << "바뀐 위치" << nx << ' ' << ny << '\n';
            }
            
            //벽이라면 그 직전까지는 이동해야 됨.
            if(!isBoundary(nx, ny, board) || board[nx][ny] == 'D'){
                //반대로 이동을 한 번 해보자.
                nx = nx + dx[(i + 2)%4];
                ny = ny + dy[(i + 2)%4];
                //cout << "재조정" << nx << ' ' << ny << '\n';
            }
            
            if(visited[nx][ny] != -1)continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    // for(int i{}; i < board.size(); i++){
    //     for(int j{}; j < board[0].size(); j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return visited[ex][ey];
}