#include <bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<int,__gnu_pbds::gp_hash_table<int, int, custom_hash>>dp;
unordered_map<int,int>numbering;
int unused = 1;//이걸로 매핑 해주기
int arr[2002];
int dfs(int next, int gap){
    if(numbering.find(next) == numbering.end() || numbering[next] == 0){
        return 0;
    }
    if(dp.find(next) != dp.end() && dp[next].find(gap) != dp[next].end()){
        return dp[next][gap];
    }

    numbering[next]--;
    int value = 0;
    value = max(dfs(next + gap, gap) + 1, value);
    dp[next][gap] = value;
    numbering[next]++;

    return dp[next][gap];
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int num;cin >> num;
        if(numbering.count(num)){
            numbering[num]++;
        }else{
            numbering.insert({num, 1});
        }
        arr[i] = num;
        dp[num] = {};
    }
    sort(arr,arr+n);
    
    int result{1};
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            result = max(result, dfs(arr[i], arr[j] - arr[i]));
        }
        numbering[arr[i]]--;
        if(numbering[arr[i]] == 0){
            dp.erase(arr[i]);
        }
    }
    cout << result;
    return 0;
}