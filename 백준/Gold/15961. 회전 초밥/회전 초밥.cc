#include <bits/stdc++.h>
using namespace std;
int arr[3004000]{};
int ate[3002]{};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,d,k,c;cin >> n >> d >> k >> c;
    int result{};
    int now{};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<k-1;i++){
        arr[n+i] = arr[i];
    }

    for(int i{};i<k;i++){//미리 k를 먹는다.
        if(!ate[arr[i]]){//안 먹었던 음식이 들어옴
            now++;
        }
        ate[arr[i]]++;
        result = max(result,now + !ate[c]);
    }

    for(int i=k,tmp;i<n + k - 1;i++){
        ate[arr[i-k]]--;//이전 개수 없애주기
        if(!ate[arr[i-k]])now--;

        if(!ate[arr[i]]){//안 먹었던 음식이 들어옴
            now++;
        }
        ate[arr[i]]++;
        result = max(result, now + !ate[c]);
    }

    cout << result;
    return 0;
}