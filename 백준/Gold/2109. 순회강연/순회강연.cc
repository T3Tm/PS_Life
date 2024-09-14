#include <bits/stdc++.h>
using namespace std;


int arr[10002];
vector<pair<int,int>>pd;
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;//n개의 대학
    pd.resize(n);
    int maximum_day = 0;
    for(int i=0;i<n;i++){
        cin >> pd[i].first >> pd[i].second;
        maximum_day = max(maximum_day, pd[i].second);
    }
    //d일을 기준으로 오름차순 정렬하고
    sort(pd.begin(), pd.end(), [](const pair<int,int>& a, const pair<int,int>&b){
        if(a.second == b.second)return a.first > b.first;
        return a.second < b.second;
    });
    //d보다 크거나 같은 것들 중에서
    //20 1
    //2 1
    //10 3
    //100 2
    //8 2
    //5 20
    //50 10
    
    //현재 날
    //제일 큰 p를 구하면 된다.
    int day{maximum_day};
    int total{};
    bool use[10002]{};
    while(day > 0){
        int maxi = 0;
        int idx = -1;
        for(int j=0;j<n;j++){
            if(use[j])continue;
            auto &[p, d]= pd[j];
            if(day <= d && maxi < p){
                maxi = p;
                idx = j;
            }
        }
        if(idx!=-1){
            total+=maxi;
            use[idx] = 1;
        }
        day--;
    }
    cout << total;
    return 0;
}