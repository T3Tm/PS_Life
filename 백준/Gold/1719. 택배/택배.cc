#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(0) ->sync_with_stdio(0);

    int n,m;cin >>n >> m;
    int A[203][203];
    int result[203][203];
    memset(A, 0x3f, sizeof A);
    memset(result, 0, sizeof result);

    for(int i{};i<m;i++){
        int u,v,cost;cin >> u >> v >> cost;
        if(A[u][v] > cost){
            A[u][v] = cost;
            A[v][u] = cost;
            result[u][v] = v;
            result[v][u] = u;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j)continue;
                if(A[i][j] > A[i][k] + A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    result[i][j] = result[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                cout << "- ";
            }else{
                cout << result[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}