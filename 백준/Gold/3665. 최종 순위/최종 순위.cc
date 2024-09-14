#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[502];
int last_year[502];
bool nxt[502][502];
int indegree[502];
//
vector<vector<int>>graph;
//자신 이전도 기록해보자
struct Grade{
    int last_year, num;
    bool operator()(const Grade& a, const Grade&b){
        return a.last_year > b.last_year;//작년도가 낮은 순서로 뽑으면 된다.
    }
};

void dfs(int cur, bool visited[], bool& flag, bool nope[]){
    if(flag)return;
    visited[cur]=1;
    nope[cur] = 1;
    for(int j = 1; j<=n;j++){
        if(!nxt[cur][j])continue;
        if(visited[j]){
            // if(this_year_max[cur] > this_year_max[j]){
            //     flag = 1;
            // }
            flag = 1;
            return;
        }
        if(nope[j])continue;
        //다음으로 가면 이 둘의 집합은 같은 것
        dfs(j, visited, flag, nope);
    }
    visited[cur]=0;
}
bool isPossible(){
    //impossible인 것이 뭐가 있을까?
    // 이번에 우위를 갖는 아이들끼리 서로 모순이 있는지 확인
    if(m == 0)return 0;
    bool nope[502]{};
    bool visited[502]{};
    for(int i=1;i<=n;i++){
        if(nope[i])continue;
        bool flag{};
        dfs(i,visited, flag, nope);
        if(flag)return 1;
    }
    return 0;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        cin >> n;
        memset(arr, 0, sizeof arr);
        memset(nxt, 0, sizeof nxt);
        memset(last_year, 0, sizeof last_year);
        memset(indegree, 0, sizeof indegree);
        
        graph.clear(); graph.resize(n+1);
        for(int i{1};i<=n;i++){
            cin >> arr[i];
            last_year[arr[i]] = i;// tmp 아이는 i등수이다.
        }
        for(int i{1};i<=n;i++){
            for(int j=i+1;j<=n;j++){
                nxt[arr[i]][arr[j]] = 1;
            }
        }


        //이번 년도에 최대 높은 등수 기입
        cin >> m;//25000개 들어올 때 매번 내 앞에 있는 것들 확인?
        for(int i=0;i<m;i++){
            int a,b;cin >> a >> b;
            int a_grade = last_year[a];
            int b_grade = last_year[b];
            //작년에 누가 차수가 더 높았는지 확인
            if(a_grade < b_grade){//a의 등수가 더 높았다
                indegree[a]++;
                graph[b].push_back(a);
                //5 2 3
                nxt[b][a] = 1;
                nxt[a][b] = 0;

            }else{//b가 더 높았다
                indegree[b]++;
                graph[a].push_back(b);
                nxt[a][b] = 1;
                nxt[b][a] = 0;
            }
        }
        //진입 차수가 같은 것이 있다면 등수를 메길 수 없다.
        if(isPossible()){//250000
            cout << "IMPOSSIBLE\n";
            continue;
        }
        priority_queue<Grade, vector<Grade>, Grade>pq;

        //차수, 작년, 숫자.
        //이번년도, 작년, 숫자.
        for(int i=1;i<=n;i++){//진입 차수
            if(!indegree[i])pq.push({last_year[i],i});
        }
        while(!pq.empty()){
            auto[last_degree, number] = pq.top();pq.pop();
            cout << number << ' ';

            for(auto &next: graph[number]){
                indegree[next]--;
                if(!indegree[next]){
                    pq.push({last_year[next], next});
                }
            }
        }
        cout << '\n';
    }
    return 0;
}