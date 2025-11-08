#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 4 * 1e3 + 2;
enum Speed{
    FASTER,
    SLOWER,
    NORMAL
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;

    vector<vector<pair<int,int>>>graph(n+1);
    for(int i{};i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        c <<=1;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    //dist, 속도, vertex
    priority_queue<tuple<long long, Speed, int>>pq;
    pq.push({0, NORMAL, 1});
    
    long long fox_dist[MAX_SIZE]; memset(fox_dist, 0x3f, sizeof fox_dist);
    fox_dist[1] = 0;

    
    while(!pq.empty()){
        auto[d, nowSpeed, cur] = pq.top();pq.pop();
        if(fox_dist[cur] < -d)continue;

        for(auto &[nex, nex_dist] : graph[cur]){
            long long next_dist = nex_dist - d;
            if(fox_dist[nex] <= next_dist)continue;
            fox_dist[nex] = next_dist;
            pq.push({-next_dist, NORMAL, nex});
        }
    }

    long long wolf_dist[2][MAX_SIZE];memset(wolf_dist, 0x3f, sizeof wolf_dist);
    wolf_dist[!FASTER][1] = 0;

    pq.push({0, FASTER, 1});
    while(!pq.empty()){
        auto[d, nowSpeed, cur] = pq.top();pq.pop();
        if(wolf_dist[!nowSpeed][cur] < -d)continue;
        
        for(auto &[nex, nex_dist] : graph[cur]){
            long long next_dist = -d;
            switch (nowSpeed){
                case FASTER:
                    next_dist += nex_dist >> 1;
                    break;
                case SLOWER:
                    next_dist += nex_dist << 1;
                    break;
            }
            if(wolf_dist[nowSpeed][nex] <= next_dist)continue;
            wolf_dist[nowSpeed][nex] = next_dist;
            pq.push({-next_dist, (nowSpeed == FASTER ? SLOWER : FASTER), nex});
        }
    }

    int answer{};
    for(int ver{2}; ver <= n; ver++){
        if(min(wolf_dist[FASTER][ver], wolf_dist[SLOWER][ver]) <= fox_dist[ver])continue;
        answer++;
    }
    cout << answer;
    return 0;
}