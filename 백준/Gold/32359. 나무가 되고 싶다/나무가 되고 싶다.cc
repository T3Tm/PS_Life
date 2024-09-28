// #include <bits/stdc++.h>
// using namespace std;
// /*
//     Y-트리는 아래 조건을 만족하는 트리이다.

//     1. 4개 이상의 정점과 인접한 정점은 없다.
//     2. 인접한 정점의 개수가 3개인 정점은 정확히 하나이다.
//     3. 인접한 정점이 한 개인 정점은 정확히 3개
//     4. Y-트리의 크기는 해당 정점을 이루는 개수와 같다.

//     1개의 정점이 부모노드와 하위 자식노드는 2개까지 가능하다. 아니면 1번 조건에 위배됨.
//     1. 부모노드는 자식이 3개가 가능하다.
//     2. 자식노드는 부모노드를 포함해야 되므로 자식노드는 무조건 2개까지만 가능하다.
//     3. 인접한 정점이 한 개인 정점은 정확히 3개이다. << 부모 포함이면 부모는 단일 자식 아니라면 리프노드가 3개
//     4. 인접한 정점의 개수가 3개인 정점은 정확히 하나이다.
//         4-1 만약 부모의 노드가 3개의 자식노드를 갖는다면 다른 곳들은 단순하게 자식을 하나씩만 가지면 된다.
//         4-2 부모가 2개의 자식 노드를 갖는다면 모든 자식 노드중 한 곳만 2개의 자식노드를 가지면 된다.

//     트리에서 정점을 0개 이상 삭제하여 만들 수 있는 가장 큰 Y-트리의 크기를 구하여라.

//     첫째 줄에 트리의 정점 개수를 의미하는 정수 $N$이 주어진다.
//     2 <= N <= 2 * 10^5
//     1 <= u,v <= N
//     u != v
//     트리임
    
//     트리를 이루는 모든 간선은 정확히 한 번씩 주어진다.

//     출력
//     첫째 줄에 주어진 트리에서 만들 수 있는 가장 큰 Y-트리의 크기를 출력한다.

//     Y-트리를 만들 수 없다면 0을 출력한다.

//     1
//     2
//     3
// */
// int n;
// //양방향 그래프 연결해놓고
// //dfs를 통해서 트리 만들기

// vector<vector<int>>graph;
// const int ROOT = 1;

// void dfs(int cur, int parent){
//     for(auto &next: graph[cur]){
//         if(next == parent)continue;

//     }
// }

// int main(){
//     cin.tie(0) -> sync_with_stdio(0);
//     cin >> n;
//     graph.resize(n+1);
//     for(int i{};i<n-1;i++){
//         int a,b;cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     dfs(ROOT, 0);
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
const int MX = 5 * (int)1e5 + 2;
long long arr[MX];
map<long long, int>parent;//해당 정점 몇 번 방문
map<long long, long long>ccnt;//해당 정점에 방문했을 때 몇 개였는지 기입
set<long long>dont;//입력으로 들어온 아이들은 절대 나오면 안됨.
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;
    queue<pair<long long, long long>>q;//{해당 수 : 몇 개}
    long long result{-1};
    for(int i{};i<n;i++){
        cin >> arr[i];//오름차순 정렬
        long long next_parent = arr[i] >> 1LL;
        parent[next_parent]++;//갯수 하나 증가시켜주기
        if(parent[next_parent] == 2){
            if(dont.find(next_parent) == dont.end()){
                q.push({next_parent, 1});//갯수 세주기
            }else if(next_parent == 1)result = 0;
        }else if(next_parent == 0)result = 0;
        dont.insert(arr[i]);//이건 절대 나오면 안됨.
    }
    //부모 갯수 세주고 만약 해당 부모가 2개가 된다면 갯수를 세줄 수 있음.
    while(!q.empty()){
        auto [cur, cnt] = q.front();q.pop();
        if(cur == 1){
            result = cnt;
            break;
        }
        long long next = cur >> 1LL;//부모 노드 없애주기
        parent[next]++;
        ccnt[next]+= cnt;//내가 지금까지 세온 갯수 넣어놓기
        if(parent[next] == 2){//자식에서 세온 갯수 넣어놔야 함.
            if(dont.find(next) == dont.end()){
                q.push({next, ccnt[next] + 1});
            }else if(next == 1)result = 0;
        }
    }
    cout << result;
    return 0;
}