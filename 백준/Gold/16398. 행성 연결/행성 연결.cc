#include <bits/stdc++.h>
using namespace std;
/*
    cost 100,000,000
*/
const int MX = 1002;
struct edge{
    int u,v,cost;
};

int parent[MX];

int find(int x){
    if(parent[x] < 0)return x;
    return parent[x] = find(parent[x]);
}

void nerge(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(x >y)swap(x,y);
    parent[x] += parent[y];
    parent[y] = x;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;
    memset(parent, -1,sizeof parent);
    vector<edge>edges;
    for(int i{};i<n;i++){
        for(int j{},tmp;j<n;j++){
            cin >> tmp;
            if(tmp == 0)continue;
            edges.push_back({i,j,tmp});
        }
    }

    sort(edges.begin(), edges.end(),[](const edge&a, const edge&b){
        return a.cost < b.cost;
    });
    long long result{};
    for(int i{}, cnt{}; cnt != n-1;i++){
        auto& [u,v,cost] = edges[i];
        if(find(u) != find(v)){
            nerge(u,v);
            result += cost;
            cnt++;
        }
    }

    cout << result;
    return 0;
}