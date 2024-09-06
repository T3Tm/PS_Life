#include <bits/stdc++.h>
using namespace std;


const int MX = 1e9;
const int MXSIZE = 500002;
vector<vector<pair<int,char>>>graph;


int n, l;
int to_int(const char& v){
    return v - 'a' + 1;
}

long long pattern[]{0,0};
int p[]{31,37};
int m[]{MX + 7, MX + 9};

long long p_pow[2][MXSIZE];
int result;
char pick[MXSIZE];
void dfs(int cur, long long hash1, long long hash2, char now[], int depth){
    long long now_hash[] = {hash1, hash2};
    if(depth){
        if(depth > l){
            for(int k{}; k<2;k++){
                now_hash[k] = ((now_hash[k] - (to_int(now[depth - l - 1]) * p_pow[k][l-1])%m[k]) *p[k] + to_int(now[depth - 1]))%m[k];
                if(now_hash[k] < 0)now_hash[k] += m[k];
            }
        }else{
            for(int k{}; k < 2;k++){
                now_hash[k] = (now_hash[k] + (to_int(now[depth - 1]) * p_pow[k][l-depth])%m[k])%m[k];
                if(now_hash[k] < 0)now_hash[k] += m[k];
            }
            
        }
    }

    if(now_hash[0] == pattern[0] && now_hash[1] == pattern[1]){
        result++;
    }

    for(auto &[next, flower]: graph[cur]){
        now[depth] = flower;
        dfs(next, now_hash[0], now_hash[1], now, depth+1);
        now[depth] = ' ';
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n;
    graph.resize(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        char c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
    }


    string target;cin >> target;
    l = target.size();


    for(int k{};k<2;k++){
        p_pow[k][0] = 1;
        for(int i=1;i<l;i++){
            p_pow[k][i] = (p_pow[k][i-1]*p[k])%m[k];
            if(p_pow[k][i] < 0)p_pow[k][i] += m[k];
        }
    }
    
    for(int k{};k < 2;k++){
        for(int i=0;i<l;i++){
            pattern[k] = (pattern[k] + (p_pow[k][l-i-1]*to_int(target[i]))%m[k])%m[k];
        }
    }

    pick[MXSIZE - 1] = '\n';//일단 마지막에 넣어놓기

    dfs(1, 0, 0, pick, 0);
    cout << result;
    return 0;
}