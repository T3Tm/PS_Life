#include <bits/stdc++.h>
using namespace std;

/*
    N(1 ≤ N ≤ 10,000)과 도로의 수 M(1 ≤ M ≤ 50,000)과 포장할 도로의 수 K(1 ≤ K ≤ 20)

    도로를 포장하는 순간 지나가는 cost : 0
    도로들은 양방향 도로이며, 걸리는 시간은 1,000,000보다 작거나 같은 자연수이다.

    1번 도로에서 N번 도로로 가야 된다.

    K개 이하의 도로를 포장하여 얻을 수 있는 최소 시간을 출력한다.

    k개 이하로 포장하여 얻을 수 있는 최소 시간?...
    
    1 -> 2
    DP[i][k]
    
*/
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long dp[22][10002];
vector<vector<pair<int,int>>>graph;
int n, m, k;

struct myPair{
    long long v, cost, road;
    bool operator()(const myPair& a, const myPair& b){
        return a.cost > b.cost;
    }
};
long long bfs(){
    priority_queue<myPair, vector<myPair>, myPair>q;
    memset(dp, 0x3f, sizeof dp);
    q.push({1, 0, 0});
    dp[0][1] = 0;
    while(!q.empty()){
        auto [cur, cur_cost, cur_road] = q.top();q.pop();
        if(cur == n)return cur_cost;
        if(dp[cur_road][cur] < cur_cost)continue;
        for(auto&[nxt, nxt_cost]: graph[cur]){
            if(dp[cur_road][nxt] > cur_cost + nxt_cost){
                dp[cur_road][nxt] = cur_cost + nxt_cost;
                q.push({nxt,dp[cur_road][nxt], cur_road});
            }
            if(cur_road+1 <= k && dp[cur_road+1][nxt] > cur_cost){
                dp[cur_road + 1][nxt] = cur_cost;
                q.push({nxt, dp[cur_road+1][nxt], cur_road+1});
            }
        }
    }
    return INF;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,c; cin >> u >> v >> c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    cout << bfs();
    return 0;
}