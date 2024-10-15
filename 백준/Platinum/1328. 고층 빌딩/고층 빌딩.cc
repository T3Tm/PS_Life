#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int MX = 101;

int dp[MX][MX][MX];
int combi[MX][MX];

int func(int n, int l,int r){
    if(l > r)swap(l,r);

    if(n == 0)return 1;
    else if(l == 0 || r == 0)return 0;
    else if(n == 1){
        if(l == 1 && r == 1)return 1;
        return 0;
    }
    
    if(dp[n][l][r] != -1)return dp[n][l][r];
    dp[n][l][r] = 0;
    for(int div = l; div <= n - r + 1; div++){//3 1 2
        int com = combi[n - 1][div-1];

        int left = 0;//3 1 2
        
        for(int i = 1;i  <=  div-1; i++) { // 
            left = (left + func(div-1, l-1, i)) % mod;
        }
        if(div-1 == 0)left = 1;
        
        int right = 0;
        for(int i = 1;i <= n - div; i++){
            right = (right + func(n - div, i, r-1))%mod;
        } 
        if(n - div == 0)right = 1;//2

        dp[n][l][r] = (dp[n][l][r] + (com * ((left * right)%mod))%mod) %mod;
    }
    return dp[n][l][r];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,l,r;cin >> n >> l >> r;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<= i; j++){
            if(j == 0 || j == i)combi[i][j] = 1;
            else{
                combi[i][j] = (combi[i-1][j-1] + combi[i-1][j])%mod;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    cout << func(n, l, r);
    return 0;
}