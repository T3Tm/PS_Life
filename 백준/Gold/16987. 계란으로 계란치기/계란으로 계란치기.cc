#include <bits/stdc++.h>
using namespace std;

/*
    1. 가장 왼쪽 계란을 든다.
    2. 하나의 계란을 친다.
*/
int n;
int weight[9];
int strength[9];
int result{};
void bact(int depth){
    if(depth == n){
        int cnt{};
        for(int i=0;i<n;i++){
            cnt += strength[i] <= 0;
        }
        result = max(result, cnt);
        return;
    }
    if(strength[depth] < 0){
        bact(depth + 1);
        return;
    }
    bool flag{1};
    for(int i=0; i < n;i++){
        if(strength[i] <= 0)continue;
        if(depth == i)continue;
        strength[depth] -= weight[i];
        strength[i] -= weight[depth];
        flag = 0;
        bact(depth + 1);
        strength[i] += weight[depth];
        strength[depth] += weight[i];
    }
    if(flag)bact(depth + 1);
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> strength[i] >> weight[i];
    }
    bact(0);
    cout << result;
    return 0;
}