#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n, k;cin >> n >> k;

    bool graph[402][402]{};
    for(int i=0;i<k;i++){
        int u,v;cin >> u >> v;
        graph[u][v]=1;//u->v갈 수 있음
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j)continue;
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = 1;
                }
            }
        }
    }


    

    int s; cin >> s;
    for(int i=0;i<s;i++){
        int u,v;cin >> u >> v;
        if(graph[u][v]){
            cout << -1 << '\n';
        }else if(graph[v][u]){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }

    return 0;
}