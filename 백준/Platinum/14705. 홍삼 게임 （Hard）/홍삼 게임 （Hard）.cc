#include <bits/stdc++.h>
using namespace std;
const int MX = 500002;
const int INF = 0x3f3f3f3f;
int dpa[2][MX];//a가 [0 : N-1]를 홀수, 짝수번째에 밟는데 최소 지목 수
int dpb[2][MX];//b가 [0 : N-1]를 홀수, 짝수번째에 밟는데 최소 지목 수
void simulation(int dp[][MX], int& interval,int start, int n){
    //어느 지점부터 시작하여서 가는지
    memset(dp, -1, (sizeof(int)*MX) * 2);
    dp[0][start] = 0 ;//시작 지점은 0번
    //시작 지점으로 부터 +- interval 로 움직인다.
    //그리고 dp가 방문된 적이 있으면 그만 멈춘다.

    queue<pair<int, bool>>q;
    q.push({start, 0});//현재 지목 횟수를 알아야 된다.
    while(!q.empty()){
        auto[cur, cur_point] = q.front();q.pop();
        for(auto next : {(cur + interval)%n, (cur-interval + n)%n}){
            bool next_point = cur_point ? 0 : 1;
            if(dp[next_point][next] != -1)continue;//이미 간 적이 있으므로 굳이 갈 이유가 없음
            dp[next_point][next] = dp[cur_point][cur] + 1;//한 번 더 지목하여 갈 수 있음.
            q.push({next, next_point});
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,a,b,da,db;cin >> n >> a >> b >> da >> db;
    //그냥 0 ~ n-1로 돌리는 것이 편할 거 같은데
    a--;
    b--;//한 개씩 줄인다.
    simulation(dpa, da,a,n);
    simulation(dpb, db,b,n);

    //각각 시뮬레이션 돌린 결과에서 이제 그럼 처음 시작
    int result{INF};//끝나기는 하는 거지..?
    for(int i=0;i<n;i++){
        //A -> B 
        if(dpa[0][i] != -1){//짝수 번만에 갈 수 있음 2번
            if(dpb[1][i] != -1){//A가 짝수, B가 홀수
                result = min(result, (max(dpa[0][i], dpb[1][i]) << 1) + (dpa[0][i] > dpb[1][i] ? -1 : 1));
            }
        }
        if(dpa[1][i] != -1){
            if(dpb[0][i] != -1){//A가 홀수, B가 짝수
                result = min(result, (max(dpa[1][i], dpb[0][i]) << 1) + (dpa[1][i] > dpb[0][i] ? -1 : 1));
            }
        }

        //B -> A
        if(dpb[0][i] != -1){
            if(dpa[0][i] != -1){//B가 짝수, A가 짝수
                result = min(result, max(dpa[0][i], dpb[0][i])<<1);
            }
        }
        
        if(dpb[1][i] != -1){
            if(dpa[1][i] != -1){
                result = min(result, max(dpa[1][i], dpb[1][i])<<1);
            }
        }
    }
    if(result == INF){
        cout << "Evil Galazy";
    }else{
        cout << result;
    }
    return 0;
}