#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int parent[1002];
int find(int x){
    if(parent[x] < 0)return x;
    return parent[x] = find(parent[x]);
}

void nerge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(x > y)swap(x,y);
    parent[x] += parent[y];
    parent[y] = x;
}

vector<set<int>>graph;//해당 간선 색깔 입혀놓고
char color[1002][1002];
int visited[1002];
void dfs(int x,int& target, pair<int,int>& last, int& vis, bool& flag){
    visited[x] = vis;
    if(x == target){//더이상 안 가도 됨.
        flag = true;
        return;
    }
    for(auto &next : graph[x]){
        if(visited[next] == vis)continue;
        if(color[x][next] == 'B')last = {x,next};//마지막
        dfs(next, target, last,vis, flag);
        if(flag)return;
    }
}
void process(vector<pair<int,int>> r, vector<pair<int,int>> b){
    if(b.size() < k){
        cout << "0\n";
        return;
    }
    if(m < n - 1){//애초에 그래프가 될 수 없음
        cout << "0\n";
        return;
    }
    memset(parent, -1, sizeof parent);
    memset(visited, -1, sizeof visited);
    //파랑으로만 일단 연결하기
    int blue{};//파랑 연결한 갯수 세기
    for(auto &[x,y] : b){
        if(find(x) != find(y)){
            nerge(x,y);
            graph[x].insert(y);
            graph[y].insert(x);
            color[x][y] = 'B';
            color[y][x] = 'B';
            blue++;
        }
    }
    //다 연결해봤자 k개가 안됨.
    if(blue < k){
        cout << "0\n";
        return;
    }
    int red = 0;//전부 연결된 갯수 보기
    vector<pair<int,int>> remain;
    for(auto &[x,y]:r){
        if(find(x) != find(y)){
            nerge(x,y);
            red++;
            graph[x].insert(y);
            graph[y].insert(x);
            color[x][y] = 'R';
            color[y][x] = 'R';
        }else{
            remain.push_back({x,y});
        }
    }
    //그냥 다 연결했는데 이게 st를 만족시키지 않음
    if(red + blue != n-1){
        cout << "0\n";
        return;
    }
    
    if(blue == k){//k이면서 n-1개를 만족시켰음
        cout << "1\n";
        return;
    }
    //1. spanning tree를 만족시키고 있는 상태
    //2. blue 간선의 갯수인 cnt > k인 상태
    //3. 남아있는 red 간선에서 n - 1 - k개를 만족시킬 수 있는지 확인을 해보자.

    /* 남아있는 빨간 간선 */
    int vis{};
    //갯수가 이제 n-1-k개 되면 종료
    for(auto &[x,y] : remain){
        if(red == n - 1 - k)break;
        //x -> y까지 가는데 파란 간선이 있다면 체크해보자.
        //그리고 y간선을 가는데 
        bool is_end = false;
        pair<int,int>tmp{-1,-1};
        dfs(x,y, tmp,vis,is_end);//x -> y가는데 blue 마지막 간선 갖고 오기
        if(tmp.first != -1){//마지막 간선 삭제하고 x,y를 연결해보자.
            graph[tmp.first].erase(tmp.second);
            graph[tmp.second].erase(tmp.first);
            graph[x].insert(y);
            graph[y].insert(x);
            red++;
        }
        vis++;
    }

    if(red == n - 1 - k){
        cout << "1\n";
        return;
    }else{
        cout << "0\n";
        return;
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    while(cin >> n >> m >> k){
        if(!n)break;
        graph.clear();graph.resize(n+1);
        vector<pair<int,int>>blue;
        vector<pair<int,int>>red;
        for(int i{};i<m;i++){
            char c;int f,t;cin >> c >> f >> t;
            if(c=='R')red.push_back({f,t});
            else blue.push_back({f,t});
        }
        process(red,blue);
    }
    return 0;
}