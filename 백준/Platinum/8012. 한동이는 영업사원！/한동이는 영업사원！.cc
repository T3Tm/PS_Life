#include <bits/stdc++.h>
using namespace std;
const int LOG = 16;
const int ROOT = 1;
const int MX = 30000 + 2;
int sprase_table[MX][LOG];
int sprase_dist[MX][LOG];
int height[MX];
vector<vector<int>> graph;
void dfs(int cur, int parent){
    sprase_table[cur][0] = parent;
    height[cur] = height[parent] + 1;
    for(auto &nxt: graph[cur]){
        if(nxt == parent)continue;
        sprase_dist[nxt][0] = 1;
        dfs(nxt, cur);
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    graph.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(ROOT, 0);

    for(int i = 1;i < LOG;i++){
        for(int j=1;j<=n;j++){
            sprase_table[j][i] = sprase_table[sprase_table[j][i-1]][i-1];
            sprase_dist[j][i] = sprase_dist[sprase_table[j][i-1]][i-1] + sprase_dist[j][i-1];
        }
    }


    int last{1};
    int m;cin >> m;
    int total{};
    for(int i=0;i<m;i++){
        int v;cin >> v;//내가 가야 되는 곳
        
        int tmp_v = v;
        if(height[last] > height[tmp_v])swap(last, tmp_v);
        
        for(int i = LOG-1; i >= 0; i--){
            if(height[tmp_v] - height[last] >= 1 << i){
                total += sprase_dist[tmp_v][i];        
                tmp_v = sprase_table[tmp_v][i];
            }
        }

        if(last == tmp_v){
            last = v;
            continue;
        }else{
            
            for(int i=LOG-1; i>=0; i--){
                if(sprase_table[tmp_v][i] != sprase_table[last][i]){
                    total += sprase_dist[tmp_v][i];
                    total += sprase_dist[last][i];

                    tmp_v = sprase_table[tmp_v][i];
                    last = sprase_table[last][i];
                }
            }
            total += sprase_dist[tmp_v][0] + sprase_dist[last][0];
            last = v;
        }
    }
    cout << total;
    return 0;
}