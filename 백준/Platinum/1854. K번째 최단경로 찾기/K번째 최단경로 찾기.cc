#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MX = 1002;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,k;cin >> n >> m >> k;
    vector<vector<pair<int,int>>>graph(MX);
    for(int i{};i<m;i++){
        int u,v,cost;cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
    }

    vector<multiset<int,greater<>>>dist(MX);
    for(int i = 2; i<=n;i++){
        dist[i].insert(INF);
    }

    dist[1].insert(0);

    priority_queue<pair<int,int>>pq;
    pq.push({0, 1});//cost, cur

    while(!pq.empty()){//1 -> 1
        auto [cos, cur] = pq.top();pq.pop();
        cos = -cos;
        if(cos > *dist[cur].begin())continue;
        for(auto &[nxt,cost]: graph[cur]){
            int nxt_cost = cos + cost;
            dist[nxt].insert(nxt_cost);
            if(dist[nxt].size() > k + 1){
                auto it = dist[nxt].begin();
                int p = *it;
                dist[nxt].erase(it);
                if(p == nxt_cost)continue;
            }
            pq.push({-nxt_cost, nxt});
        }
    }

    for(int i = 1;i<=n;i++){
        for(; dist[i].size()>k;){
            auto it = dist[i].begin();
            dist[i].erase(it);
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i].size() < k)cout << -1 << '\n';
        else {
            auto it = dist[i].begin();
            if(*it == INF)cout << -1 << '\n';
            else cout << *it << '\n';
        }
    }
    return 0;
}