#include <bits/stdc++.h>
using namespace std;

/*
    https://www.acmicpc.net/problem/14517

    14517번 팰린드롬

    첫째 줄에 길이가 1000을 넘지 않는 문자열 S 가 주어진다. 
    문자열 S는 알파벳 소문자로만 이루어져 있다.
*/
int dp[1002][1002];
const int mod = 10007;
string s;
int dfs(int l, int r){
    if(l > r)return 0;
    if(l == r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r] = (dfs(l,r-1) + dfs(l+1,r) - dfs(l+1,r-1) + mod)%mod;
    if(s[l] == s[r]){
        dp[l][r] = (dp[l][r] + 1 + dfs(l+1,r-1))%mod;
    }
    return dp[l][r];
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    cin >> s;
    s = ' ' + s;
    cout << dfs(1, s.size()-1);
    return 0;
}