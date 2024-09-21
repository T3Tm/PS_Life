#include <bits/stdc++.h>
using namespace std;
int brother[500002];
int sister[2][500002]; // 짝수, 홀수를 나누기 0은 짝수 초, 1은 홀수초
const int INF = 0x3f3f3f3f;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    memset(brother, -1, sizeof brother);
    queue<pair<int, int>> q;
    brother[k] = 0; // 처음 동생 위치
    q.push({k, 1}); //
    while (!q.empty())
    {
        auto [cur, plus] = q.front();
        q.pop();
        int next = cur + plus;
        if (next > 500000)
            continue;
        if (brother[next] != -1)
            continue;
        brother[next] = brother[cur] + 1;
        q.push({next, plus + 1});
    }

    // 누나가 이제 움직여보자.
    // 누나는 2가지를 할 수 있음
    memset(sister, 0x3f, sizeof sister);
    q.push({n, 0});
    sister[0][n] = 0;
    int ret{0x3f3f3f3f};
    
    while (!q.empty()){ // 1, , 2, 4, 7,
        auto [cur, now] = q.front();q.pop();
        if(brother[cur]!=-1){
            if(brother[cur]&1 && brother[cur] >= sister[1][cur]){
                ret = min(ret,brother[cur]);
            }else if(!(brother[cur]&1) && brother[cur] >= sister[0][cur]) {
                ret = min(ret,brother[cur]);
            }
        }
        for(auto next:{cur+ 1, cur-1,cur*2}){
            if(next < 0 || next>500000)continue;
            if(sister[(now+1) & 1][next]!=INF)continue;
            sister[(now+1) & 1][next] = sister[now&1][cur] + 1;
            q.push({next,sister[(now+1) & 1][next]});
        }
    }
    cout << (ret == INF ? -1 : ret);
    return 0;
}