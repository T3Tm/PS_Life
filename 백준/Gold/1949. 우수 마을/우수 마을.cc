#include <bits/stdc++.h>
using namespace std;
const int ROOT = 1;
const int MX = 10002;

int dp[2][MX];
vector<vector<int>>tree(MX);
vector<vector<int>>graph(MX);
int arr[MX];
void dfs(int cur, int parent){
    for(auto &next: graph[cur]){
        if(next == parent)continue;
        tree[cur].push_back(next);
        dfs(next,cur);
    }
}

int village(int cur, int inout){
    if(dp[inout][cur]!=-1)return dp[inout][cur];
    dp[inout][cur] = inout * arr[cur];
    //내가 inout이 꺼져있으면 상대방은 
    //켜져있어도 되고 꺼져있어도 됨.
    //켜져있으면 다음 아이들은 무조건 꺼져있어야 함.
    for(auto &next: tree[cur]){
        if(inout){//내가 켜져있기 위해 다른 것들은 다 꺼져있어야 함.
            dp[inout][cur] += village(next, 0);
        }else{
            //next들 중에서 하나 이상만 커져있으면 됨.
            dp[inout][cur] += max(village(next,0), village(next,1));
        }
    }
    return dp[inout][cur];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    int n;cin >> n;
    for(int i{1};i<=n;i++)cin >> arr[i];

    for(int i{1};i<n;i++){
        int u,v;cin >> u >>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(ROOT, 0);

    cout << max(village(ROOT,0),village(ROOT,1));
    return 0;
}