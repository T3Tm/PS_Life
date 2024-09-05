#include <bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace std;
int A[4002],B[4002],C[4002],D[4002];
__gnu_pbds::gp_hash_table<int, int, custom_hash> ab;
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n; // <=4000
    for(int i=0;i<n;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }    

    for(int i=0;i<n;i++){//배열 A에 있는 숫자 중 하나를 뽑는다.
        for(int j=0;j<n;j++){
            ab[A[i] + B[j]]++;
        }
    }
    
    long long cnt{};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ab.find(-(C[i] + D[j])) != ab.end()){
                cnt += ab[-(C[i] + D[j])];    
            }
        }
    }

    cout << cnt;
    return 0;
}