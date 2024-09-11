#include <bits/stdc++.h>
using namespace std;
int country[6][3];


bool bact(int team, int another){//현재 어느 팀인지 확인
    if(team == 6){
        return 1;//마지막 팀에 도달 했다는 것
    }
    //현재 team이라는 팀이 another 팀을 어떻게 걸러줄 것인지 판단
    if(another == 6){
        return bact(team + 1, team + 2);
    }
    //3가지의 상황이 있다.
    //이긴다
    for(int win_draw_lose = 0; win_draw_lose < 3; win_draw_lose++){
        if(country[team][win_draw_lose] && country[another][2 - win_draw_lose]){
            country[team][win_draw_lose]--;
            country[another][2 - win_draw_lose]--;
            bool ret = bact(team, another + 1);
            if(ret)return ret;
            country[team][win_draw_lose]++;
            country[another][2 - win_draw_lose]++;
        }
    }
    return false;
}

bool Possible(){
    for(int i=0;i<6;i++){
        int total = 0;
        for(int j=0;j<3;j++){
            total += country[i][j];
        }

        if(total != 5)return 0;//한 곳이 5경기를 하지 않았다는 것은 말이 안됨.
    }

    return bact(0,1);
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    for(int i=0;i<4;i++){
        for(int row = 0; row < 6; row++){
            for(int col = 0; col < 3; col ++){
                cin >> country[row][col];
            }
        }

        if(Possible())cout << "1 ";
        else cout << "0 ";

    }
    return 0;
}