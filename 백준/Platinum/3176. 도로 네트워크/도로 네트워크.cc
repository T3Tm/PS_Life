#include <bits/stdc++.h>
using namespace std;
const int MX = 100002;
const int LOG = 20;
const int ROOT = 1;
const int INF = 0x3f3f3f3f;
vector<vector<pair<int,int>>> graph;

int sparse_table[LOG][MX];
int sparse_min[LOG][MX];
int sparse_max[LOG][MX];
int height[MX];

void dfs(int cur, int parent){
    sparse_table[0][cur] = parent;
    height[cur] = height[parent] + 1; 
    for(auto &[next, cost]: graph[cur]){
        if(next == parent)continue;
        sparse_min[0][next] = cost;
        sparse_max[0][next] = cost;
        dfs(next, cur);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;
    memset(sparse_min, 0x3f, sizeof sparse_min);
    graph.resize(n+1);

    for(int i{1};i<n;i++){
        int u,v,cost;cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }

    dfs(ROOT,0);

    for(int i = 1;i<LOG;i++){
        for(int j=1;j<=n;j++){
            sparse_table[i][j] = sparse_table[i-1][sparse_table[i-1][j]];
            sparse_min[i][j] = min(sparse_min[i-1][j], sparse_min[i-1][sparse_table[i-1][j]]);
            sparse_max[i][j] = max(sparse_max[i-1][j], sparse_max[i-1][sparse_table[i-1][j]]);
        }
    }

    int q;cin >> q;
    while(q--){
        int a,b;cin >> a >> b;
        if(height[a] > height[b])swap(a,b);

        int min_v {INF}, max_v{-1};
        for(int i = LOG - 1;i>=0;i--){
            if(height[b] - height[a] >= 1 << i){
                max_v = max(max_v, sparse_max[i][b]);
                min_v = min(min_v, sparse_min[i][b]);
                b = sparse_table[i][b];
            }
        }

        if(a == b){
            cout << min_v << ' ' << max_v << '\n';
            continue;
        }

        for(int i = LOG - 1;i>=0;i--){
            if(sparse_table[i][b] != sparse_table[i][a]){
                max_v = max(max_v, sparse_max[i][b]);
                min_v = min(min_v, sparse_min[i][b]);
                max_v = max(max_v, sparse_max[i][a]);
                min_v = min(min_v, sparse_min[i][a]);
                b = sparse_table[i][b];
                a = sparse_table[i][a];
            }
        }
        max_v = max(max_v, sparse_max[0][b]);
        min_v = min(min_v, sparse_min[0][b]);

        max_v = max(max_v, sparse_max[0][a]);
        min_v = min(min_v, sparse_min[0][a]);
        cout << min_v << ' ' << max_v << '\n';
    }
    return 0;
}