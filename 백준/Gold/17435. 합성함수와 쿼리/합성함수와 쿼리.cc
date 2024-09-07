#include <bits/stdc++.h>
using namespace std;
int sparseTable[20][200002];
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> sparseTable[0][i];
    }

    for(int i=1;1 << i<500000;i++){
        for(int j=1;j<=n;j++){//2^i 승 뒤에 j 값은 
            sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]];
        }
    }
    
    int q;cin >> q;
    while(q--){
        int n,x;cin >>n >> x;
        for(int i = 20;i>=0;i--){
            if(n >= 1 << i){
                n -= 1<<i;
                x = sparseTable[i][x];
            }
        }
        cout << x << '\n';
    }
    return 0;
}