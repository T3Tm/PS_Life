#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;//2 * 10^5
    
    vector<int>dp;
    int num;cin >> num;
    dp.push_back(num);
    
    for(int i = 1;i<n;i++){
        cin >> num;
        auto it = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
        if(dp.back() < num)dp.push_back(num);
        else dp[it] = num;
    }
    cout << n - dp.size();
    return 0;
}