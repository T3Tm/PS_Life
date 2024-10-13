#include <bits/stdc++.h>
using namespace std;
int arr[10];
struct loc{
    int x,y;
};

loc mal[]{
    {0,0},
    {0,0},
    {0,0},
    {0,0}
};

int board[][22]{
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0},
    {0,0,0,0,0,10,13,16,19,25,0},
    {0,0,0,0,0,0,0,0,0,0,20,22,24,25,30,35},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,28,27,26,25},
};
//5, 10, 15,
const int board_end = 21;//
int result;
loc moving(int x,int y,int alpha){
    loc ret{x,y + alpha};
    if(x == 0){
        if(ret.y % 5 == 0 && ret.y / 5 < 4){
            ret.x = ret.y / 5;
        }else{
            ret.y = min(board_end, ret.y);
        }
    }else if(x == 1){
        if(ret.y >= 12){//마지막
            ret.x = 0;
            ret.y = min(20 + (ret.y - 12), board_end);
        }
        else if(ret.y >= 9){
            ret.x = 2;
            ret.y = 13 + (ret.y - 9);
        }
    }else if(x == 2){
        if(ret.y >= 16){
            ret.x = 0;
            ret.y = min(20 + (ret.y - 16),board_end);
        }
    }else if(x == 3){
        if(ret.y >= 22){
            ret.x = 0;
            ret.y = min(20 + (ret.y - 22),board_end);
        }
        else if(ret.y >= 19){
            ret.x = 2;
            ret.y = 13 + (ret.y - 19);
        }
    }
    return ret;
}
bool isvisit(int idx, int x,int y){
    if(x == 0 && y == board_end)return 0;
    for(int i{};i<4;i++){
        if(i == idx)continue;
        auto &[xx,yy] = mal[i];
        if(x == xx && y == yy)return 1;    
    }
    return 0;
}
void dice_yut(int depth, int num){
    if(depth == 10){
        result = max(result, num);
        return;
    }

    int move = arr[depth];//움직이어야 하는 칸 수

    for(int i{};i<4;i++){
        auto &[x,y] = mal[i];
        //mal 중 하나 고르기
        int prex = x, prey = y;
        auto [nx,ny] = moving(x,y, move);
        if(isvisit(i,nx,ny))continue;//이미 방문돼있으면 안됨.
        x = nx,y = ny;
        dice_yut(depth + 1, num + board[nx][ny]);
        x = prex, y = prey;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(auto &v: arr)cin >> v;
    dice_yut(0,0);
    cout << result;
    return 0;
}