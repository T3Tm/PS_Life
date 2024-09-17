#include <bits/stdc++.h>
#include <bits/extc++.h>
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
    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        static const uint64_t FIXED_RANDOM1 = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM1);
    }
};
__gnu_pbds::gp_hash_table<pair<int,int>, int, custom_hash> save;
vector<vector<int>>pattern;
int p[]{10007, 10009};
int m[]{(int)1e9 + 7, (int)1e9 + 9};
vector<vector<long long>>p_pow(2);
int n,pp;
void rabin_karp(vector<int>&list, int k){
    long long my_hash[]{0,0};
    long long back_hash[]{0,0};

    int l = list.size();
    __gnu_pbds::gp_hash_table<pair<int,int>, int, custom_hash> tmp;
    for(int t = 0; t<2;t++){ // 2 * k번
        for(int i=0;i<k;i++){
            my_hash[t] = (my_hash[t] + list[i] * p_pow[t][k - i - 1]) %m[t];
            back_hash[t] = (back_hash[t] + list[l - 1 - i] * p_pow[t][k - i - 1]) %m[t];
            if(my_hash[t] < 0) my_hash[t] += m[t];
            if(back_hash[t] < 0) back_hash[t] += m[t];
        }
    }
    tmp[{my_hash[0], my_hash[1]}]=1;
    tmp[{back_hash[0], back_hash[1]}]=1;
    
    for(int i=k;i<l;i++){
        for(int t = 0;t<2;t++){
            my_hash[t] = ((my_hash[t] - list[i - k] * p_pow[t][k - 1]) * p[t] + list[i])%m[t];

            back_hash[t] = ((back_hash[t] - list[(l-1) - i + k] * p_pow[t][k - 1]) * p[t] + list[(l-1) - i])%m[t];

            if(my_hash[t] < 0) my_hash[t] += m[t];
            if(back_hash[t] < 0) back_hash[t] += m[t];
        }
        tmp[{my_hash[0], my_hash[1]}]=1;
        tmp[{back_hash[0], back_hash[1]}]=1;
    }
    //4000번
    for(auto &[key,value]:tmp){//4000번
        save[key]++;//각각 갯수 세주기
    }
    //8000번
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> pp;
    pattern.resize(n);
    int mini = 1001;
    for(int i=0;i<n;i++){
        int num;cin >> num;
        mini = min(mini, num);
        pattern[i].resize(num);
        for(auto&v:pattern[i])cin >> v;
    }
    
    for(int t = 0;t<2;t++){
        p_pow[t].resize(1000);
        p_pow[t][0] = 1; 
        for(int i=1;i<1000;i++){
            p_pow[t][i] = (p_pow[t][i-1] * p[t])%m[t];
            if(p_pow[t][i] < 0)p_pow[t][i]+=m[t];
        }
    }
    bool flag{};
    int left = pp, right = mini;
    while(left <=right){
        int mid = (left +right) >> 1;
        save.clear();
        for(int i{};i<n;i++){//n개
            rabin_karp(pattern[i], mid);//8000번
        }
        for(auto&[key, value] : save){
            if(value == n){
                flag=1;
                break;
            }
        }
        if(flag)break;
        else {
            right = mid - 1;
        }
    }
    if(!flag)cout << "NO";
    else cout << "YES";
    return 0;
}