#include <bits/stdc++.h>
using namespace std;
const int MX = 500001;
int sa[MX];
//다음도 필요
int aux[MX];//다음 랭크를 담아놓을 곳 
int sfx[MX];
int nord[MX];
int ord[MX];
int cnt[MX];//counting sort
int rev[MX];
int lcp[MX];
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    string a;cin >> a;
    //sa를 먼저 구하고
    int n = a.size();
    for(int i=0;i<n;i++){
        sfx[i] = i;//인덱스 맵핑 해놓기
        ord[i] = a[i];//현재 i번째 값
    }
    int pnt = 1, p=1;
    while(1){
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<n;i++){
            cnt[ord[min(i+p, n)]]++;
        }
        for(int i=1;i<=n || i <= 255;i++){
            cnt[i]+=cnt[i-1];
        }
        //counting sort에서 누적합 뒤에서부터 세주기
        for(int i=n-1;i>=0;i--){
            aux[--cnt[ord[min(i+p,n)]]] = i;
        }

        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<n;i++){//앞에것 정렬
            cnt[ord[i]]++;
        }
        for(int i=1;i<=n || i<=255;i++){
            cnt[i] += cnt[i-1];
        }

        for(int i= n-1;i>=0;i--){
            sfx[--cnt[ord[aux[i]]]] = aux[i];
        }

        if(pnt == n)break;
        pnt = 1;
        nord[sfx[0]] = 1;//
        for(int i=1;i<n;i++){
            if(ord[sfx[i-1]] != ord[sfx[i]] || ord[sfx[i-1] + p]!= ord[sfx[i] + p]){
                pnt++;
            }
            nord[sfx[i]] = pnt;
        }
        memcpy(ord, nord, sizeof(int) * n);
        p*=2;
    }
    for(int i=0;i<n;i++){
        rev[sfx[i]] = i;//다 구한 것 나오고
    }
//lcp를 구한다.     
    int h= 0;
    for(int i=0;i<n;i++){
        if(rev[i]){
            int prv = sfx[rev[i] - 1];
            while(a[prv + h] == a[i + h])h++;
            lcp[rev[i]] = h;
        }
        h = max(h-1, 0);
    }

    for(int i=0;i<n;i++){
        cout << sfx[i] + 1 << ' ';
    }
    cout << '\n';
    cout << "x ";
    for(int i =1;i<n;i++){
        cout << lcp[i] << ' ';
    }
    
    return 0;
}