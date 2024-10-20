#include <bits/stdc++.h>
using namespace std;
const int MX = 1002;
const int INF = 0x3f3f3f3f;
int n, k;
int dp[MX][MX];
pair<int,int>mark[MX][MX];

pair<int, int> arr[MX];
int getDist(int num, int eventA, int eventB){
    pair<int, int> pre;
    if (!eventA){
        if (num)
            pre = {n, n};
        else
            pre = {1, 1};
    }
    else{
        pre = arr[eventA];
    }
    pair<int, int> &now = arr[eventB];
    return abs(now.second - pre.second) + abs(now.first - pre.first);
}
int func(int x, int y)
{
    if(x == k || y == k)return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = INF;
    int nxt = max(x,y) + 1;
    int left = func(nxt, y) +  getDist(0, x, nxt);
    int right = func(x, nxt) +  getDist(1, y, nxt);
    if(left > right){
        dp[x][y] = right;
        mark[x][y] = {x, nxt};
    }else{
        dp[x][y] = left;
        mark[x][y] = {nxt, y};
    }
    return dp[x][y];
}

void tracing(int x, int y, vector<int> &car)
{
    if(x == k || y == k)return;
    auto [nx, ny] = mark[x][y];
    if(nx > ny)car.push_back(1);
    else car.push_back(2);
    tracing(nx, ny, car);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    for (int i{1}; i <= k; i++)cin >> arr[i].first >> arr[i].second;

    int result = func(0,0);
    cout << result << "\n";
    vector<int> trace;
    tracing(0,0,trace);
    for (auto it = trace.begin(); it != trace.end(); it++)
        cout << *it << '\n';
    return 0;
}