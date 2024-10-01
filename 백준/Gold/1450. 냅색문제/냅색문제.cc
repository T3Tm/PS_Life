#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
int n,c;
map<int, int, greater<>>knap(int front, int back){
    //어디붙 ㅓ idx까지인지
    map<int, int, greater<>>dp{{0, 1}};
    for(int i = front; i<back;i++){
        auto &v = arr[i];
        for(auto iter = dp.begin();iter!=dp.end();iter++){
            auto key = 1LL * iter->first + v;
            if(key <= c){
                dp[key] = dp[key] + iter->second;
            }
        }
    }
    for(auto iter = next(dp.rbegin()); iter!=dp.rend();iter++){
        iter->second += prev(iter)->second;
    }
    return dp;
}
int knap(int front, int back, map<int, int,greater<>>&dp){
    //어디붙 ㅓ idx까지인지
    long long ret{};
    map<int, int>now_dp{{0, 1}};// 0이 아니라면 모든 곳에 dp->rbegin()->second를 더한다.
    for(int i = front; i<back;i++){
        auto &v = arr[i];
        for(auto iter = now_dp.rbegin(); iter != now_dp.rend();iter++){
            auto key = 1LL * iter->first + v;
            if(key <= c){
                now_dp[key] = now_dp[key] + iter->second;
            }
        }
    }
    int result{};
    for(auto &[key, value]: now_dp){
        auto it = dp.lower_bound(c - key);
        result += value * it->second;
    }
    return result;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> c;
    arr.resize(n);
    for(auto &v:arr)cin >> v;
    sort(arr.begin(), arr.end());
    map<int, int, greater<>>dp = knap(0, n >> 1);//나오는 갯수
    int back = knap(n>>1, n, dp);
    cout << back;//2배
    return 0;
}