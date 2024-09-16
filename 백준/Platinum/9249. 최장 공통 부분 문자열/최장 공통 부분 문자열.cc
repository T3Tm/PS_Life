#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;


/*
    이분탐색 + 라빈카프

    a문자열 rabin
    b문자열 rabin
*/
int p[]{31,37};
int m[]{(int)1e9 + 7, (int)1e9 + 9};
vector<vector<long long>>p_pow;
int to_int(const char& v){
    return v - 'a' + 1;
}
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
    size_t operator()(pair<uint64_t,uint64_t> x) const{
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        static const uint64_t FIXED_RANDOM1 = std::chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x.first + FIXED_RANDOM)^splitmix64(x.second + FIXED_RANDOM1);
    }
};
__gnu_pbds::gp_hash_table<pair<int,int>, int, custom_hash> save;//확인


int getIndex(const string &a, const string&b,int mid){
    save.clear();
    long long my_hash[]{0,0};
    //right 만큼 잘라서 save해놓고
    //해당 곳에 b에서 있는지 확인
    for(int k=0;k<2;k++){//일단 a의 문자열에서 hash를 구해보자
        for(int i=0;i<mid;i++){
            my_hash[k] = (my_hash[k] + to_int(a[i]) * p_pow[k][mid - i - 1])%m[k];
            if(my_hash[k] < 0)my_hash[k] += m[k];
        }
    }
    save[{my_hash[0], my_hash[1]}] = 1;

    for(int i=mid;i<a.size();i++){
        for(int k=0;k<2;k++){
            my_hash[k] = ((my_hash[k] - to_int(a[i - mid]) * p_pow[k][mid - 1]) * p[k] + to_int(a[i]))%m[k];
            if(my_hash[k] < 0)my_hash[k] += m[k];
        }
        save[{my_hash[0], my_hash[1]}] =1;//등록
    }
    my_hash[0] = 0;
    my_hash[1] = 0;
    for(int k=0;k<2;k++){//일단 a의 문자열에서 hash를 구해보자
        for(int i=0;i<mid;i++){
            my_hash[k] = (my_hash[k] + to_int(b[i]) * p_pow[k][mid - i - 1])%m[k];
            if(my_hash[k] < 0)my_hash[k] += m[k];
        }
    }
    if(save.find({my_hash[0], my_hash[1]}) != save.end()){//겹치는 것이 있음.
        return 0;//0번 인덱스이다.
    }
    for(int i=mid;i<b.size();i++){
        for(int k=0;k<2;k++){
            my_hash[k] = ((my_hash[k] - to_int(b[i - mid]) * p_pow[k][mid - 1]) * p[k] + to_int(b[i]))%m[k];
            if(my_hash[k] < 0)my_hash[k] += m[k];
        }
        if(save.find({my_hash[0], my_hash[1]}) != save.end()){
            return i - mid + 1;
        }
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    string a,b;cin >> a >> b;//각 문자열로
    int left=0, right =  min(a.size(), b.size());

    p_pow.resize(2, vector<long long>(right));    
    for(int k=0;k<2;k++){
        p_pow[k][0] = 1;
        for(int i=1;i<right;i++){
            p_pow[k][i] = (p_pow[k][i-1] * p[k])%m[k];
            if(p_pow[k][i] < 0)p_pow[k][i] += m[k];
        }
    }
    while(left<=right){
        int mid = (left+right) >> 1;
        save.clear();//비우기 

        long long my_hash[]{0,0};
        for(int k=0;k<2;k++){//일단 a의 문자열에서 hash를 구해보자
            for(int i=0;i<mid;i++){
                my_hash[k] = (my_hash[k] + to_int(a[i]) * p_pow[k][mid - i - 1])%m[k];
                if(my_hash[k] < 0)my_hash[k] += m[k];
            }
        }
        save[{my_hash[0], my_hash[1]}] = 1;//등록
        
        for(int i=mid;i<a.size();i++){
            for(int k=0;k<2;k++){
                my_hash[k] = ((my_hash[k] - to_int(a[i - mid]) * p_pow[k][mid - 1]) * p[k] + to_int(a[i]))%m[k];
                if(my_hash[k] < 0)my_hash[k] += m[k];
            }
            save[{my_hash[0], my_hash[1]}] =1;//등록
        }
        
        my_hash[0] = 0;
        my_hash[1] = 0;

        for(int k=0;k<2;k++){//일단 a의 문자열에서 hash를 구해보자
            for(int i=0;i<mid;i++){
                my_hash[k] = (my_hash[k] + to_int(b[i]) * p_pow[k][mid - i - 1])%m[k];
                if(my_hash[k] < 0)my_hash[k] += m[k];
            }
        }
        if(save.find({my_hash[0], my_hash[1]}) != save.end()){//겹치는 것이 있음.
            left = mid + 1;
            continue;
        }
        bool flag{};
        for(int i=mid;i<b.size();i++){
            for(int k=0;k<2;k++){
                my_hash[k] = ((my_hash[k] - to_int(b[i - mid]) * p_pow[k][mid - 1]) * p[k] + to_int(b[i]))%m[k];
                if(my_hash[k] < 0)my_hash[k] += m[k];
            }
            if(save.find({my_hash[0], my_hash[1]}) != save.end()){
                flag = 1;
                break;
            }
        }
        if(flag){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << right << '\n';
    if(right){
        int idx = getIndex(a, b, right);
        for(int i = idx; i< idx+right;i++){
            cout << b[i];
        }
    }

    return 0;
}