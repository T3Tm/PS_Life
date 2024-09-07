#include <bits/stdc++.h>
using namespace std;
int ox[100002];
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    string a; cin >> a;
    string b; cin >> b;
    for(int i{1};i<=n;i++)ox[i] = a[i-1]==b[i-1];
    int tmp[100002];
    memcpy(tmp+1,ox+1,sizeof(int) * n);
    int result{};
    for(int i=2;i<=n;i++){
        if(!ox[i-1]){
            ox[i-1] = !ox[i-1];
            ox[i] = !ox[i];
            ox[i+1] = !ox[i+1];
            result++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!ox[i]){
            result = -1;
            break;
        }
    }
    memcpy(ox+1,tmp+1,sizeof(int)*n);
    ox[1]=!ox[1];
    ox[2]=!ox[2];
    int now{1};
    for(int i=2;i<=n;i++){
        if(!ox[i-1]){
            ox[i-1] = !ox[i-1];
            ox[i] = !ox[i];
            ox[i+1] = !ox[i+1];
            now++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!ox[i]){
            now = -1;
            break;
        }
    }
    if(result == -1 && now == -1){
        cout << -1;
    }else if(result == -1){
        cout << now;
    }else if(now == -1){
        cout << result;
    }else{
        cout << min(result, now);
    }
    return 0;
}