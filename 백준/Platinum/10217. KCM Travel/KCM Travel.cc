#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m,k;

struct Pair{
    int v,c,d;
    bool operator()(const Pair& a, const Pair& b){
        return a.d > b.d;
    }
};
vector<vector<Pair>>graph;
int KCM_Travel(){
    int dp[102][10002];
    memset(dp, 0x3f, sizeof dp);
    priority_queue<Pair, vector<Pair>,Pair>pq;
    pq.push({1,0,0});
    dp[1][0] = 0;
    while(!pq.empty()){
        auto [cur, cur_cost, cur_distance] = pq.top(); pq.pop();
        if(cur == n)return cur_distance; //제일 빠르게 해당 n에 도달했음
        if(cur_cost == m)continue;
        if(cur_distance > dp[cur][cur_cost])continue;

        for(auto &[nxt, nxt_cost, nxt_distance]: graph[cur]){
            if(cur_cost + nxt_cost > m)break;//여기서 break를 걸 수 있게됨
            
            if(dp[nxt][cur_cost + nxt_cost] > cur_distance + nxt_distance){
                dp[nxt][cur_cost + nxt_cost] = cur_distance + nxt_distance;

                pq.push({nxt, cur_cost + nxt_cost, cur_distance + nxt_distance});
            }
        }
    }
    return INF;
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