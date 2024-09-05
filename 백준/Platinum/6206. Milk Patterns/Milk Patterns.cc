#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
typedef long long ll;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static uint64_t splitmix64(pair<uint64_t,uint64_t> x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x.first += 0x9e3779b97f4a7c15;
        x.first = (x.first ^ (x.first >> 30)) * 0xbf58476d1ce4e5b9;
        x.first = (x.first ^ (x.first >> 27)) * 0x94d049bb133111eb;


        x.second += 0x9e3779b97f4a7c15;
        x.second = (x.second ^ (x.second >> 30)) * 0xbf58476d1ce4e5b9;
        x.second = (x.second ^ (x.second >> 27)) * 0x94d049bb133111eb;
        return x.first^x.second ^ (x.first^x.second >> 31);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64({x.first + FIXED_RANDOM, x.second + FIXED_RANDOM});
    }
};

int to_int(const char& v){
    return v - 'a' + 1;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n,z;cin >> n >> z;
    int tmp[20002]{};   
    for(int i=0;i<n;i++){
        cin >> tmp[i];
    }


    int left = 1, right = n-1;
    int p[]{1000003,1000033};
    int m[]{(int)1e9 + 7, (int)1e9 + 9};

    ll p_pow[2][20002]{};
    for(int k=0;k<2;k++){
        p_pow[k][0] = 1;

        for(int i=1;i<n;i++){
            p_pow[k][i] = (p_pow[k][i-1] * p[k])%m[k];
        }
    }

    
    
    while(left <= right){
        int mid = (left + right) >> 1;
        
        pair<ll,ll> my_hash = {0,0};
        for(int k = 0;k<2;k++){
            for(int i=0;i<mid;i++){//0,1,2
                if(k){
                    my_hash.second = (my_hash.second + p_pow[k][mid-i-1] * tmp[i])%m[k];
                }else{
                    my_hash.first = (my_hash.first + p_pow[k][mid-i-1] * tmp[i])%m[k];
                }
            }
        }
        __gnu_pbds::gp_hash_table<pair<ll,ll>,int,custom_hash> save;

        save.insert({my_hash, 1});
        bool flag = 0;
        for(int i=mid;i<n;i++){
            for(int k=0;k<2;k++){
                if(k){
                    my_hash.second = ((my_hash.second - p_pow[k][mid -1]*tmp[i-mid])*p[k] + tmp[i])%m[k];
                    if(my_hash.second < 0)my_hash.second += m[k];
                }else{
                    my_hash.first = ((my_hash.first - p_pow[k][mid -1]*tmp[i-mid])*p[k] + tmp[i])%m[k];

                    if(my_hash.first < 0)my_hash.first += m[k];
                }
            }
            if(save.find(my_hash)!= save.end()){
                save[my_hash]++;
            }else{
                save.insert({my_hash, 1});
            }

            if(save[my_hash] >= z){
                flag = 1;
                break ;
            }
        }
        
        if(flag){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << right;
    return 0;
}