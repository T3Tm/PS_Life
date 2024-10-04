#include <bits/stdc++.h>

using namespace std;
const int MX = 10002;

struct edge{
    int u,v,cost;
};

int parent[MX];

int min_cost[MX];
int find(int x){
    if(parent[x] < 0)return x;
    return parent[x] = find(parent[x]);
}

void nerge(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(x > y)swap(x,y);
    parent[x] += parent[y];
    min_cost[x] = min(min_cost[x], min_cost[y]);
    parent[y] = x;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,k;cin >> n >> m >> k;
    memset(parent, -1, sizeof parent);
    for(int i{1};i<=n;i++){
        cin >> min_cost[i];
    }

    //가장 적은 비용으로 모든 간선을 이어서 mst를 완성
    vector<edge>edges;
    for(int i{};i<m;i++){
        int u,v;cin >> u >> v;
        edges.push_back({u,v,min(min_cost[u], min_cost[v])});
    }

    sort(edges.begin(), edges.end(), [](const edge& a, const edge&b){
        return a.cost < b.cost; 
    });

    int cnt{};
    for(auto &[u,v,cost]:edges){
        if(cnt == n-1)break;
        if(find(u)!= find(v)){
            nerge(u,v);
            cnt++;
        }
    }
    int total{};
    for(int i=1;i<=n;i++){
        if(parent[i] < 0)total += min_cost[i];
    }
    if(total <= k){
        cout << total;
    }else{
        cout << "Oh no";
    }
    
    return 0;
}