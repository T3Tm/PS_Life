#include <bits/stdc++.h>
using namespace std;
const int MX = 102;

struct loc{
    int x,y,dir;
};

/* 북 동 남 서 */
int dx[]{-1,0,1,0};
int dy[]{0,1,0,-1};

//결과를 해석하는 것 동 서 남 북
//0 -> 1
//1 -> 3
//2 -> 2
//3 -> 0
int dir_trans[]{1,3,2,0};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;
    int board[MX][MX]{};
    for(int i{};i<n;i++){
        for(int j{};j<m;j++)cin >> board[i][j];
    }
    auto init = [](loc &tmp){
        cin >> tmp.x >> tmp.y >> tmp.dir;
        tmp.x--;
        tmp.y--;
        tmp.dir--;
        tmp.dir = dir_trans[tmp.dir];
    };
    loc START{}; init(START);
    loc END{}; init(END);
    
    /* Turn */
    auto turnning = [&](loc t, int alpha)-> loc{
        //left, right 
        if(alpha == 1){
            t.dir = (t.dir + alpha)%4;
        }else{
            t.dir = (t.dir + alpha + 4)%4;
        }
        return t;
    };

    /* GO Striaght*/
    int visited[4][MX][MX];
    auto GO = [&](loc &s, loc& e) -> int{
        memset(visited, -1, sizeof visited);//방문 체크
        visited[s.dir][s.x][s.y] = 0;//처음 방문
        
        queue<loc>q;
        q.push(s);

        while(!q.empty()){
            auto [x,y,dir] = q.front();q.pop();
            for(int alpha{1};alpha<4;alpha++){
                int nx = x + dx[dir] * alpha;
                int ny = y + dy[dir] * alpha;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                if(board[nx][ny])break;
                if(visited[dir][nx][ny] !=-1)continue;
                visited[dir][nx][ny] = visited[dir][x][y] + 1;
                q.push({nx,ny, dir});
            }

            //방향 바꾸는 거 하나 넣기
            for(auto alpha : {1,-1}){
                loc tmp = turnning({x,y,dir}, alpha);
                int chk = visited[dir][x][y] + 1;
                if(visited[tmp.dir][x][y]!=-1)continue;//해당 방향으로는 이미 갔었음
                visited[tmp.dir][x][y] = chk;
                q.push(tmp);//왼쪽 오른쪽 방향 하나씩 넣기
            }
        }
        return visited[e.dir][e.x][e.y];
    };

    cout << GO(START, END);
    return 0;
}