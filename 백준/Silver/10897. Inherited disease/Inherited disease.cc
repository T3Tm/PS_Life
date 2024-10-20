#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
using namespace std;
long long StartNumber= 0;//시작 번호
long long LastNumber=0;//마지막 번호
long long LeftSideCnt=0;//왼쪽 애들 갯수
const int MOD = 1e9+7;
long long cnt=1;
int main() {
    fast;
    int d;cin >> d;
    for(int gen=1;gen<=d;gen++){
        long long number;cin >> number;//같은 자식일 때 -1 내 왼쪽 아이의 갯수
        cout << (LastNumber%MOD + (LeftSideCnt*gen)%MOD+ number)%MOD  << endl;
        LeftSideCnt = ((LeftSideCnt*gen)%MOD + number-1)%MOD;
        cnt=(cnt*gen)%MOD;
        LastNumber = (LastNumber+cnt)%MOD;
    }
    return 0;
}
