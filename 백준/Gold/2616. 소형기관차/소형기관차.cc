#include <bits/stdc++.h>

using namespace std;
int n, divi;
int prefix[50002];
int dp[3][50002];
int dfs(int cnt, int x){
    if(cnt == 3 || x > n)return 0;
    if(dp[cnt][x]!=-1)return dp[cnt][x];
    dp[cnt][x] = 0;
    dp[cnt][x] = dfs(cnt, x+1);
    if(divi + x - 1 <= n){
        dp[cnt][x] = max(dp[cnt][x], dfs(cnt+1, x+divi) + prefix[divi + x - 1] - prefix[x-1]);
    }
    return dp[cnt][x];
}
int main(){
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i{1};i<=n;i++){
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }
    cin >> divi;
    cout << dfs(0,1);
    return 0;
}