#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, vector<int>>>graph;
int visited[200002];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,k,q;cin >> n>> m >> k >> q;
    for(int i=0;i<m;i++){
        int x,y;cin >> x>> y ;
        graph[x][y].push_back(0);
        graph[y][x].push_back(0);
    }

    struct Pair{
        int cost, cur;
        bool operator()(const Pair&a, const Pair&b){
            return a.cost > b.cost;
        }
    };
    
    priority_queue<Pair, vector<Pair>, Pair>pq;
    memset(visited, 0x3f, sizeof visited);
    for(int i=0,tmp;i<k;i++){
        cin >> tmp;pq.push({0, tmp});
        visited[tmp] = 0;
    }

    for(int i{};i<q;i++){
        int time, a,b;cin >> time >> a >> b;
        graph[a][b].push_back(time);
        graph[b][a].push_back(time);
    }

    while(!pq.empty()){
        auto [cost, cur] = pq.top();pq.pop();
        if(visited[cur] < cost)continue;

        for(auto &[key, values]:graph[cur]){
            int mark = cost;//
            auto it = lower_bound(values.begin(), values.end(), cost);
            //마지막
            if(it == values.end()){
                if(((int)values.size() & 1) == 0)continue;//끊겼음
                mark = cost + 1;//cost보다 큰 값은 없다는 것
            }else{
                //마지막은 아님.
                int idx = it - values.begin();
                if((idx & 1) == 0) mark = values[idx] + 1;
                else{
                    //이러면 가능
                    if(cost+1 <= values[idx])mark = cost+1;//가능
                    else if(idx + 1 == values.size())continue;
                    else mark = values[idx + 1] + 1;
                }
            }
            if (visited[key] > mark){
                visited[key] = mark;
                pq.push({mark, key});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i] == 0x3f3f3f3f) cout << "-1 ";
        else cout << visited[i] << ' ';
    }

    return 0;
}