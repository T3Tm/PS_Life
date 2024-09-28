#include <bits/stdc++.h>
using namespace std;
const int MX = 5 * (int)1e5 + 2;
long long arr[MX];
unordered_map<long long, int>parent;//해당 정점 몇 번 방문
unordered_map<long long, long long>ccnt;//해당 정점에 방문했을 때 몇 개였는지 기입
unordered_set<long long>dont;//입력으로 들어온 아이들은 절대 나오면 안됨.
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