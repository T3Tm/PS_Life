#include <bits/stdc++.h>
using namespace std;
const int MX = 1e4 + 2;
vector<vector<pair<int,int>>>graph,reverse_graph;

unordered_map<int, unordered_map<int,int>> mark;//
set<pair<int,int>>visited;

void dfs(int cur, int time,int & cnt){
    for(auto &[nxt, nxt_time] : reverse_graph[cur]){
        if(visited.find({cur,nxt})!= visited.end())continue;//이미 갔던 곳
        //lgn
        if(mark[cur][nxt] == time){
            cnt++;
            visited.insert({cur,nxt});
            dfs(nxt, time - nxt_time, cnt);
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;
    graph.resize(n+1);reverse_graph.resize(n+1);
    

    int indegree[MX]{};
    int time_table[MX]{};
    for(int i{};i<m;i++){
        int u,v,time;cin >> u >> v >> time;
        graph[u].push_back({v,time});
        reverse_graph[v].push_back({u,time});
        indegree[v]++;
    }
    int s, e;cin >> s >> e;

    queue<int> q;
    for(int i{1};i<=n;i++){
        if(!indegree[i])q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();q.pop();
        for(auto &[nxt, nxt_time] : graph[cur]){
            time_table[nxt] = max(time_table[nxt], time_table[cur] + nxt_time);
            mark[nxt][cur] = time_table[cur] + nxt_time;
            if(!--indegree[nxt]){
                q.push(nxt);
            }
        }
    }

    cout << time_table[e] << '\n';
    int edge{};
    dfs(e, time_table[e], edge);
    cout << edge;

    return 0;
}