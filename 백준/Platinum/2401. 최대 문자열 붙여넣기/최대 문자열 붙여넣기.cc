#include <bits/stdc++.h>
using namespace std;
const int MX = 100002;
int dp[MX];//10
// int tree[MX << 1];//20만
// void init(int n){
//     for(int p = n-1;p>0;p--)tree[p] = max(tree[p<<1], tree[p<<1|1]);
// }

// void update(int idx, int v,int n){
//     for(tree[idx+=n] = v;idx > 1 ;idx>>=1)tree[idx >> 1] = max(tree[idx] , tree[idx^1]);
// }

// int query(int i, int j,int n){
//     int ret{};
//     for(i+=n, j+=n; i<j;i>>=1,j>>=1){
//         if(i&1)ret = max(ret, tree[i++]);
//         if(j&1)ret = max(ret, tree[--j]);
//     }
//     return ret;
// }
vector<vector<int>>f;
void failure(vector<int>&t, const string &word){
    int l = word.size();
    t.resize(l);
    t[0] = -1;
    for(int i=1;i<l;i++){
        int j = t[i-1];
        while(j>=0 && word[j+1] != word[i]){
            j = t[j];//f[0] = 0이잖아
        }
        t[i] = j + 1;
    }
}
void kmp(const string& target,vector<string> &words){//word라는 아이가 target에 등장하는지 확인하면 된다.
    //word를 일단 대소문자 포함돼있으므로 kmp
    int n = target.size() -1;
    //5,000,000
    //target에 이제 word가 몇 번 나타나는지 확인
    vector<int>js(words.size());
    for(int i=1;i<target.size();i++){
        dp[i] = max(dp[i], dp[i-1]);
        for(int p{};p<words.size();p++){
            int l = words[p].size();
            int j = js[p];
            while(j>=0 && words[p][j+1] != target[i]){
                j = f[p][j];
            }
            j++;
            if(j == l-1){
                dp[i]= max(dp[i], dp[i-(l-1)] + (l-1));
                j = f[p][j];
            }
            js[p] = j;
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string a;cin >> a;
    a = ' '+a;
    int n;cin >> n;
    f.resize(n);
    vector<string>pattern(n);
    for(auto &v:pattern)cin >> v;
    //이렇게 하면 안
    //접두사가 많이 겹치는 순으로 먼저 들어가야 되네..

    //정렬을 그러면
    //
    //[1 : 10]
    //[11 : 15]
    for(int i{};i<n;i++){
        pattern[i] = ' '+ pattern[i];
        failure(f[i],pattern[i]);
    }

    kmp(a,pattern);

    int l = a.size()-1;
    //뒤에서 부터
    cout << dp[l];
    return 0;
}