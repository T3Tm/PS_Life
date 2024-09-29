#include <bits/stdc++.h>
using namespace std;
const int INF= 0x3f3f3f3f;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;
    int dist[102][102];memset(dist, 0x3f, sizeof dist);
    

    int trace[102][102];memset(trace, 0, sizeof trace);
    for(int i{};i<m;i++){
        int u,v,cost; cin >> u >> v >> cost;
        if(dist[u][v] > cost){
            dist[u][v] = cost;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j)continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    trace[i][j] = k;
                }
            }
        }
    }   
    /*
        0 2 3 1 4
        12 0 15 2 5
        8 5 0 1 1
        10 7 13 0 3
        7 4 10 6 0
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }


    auto Find = [&](auto self, int from, int to,vector<int>&result)->void{
        if(!trace[from][to])return;
        self(self, from, trace[from][to],result);
        result.push_back(trace[from][to]);
        self(self,trace[from][to],to,result);
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INF){
                cout << 0 << '\n';
                continue;
            }
            vector<int> result;
            Find(Find,i,j, result);
            cout << result.size() + 2 << ' ' << i << ' ';
            for(auto &v: result)cout << v << ' ';
            cout << j <<'\n';
        }
    }

    return 0;
}