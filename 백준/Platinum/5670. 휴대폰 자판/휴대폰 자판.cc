#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e6;
const int ROOT = 1;

int nxt[MX+2][26];
int unused = 2;
bool chk[MX+2];
inline int c2i(const char&v){
    return v - 'a';
}
void insert(const string& s){
    int cur = ROOT;
    for(auto &v: s){
        if(nxt[cur][c2i(v)] == 0){
            nxt[cur][c2i(v)] = unused++;
        }
        cur = nxt[cur][c2i(v)];
    }
    chk[cur]=1;
}
int total;
void find(int cur, int cnt){
    int nexts{};
    for(int i=0;i<26;i++){
        if(nxt[cur][i])nexts++;
    }
    for(int i=0;i<26;i++){
        if(nxt[cur][i]){
            if(nexts == 1 && !chk[cur]){
                find(nxt[cur][i], cnt);
            }else{
                find(nxt[cur][i],cnt + 1);
            }
        }
    }
    if(chk[cur])total += cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cout << fixed;
    cout.precision(2);
    while(cin >> n){
        memset(nxt, 0, sizeof nxt);
        memset(chk, 0, sizeof chk);
        unused = 2;
        chk[1] = 1;
        for(int i=0;i<n;i++){
            string a;cin >> a;
            insert(a);
        }
        total = 0;
        find(ROOT,0);
        cout << (double)total/n << '\n';//이러면 큰일이지 않나..
    }
    return 0;
}