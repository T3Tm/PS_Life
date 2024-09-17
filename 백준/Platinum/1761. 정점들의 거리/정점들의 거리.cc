#include <bits/stdc++.h>
using namespace std;
const int LOG = 17;
const int ROOT = 1;//루트를 1번으로 한다.
int sparse_table[40002][LOG];
int sparse_dist[40002][LOG];
int height[40002];
vector<vector<pair<int,int>>> graph;


void dfs(int cur, int parent){
    height[cur] = height[parent] + 1; 
    sparse_table[cur][0] = parent;
    for(auto&[nxt, dist] : graph[cur]){
        if(nxt == parent)continue;
        sparse_dist[nxt][0] = dist;
        dfs(nxt, cur);
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    graph.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v,dist;cin >> u >> v >> dist;
        graph[u].push_back({v,dist});
        graph[v].push_back({u,dist});
    }
    dfs(ROOT, 0);

    for(int i=1;i<LOG;i++){
        for(int j=1;j<=n;j++){
            sparse_table[j][i] = sparse_table[sparse_table[j][i-1]][i-1];
            sparse_dist[j][i] = sparse_dist[sparse_table[j][i-1]][i-1] + sparse_dist[j][i-1];
        }
    }

    int m;cin >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >>v;
        if(height[u] > height[v])swap(u,v);

        int total{};
        for(int i=LOG-1; i>=0;i--){
            if(height[v] - height[u] >= 1 << i){
                total += sparse_dist[v][i];
                v = sparse_table[v][i];
            }
        }

        if(u == v){
            cout << total << '\n';
        }else{
            for(int i = LOG-1; i>=0;i--){
                if(sparse_table[u][i] != sparse_table[v][i]){
                    total += sparse_dist[u][i];
                    total += sparse_dist[v][i];
                    u = sparse_table[u][i];
                    v = sparse_table[v][i];
                }
            }
            cout << total + sparse_dist[u][0] + sparse_dist[v][0] << '\n';
        }
    }
    return 0;
}