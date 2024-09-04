#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int>dp;
    int num;cin >> num;
    dp.push_back(num);
    for(int i=1;i<n;i++){
        cin >> num;
        auto it = lower_bound(dp.begin(),dp.end(), num) - dp.begin();
        if(dp[it] < num)dp.push_back(num);
        else dp[it] = num;
    }
    cout << dp.size();
}