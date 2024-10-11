#include <bits/stdc++.h>
using namespace std;
const int MX = 1002;
int parent[MX];
int find(int x){
    if(parent[x] < 0)return x;
    return parent[x] = find(parent[x]);
}

void nerge(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(x > y)swap(x,y);
    parent[y] += parent[x];
    parent[x] = y;
}
struct vertex{
    int x,y;
};
struct edge{
    vertex cur;
    long long dis;  
};
inline long long mypow(long long x){
    return x * x;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;memset(parent, -1, sizeof parent);
    vector<vertex> arr(n);//원래 정점들 
    vector<edge> edges;

    for(auto &[x,y]:arr)cin >> x >> y;
    

    for(int i{};i<n;i++){
        for(int j{i+1};j<n;j++){
            auto &[xx,yy] = arr[i];
            auto &[x,y] = arr[j];
            long long dist = mypow(1LL * xx - x) + mypow(1LL * yy - y);
            edges.push_back({{i+1,j+1}, dist});// i -> y , dis
        }
    }

    int cnt{};
    for(int i{};i<m;i++){
        int u,v;cin >> u >> v;//u정점과 v정점이 서로 연결돼있다느 것이다.
        if(find(u) != find(v)){
            cnt++;
            nerge(u,v);//둘이 합치ㅣㄱ
        }
    }

    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b){
        return a.dis < b.dis;
    });

    double result{};
    for(auto &[cur, dist]: edges){
        if(cnt == n-1)break;
        auto &[u,v] = cur;
        if(find(u) != find(v)){
            nerge(u,v);
            result += sqrt(dist);
            cnt++;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result;
    return 0;
}