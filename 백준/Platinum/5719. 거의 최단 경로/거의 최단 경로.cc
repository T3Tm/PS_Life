#include <bits/stdc++.h>
using namespace std;
const int MX = 502;
const int INF = 0x3f3f3f3f;

unordered_map<int, int>graph[MX];
vector<vector<pair<int,int>>> reverse_graph;

int mark[MX][MX];
int dist[MX];
priority_queue<pair<int,int>>q;

void dfs(int cur, int distance){
    vector<int> query;
    for(auto &[nxt, nxt_cost] : graph[cur]){
        if(mark[cur][nxt] == distance){
            query.push_back(nxt);
            dfs(nxt, distance - nxt_cost);
        }
    }

    while(!query.empty()){
        int front = query.back();query.pop_back();
        graph[cur].erase(front);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    while(1){
        int n,m;cin >> n >> m;
        if(!n)break;
        int s,d;cin >> s >> d;
        for(int i{};i<n;i++){
            graph[i].clear();
        }
        reverse_graph.clear();reverse_graph.resize(MX);
        memset(mark, 0x3f, sizeof mark);

        for(int i{};i<m;i++){
            int u,v,cost;cin>> u >> v >> cost;
            graph[u][v] = cost;
            reverse_graph[v].push_back({u,cost});
        }


        //다익스트라 한 번 돌리기
        memset(dist, 0x3f, sizeof dist);
        dist[d] = 0;//d -> s로 가기
        q.push({0, d});
        while(!q.empty()){
            auto [cost, cur] = q.top();q.pop();
            cost = -cost;
            if(dist[cur] < cost)continue;
            for(auto &[nxt, nxt_costs] : reverse_graph[cur]){
                int nxt_cost = cost + nxt_costs;
                mark[nxt][cur] = min(mark[nxt][cur], nxt_cost);
                if(nxt_cost < dist[nxt]){
                    dist[nxt] = nxt_cost;
                    q.push({-nxt_cost, nxt});
                }
            }
        }

        dfs(s, dist[s]);

        //다시 s -> d 까지 다익 돌리기
        memset(dist, 0x3f, sizeof dist);
        dist[s] = 0;
        q.push({0, s});
        while(!q.empty()){
            auto [cost, cur] = q.top();q.pop();
            cost = -cost;
            if(dist[cur] < cost)continue;
            for(auto &[nxt, nxt_costs] : graph[cur]){
                int nxt_cost = cost + nxt_costs;
                if(nxt_cost < dist[nxt]){
                    dist[nxt] = nxt_cost;
                    q.push({-nxt_cost, nxt});
                }
            }
        }
        cout << (dist[d] == INF ? -1 : dist[d]) << '\n';
    }
    return 0;
}