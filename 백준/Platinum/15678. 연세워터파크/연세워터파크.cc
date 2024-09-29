#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e5 + 2;
const int INF = -(int)1e9 -1;
int n,d;
long long dp[MX];
int arr[MX];//각 안에 들어있는 값은 -10^9 ~ 10^9
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> d;
    fill(dp,dp+MX,INF);
    for(int i{};i<n;i++)cin >> arr[i];
    //어느 지점에서 시작을 했는지에 따라서 값이 달라질 수 있음
    priority_queue<pair<long long, int>>pq;
    /*
        i는 
        long long v = max(dp[i-d : i-1]);//이전에서 최댓값 갖고 오기
        if(v <= 0)dp[i] = arr[i];//이렇게 넣어놓기
        else dp[i] = v + arr[i];

        pq에는 [i-d : i-1]의 값을 갖고 있는다.//여기서 최댓값을 하나 갖고 나온다.
    */
    //i - d
    //
    long long result{INF};
    for(int i{};i<n;i++){//i - d
        while(!pq.empty() && pq.top().second < i - d)pq.pop();
        //0보다 작거나 같으면 솔직히 안에 있을 필요가 없음
        if(!pq.empty()){
            auto [v, idx] = pq.top();
            dp[i] = v + arr[i];
        }else{//여기서부터 시작한다.
            dp[i] = arr[i];
        }
        if(dp[i] > 0)pq.push({dp[i], i});
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}