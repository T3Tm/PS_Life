#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e5 + 2;
const int INF = 0x3f3f3f3f;
int n;
int energy[MX];//i아이가 가지고 있는 에너지
int sparse_table[MX][18];//i노드에서 2^j갔을 때 정점
int sparse_energy[MX][18];//i 노드 에서 2^j가는데 드는 비용
vector<vector<pair<int,int>>>graph;
void dfs(int cur, int parent){
    sparse_table[cur][0] = parent;
    for(auto &[next,cost]: graph[cur]){
        if(next == parent)continue;
        sparse_energy[next][0] = cost;
        dfs(next, cur);
    }
}
int main(){
    cin >> n;
    graph.resize(n+1);
    
    for(int i=1;i<=n;i++)cin >> energy[i];
    memset(sparse_energy,0x3f, sizeof sparse_energy);
    for(int i=1;i<n;i++){
        int u,v, cost ;cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }
    dfs(1,0);
    for(int i=1;1 << i <n;i++){
        for(int j=2;j<=n;j++){
            if(sparse_energy[sparse_table[j][i-1]][i-1] >= INF)continue;
            sparse_table[j][i] = sparse_table[sparse_table[j][i-1]][i-1];
            sparse_energy[j][i] = sparse_energy[sparse_table[j][i-1]][i-1] + sparse_energy[j][i-1];
        }
    }
    
    for(int a=1;a<=n;a++){
        int& now_cost = energy[a];
        int now_cur = a;
        for(int i=17;i>=0;i--){
            if(now_cost >= sparse_energy[now_cur][i]){
                now_cost -= sparse_energy[now_cur][i];
                now_cur = sparse_table[now_cur][i];
            }
        }
        cout << now_cur << '\n';
    }
    
    return 0;
}