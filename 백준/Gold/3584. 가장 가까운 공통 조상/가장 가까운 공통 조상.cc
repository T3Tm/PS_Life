#include <bits/stdc++.h>
using namespace std;
int height[10002];
int parent[10002][16];
int indegree[10002];
vector<vector<int>>graph;
void dfs(int cur, int parent){
    height[cur] = height[parent]+1;
    for(auto& next:graph[cur]){
        dfs(next,cur);
    }
}
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        graph.clear(); graph.resize(n+1);
        memset(height, 0,sizeof height);
        memset(parent, 0,sizeof parent);
        memset(indegree, 0,sizeof indegree);
        
        
        for(int i=1;i<n;i++){
            int u,v;cin >> u >> v;
            graph[u].push_back(v);
            parent[v][0] = u;
            indegree[v]++;
        }

        for(int i=1;i<=n;i++){
            if(!indegree[i]){
                dfs(i, 0);
                break;
            }
        }

        for(int i=1; i < 16; i++){
            for(int j=1;j<=n;j++){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }

        int a,b;cin >> a >> b;
        if(height[a] > height[b])swap(a,b);
        
        for(int i = 15;i>=0;i--){
            if(height[b] - height[a] >= 1 << i){
                b = parent[b][i];
            }
        }

        if(a == b){
            cout << a << '\n';
        }else{
             for(int i=15;i>=0;i--){
                 if(parent[a][i] != 0 && parent[a][i]!= parent[b][i]){
                     a = parent[a][i];
                     b = parent[b][i];    
                 }
             }
            cout << parent[a][0] << '\n';
        }
    }
    return 0;
}