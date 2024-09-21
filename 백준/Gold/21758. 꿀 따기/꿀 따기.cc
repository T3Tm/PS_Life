#include <iostream>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    int prefix[n+1]{};
    for(int i=1;i<=n;i++){
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }
    int result{};
    //중간에 꿀통이 있을 경우
    for(int i=2;i<n;i++){
        int now=prefix[i]-prefix[1];
        now += prefix[n-1] - prefix[i-1];
        result = max(result, now);
    }

    //맨 왼쪽에 꿀통이 있을 때
    for(int i=2;i<n;i++){
        int now=prefix[i-1]<<1;
        now += prefix[n-1]-prefix[i];
        result=max(result, now);
    }

    //맨 오른쪽에 꿀통이 있을 때
    for(int i=2;i<n;i++){
        int now=(prefix[n]-prefix[i])<<1;
        now += prefix[i-1]-prefix[1];
        result=max(result, now);
    }

    cout << result;
    return 0;
}