#include <bits/stdc++.h>
using namespace std;
const int MX = 102;
long long dp[MX][MX];
map<pair<int,int>,set<pair<int,int>>>dont;
int dx[]{0,1};
int dy[]{1,0};
int n,m;
long long func(int x,int y){
    if(x == n && y == m)return 1;
    if(dp[x][y] != -1)return dp[x][y];
    dp[x][y] = 0;
    for(int i{};i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > n || ny > m)continue;
        if(dont.find({x,y}) != dont.end()){
            if(dont[{x,y}].find({nx,ny}) != dont[{x,y}].end())continue;//갈 수 없는 곳
        }
        dp[x][y] += func(nx,ny);
    }
    return dp[x][y];
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;memset(dp,-1,sizeof dp);
    int k;cin >> k;
    for(int i{};i<k;i++){
        int a,b,c,d;cin >> a >> b >> c >> d;
        if(a > c)swap(a,c),swap(b,d);
        else if(b > d)swap(a,c),swap(b,d);
        dont[{a,b}].insert({c,d});
    }
    cout << func(0,0);
    return 0;
}