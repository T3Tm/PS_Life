#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m,k;

struct Pair{
    int v,c,d;
};
int dp[102][10002];
vector<vector<Pair>>graph;
int dfs(int cur, int cost){
    if(cur == n)return 0;
    if(dp[cur][cost]!=-1)return dp[cur][cost];

    dp[cur][cost] = INF;
    for(auto&[nxt, nxt_cost, nxt_dist]:graph[cur]){
        if(cost + nxt_cost > m)break;
        dp[cur][cost] = min(dp[cur][cost], dfs(nxt, nxt_cost + cost) + nxt_dist);
    }
    return dp[cur][cost];
}
int KCM_Travel(){

    memset(dp, -1, sizeof dp);
    return dfs(1,0);
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        cin >> n >> m >>k;
        graph.clear(); graph.resize(n+1);

        for(int i=0;i<k;i++){
            int u,v,c,d; cin >> u >> v >> c >> d;
            if(u == v)continue;
            if(v == 1)continue;
            graph[u].push_back({v,c,d});
        }

        for(int i=1;i<=n;i++){
            sort(graph[i].begin(), graph[i].end(),[](const Pair& a, const Pair& b){//각 지점에서 오름차순하기
                return a.c < b.c;
            });
        }

        int ret = KCM_Travel();

        if(ret == INF){
            cout << "Poor KCM\n";
        }else{
            cout << ret << '\n';
        }
    }
    return 0;
}